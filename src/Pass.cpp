#include "stdafx.h"
#include "Pass.h"
#include "Resource.h"
#include "EPlane1.h"
#include "EPlane2.h"
#include "Boss.h"
#include "Boss1.h"
#include "Boss2.h"
#include "Boss3.h"
CPass::CPass() { init(); }
CPass::~CPass() {}
CPass::CPass(int socre) :NowScore(socre) { init(); }


void CPass::init() {
	NowScore = 0;
	NowPass = 0;
	have_pass = 3;
	PassScore[0] = 60;
	PassScore[1] = 120;
	PassScore[2] = 180;
	InBoss = 0;
	boss = NULL;
	for (int i = 0; i < 4; i++)has_Boss[i] = 0;
}


int CPass::GetPass() {
	for (int i = 2; i >= 0; i--)if (NowScore >= PassScore[i]) {
		return i+1;
	}
	return 0;
}


void CPass::MakeBoss()
{
	if (!InBoss) {
		if (NowPass>0&&!has_Boss[NowPass - 1]) {
			if(NowPass==1)boss = new CBoss1;
			else if(NowPass==2)boss = new CBoss2;
			else boss = new CBoss3;
			InBoss = 1;
			has_Boss[NowPass - 1] = 1;
		}
		
	}
}


void CPass::ShowWing(CDC* pMemDC)
{
	POSITION pos1, pos2;
	for (pos1 = m_ObjList[4].GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CWingPlane* pObj = (CWingPlane*)m_ObjList[4].GetNext(pos1);
		if (!pObj->Draw(pMemDC, FALSE))
		{
			m_ObjList[4].RemoveAt(pos2);
			delete pObj;
		}
		pObj->DoFired(m_ObjList);
	}
}


void CPass::Work(CDC* pMemDC) {
	DrawBack(pMemDC, NowPass);
	CEPlane1::Mupdate();
	CEPlane2::Mupdate();
	MakeEPlane();
	NowPass = GetPass();
	MakeBoss();
	EPlaneFire();

	CString str;
	str.Format(_T("Score: %d"), NowScore);
	pMemDC->SetBkMode(TRANSPARENT);
	pMemDC->SetTextAlign(TA_CENTER);
	pMemDC->SetTextColor(RGB(255, 0, 255));
	pMemDC->TextOut(5 + 40, 5, str);

}


void CPass::EPlaneFire() 
{
	POSITION P1 = NULL, P2 = NULL;
	for (P1 = m_ObjList[1].GetHeadPosition(); (P2 = P1) != NULL;)
	{
		CEPlane* Ep = (CEPlane*)m_ObjList[1].GetNext(P1);
		if (Ep->Fired()) {
			Ep->DoFired(m_ObjList);
		}
	}
	if(InBoss)
	{
		//if (boss->Fired()) {
			boss->DoFired(m_ObjList);
		//}
	}
}

void CPass::MakeEPlane() {
	//if(NowPass==0){
		if (CEPlane1::Isappear()) {
			m_ObjList[1].AddTail(new CEPlane1);
		}
		if (CEPlane2::Isappear()) {
			m_ObjList[1].AddTail(new CEPlane2);
		}
	//}
}

void CPass::DrawBack(CDC* pMemDC,int num) {
	const int BackGroundSpeed = 2;
	//»æÖÆÌì¿Õ
	static int imagelocation = 0;
	CDC memDC;
	memDC.CreateCompatibleDC(pMemDC);
	CBitmap bmpDraw;
	if(num==0)bmpDraw.LoadBitmapW(IDB_BITMAP1);
	if(num==1)bmpDraw.LoadBitmapW(IDB_BITMAP2);
	if(num==2)bmpDraw.LoadBitmapW(IDB_BITMAP3);
	if(num==3)bmpDraw.LoadBitmapW(IDB_BITMAP4);

	CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
	pMemDC->BitBlt(0, imagelocation, GAME_WIDTH, GAME_HEIGHT, &memDC, 0, 0, SRCCOPY);
	pMemDC->BitBlt(0, 0, GAME_WIDTH, imagelocation, &memDC, 0, GAME_HEIGHT - imagelocation, SRCCOPY);
	imagelocation += BackGroundSpeed;
	if (imagelocation == GAME_HEIGHT)
		imagelocation = 0; 
}
