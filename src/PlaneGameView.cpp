
// PlaneGameView.cpp: CPlaneGameView 类的实现
//

#include "stdafx.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PlaneGame.h"
#endif

#include "PlaneGameDoc.h"
#include "PlaneGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneGameView

IMPLEMENT_DYNCREATE(CPlaneGameView, CView)

BEGIN_MESSAGE_MAP(CPlaneGameView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CPlaneGameView 构造/析构

CPlaneGameView::CPlaneGameView() noexcept
{
	// TODO: 在此处添加构造代码
}
CPlaneGameView::~CPlaneGameView()
{
}
BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}
// CPlaneGameView 绘图
void CPlaneGameView::OnDraw(CDC* /*pDC*/)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CPlaneGameView 打印

BOOL CPlaneGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPlaneGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPlaneGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPlaneGameView 诊断

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView 消息处理程序


void CPlaneGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	InitGame();
	// TODO: 在此添加专用代码和/或调用基类
}




void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateFrame(m_pMemDC);
	AI();
	CView::OnTimer(nIDEvent);
}
BOOL CPlaneGameView::InitGame()
{
	//初始化的乱七八糟
	CRect rc;
	GetClientRect(rc);
	srand((unsigned)time(NULL));		//产生随机数种子
	m_pDC = new CClientDC(this);		//建立设备DC
	m_pMemDC = new CDC;
	m_pMemDC->CreateCompatibleDC(m_pDC);	//建立内存DC
	m_pMemBitmap = new CBitmap;
	m_pMemBitmap->CreateCompatibleBitmap(m_pDC, GAME_WIDTH, GAME_HEIGHT); //建立内存位图

	m_pMemDC->SelectObject(m_pMemBitmap);	//将位图选入内存DC

	//加载各种图片

	CMyPlane::LoadImage();
	CMyBall1::LoadImage();
	CBomb::LoadImage();
	CEPlane::LoadImageUp();
	CEPlane::LoadImageDown();
	CExplosion_1::LoadImage();
	CEBall1::LoadImage();
	CBoss::LoadImage();
	CBossBall1::LoadImage();
	CWingPlane::LoadImage();
	CBossBall2::LoadImage();
	CBossBall3::LoadImage();
	//CBoss2::LoadImage();

	AfxMessageBox(_T("操作说明：\n WASD控制移动。\n J键：发射子弹。\n I键：召唤僚机。\n P键：开启无敌模式"));

	//*************
	m_pMe = new CMyPlane;		//产生主角(战机)
	m_pMe->Setlimit(5);
	MyMove.SetMe(m_pMe);
	MyMove.SetList(m_ObjList);
	myball.SetList(m_ObjList);
	eplane.SetList(m_ObjList);
	explosion.SetList(m_ObjList);

	judge.SetList(m_ObjList);
	judge.SetMe(m_pMe);
	Pass = new CPass();
	Pass->SetList(m_ObjList);
	Pass->init();
	judge.SetPass(Pass);
	eball.SetList(m_ObjList);
	eball.SetMy(m_pMe);
	SetTimer(1, 30, NULL);		//启动游戏
	return TRUE;
}

void CPlaneGameView::StopGame()
{
	delete m_pMe;
	delete m_pMemDC;
	delete m_pDC;
	delete m_pMemBitmap;
}
void CPlaneGameView::UpdateFrame(CDC* pMemDC) {

	CDC m_MemDc;
	CDC m_cacheDC;
	CBitmap m_cacheCBitmap;
	//BITMAP m_Bmplnfo;
	CDC *pDc = GetDC();

	CRect m_CliRect;
	GetClientRect(&m_CliRect);

	//创建缓冲窗口大小（解决刷新闪屏问题）
	m_cacheDC.CreateCompatibleDC(NULL);
	m_cacheCBitmap.CreateCompatibleBitmap(pDc, m_CliRect.Width(), m_CliRect.Height());
	m_cacheDC.SelectObject(&m_cacheCBitmap);
	count++;
	pMemDC->BitBlt(0, 0, m_CliRect.Width(), m_CliRect.Height(), &m_MemDc, 0, 0, SRCCOPY);
	pMemDC->BitBlt(0, 0, m_CliRect.Width(), count, &m_MemDc, 0, m_CliRect.Height() - count, SRCCOPY);
	pMemDC->BitBlt(0, count, m_CliRect.Width(), m_CliRect.Height() - count, &m_MemDc, 0, 0, SRCCOPY);
	if (count >= m_CliRect.Height())
		count = 0;

	//在绘制完图后，使得窗口有效
	ValidateRect(&m_CliRect);
	//释放缓冲DC
	m_cacheDC.DeleteDC();
	//释放对象
	m_cacheCBitmap.DeleteObject();
	//释放窗口DC
	ReleaseDC(pDc);



	Pass->Work(pMemDC);
	if (m_pMe != NULL)
	{
		m_pMe->Draw(pMemDC, FALSE);
	}
	else {
		CString str = _T("GAME OVER!");
		pMemDC->TextOut(GAME_HEIGHT / 2, GAME_HEIGHT / 2, str);
	}
	if (Pass->InBoss)Pass->boss->Draw(pMemDC,false);

	myball.Show(pMemDC);
	eplane.Show(pMemDC);
	explosion.Show(pMemDC);
	eball.Show(pMemDC);
	Pass->ShowWing(pMemDC);

	if (m_pMe != NULL && m_pMe->wait > 0) m_pMe->wait--;

	//复制内存DC到设备DC
	m_pDC->BitBlt(0, 0, GAME_WIDTH, GAME_HEIGHT, m_pMemDC, 0, 0, SRCCOPY);
}

void CPlaneGameView::AI() {

	if (m_pMe == NULL)return;
	MyMove.JudgeMoveKey();
	MyMove.JudgeFire();
	if (m_pMe->wait == 0) {
		MyMove.JudgeGod();
	}
	MyMove.CallWing();
	MyMove.update_Wing();

	judge.MyBallAttack();
	if (judge.DPlaneTouch()||judge.EPlaneAttack()) {
		m_pMe = NULL;
	//	ExitProcess(0);
	//	exit(0);
		return;
	}
}
