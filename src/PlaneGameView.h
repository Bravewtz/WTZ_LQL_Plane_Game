
// PlaneGameView.h: CPlaneGameView 类的接口
//

#pragma once
#include "Pass.h"
#include "Plane.h"
#include "MyPlane.h"
#include "MyMove.h"
#include "Ball.h"
#include "MyBall.h"
#include "MyBall1.h"
#include "Ball1.h"
#include "EPlane.h"
#include "Explosion.h"
#include "Explosion_1.h"
#include "JudgeCollision.h"
#include "EBall.h"
#include "EBall1.h"
#include "Boss1.h"
#include "Boss.h"
#include "BossBall1.h"
#include "WingPlane.h"
#include "BossBall2.h"
#include "Boss2.h"
#include "BossBall3.h"

class CPlaneGameView : public CView
{

protected: // 仅从序列化创建
	CPlaneGameView() noexcept;
	DECLARE_DYNCREATE(CPlaneGameView)

// 特性
public:
	CPlaneGameDoc* GetDocument() const;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPlaneGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	int count ;
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	CDC*        m_pMemDC;		//内存DC
	CClientDC*  m_pDC;		//设备DC
	CBitmap*    m_pMemBitmap;		//内存位图
public:
	//初始化游戏
	BOOL InitGame();
	//结束游戏
	void StopGame();
	//刷新游戏的帧画面
	void AI();
	void UpdateFrame(CDC* pMemDC);

	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000) ? 1 : 0;
	}
	CMyPlane*  m_pMe;
	CObList    m_ObjList[5];
	CMyBall myball;
	CEPlane eplane;
	CExplosion explosion;
	CJudgeCollision judge;
	CPass* Pass;
	CMyMove MyMove;
	CEBall eball;
	CBoss* boss;
};
#ifndef _DEBUG  // PlaneGameView.cpp 中的调试版本
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

