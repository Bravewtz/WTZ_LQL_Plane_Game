#pragma once
#include "stdafx.h"
#include "Move.h"
#include "MyMove.h"
#include "Plane.h"
#include "MyPlane.h"
#include "MyBall1.h"
#include "Ball1.h"
#include "MyBallLeftMove.h"
#include "MyBallRightMove.h"
CMyMove::CMyMove(){

	int Wing_wait = 0;
}
void CMyMove::update_Wing()
{
	if (Wing_wait)Wing_wait--;

}
bool CMyMove::AppearWing()
{
	if (Wing_wait <= 0) { 
		Wing_wait = 10;
		return true; 
	}
	return false;
}

CMyMove::~CMyMove(void){}
void CMyMove::SetMe(CMyPlane *Me) { m_pMe = Me; }
void CMyMove::SetList(CObList* ObjList) { m_ObjList = ObjList; }

int CMyMove::JudgeMoveKey()
{
	int nMeMotion;
	for (int i = 0; i < 4; i++)
	{
		
		m_pMe->SetVx(0);
		m_pMe->SetVy(0);

		nMeMotion = GetKey(0x57);//W
		if (nMeMotion == 1)
			m_pMe->SetVy(-1);

		nMeMotion = GetKey(0x53);//S
		if (nMeMotion == 1)
			m_pMe->SetVy(1);

		nMeMotion = GetKey(0x44);//D
		if (nMeMotion == 1)
			m_pMe->SetVx(1);

		nMeMotion = GetKey(0x41);//A
		if (nMeMotion == 1)
			m_pMe->SetVx(-1);
		
	}
	return TRUE;
}


int CMyMove::JudgeFire()
{
	if (GetKey(0x4A) == 1&&m_pMe->Fired())//°´ÏÂÁËJ¼ü
	{
		if (m_pMe != NULL)
		{
			CPoint pt = m_pMe->GetPoint();
		
			m_ObjList[0].AddTail(new CMyBall1(pt.x + 20, pt.y + 10));
			CMyBall * ball1 = new CMyBall1(pt.x+10,pt.y+10);
			ball1->SetMoveL();
			m_ObjList[0].AddTail(ball1);
			CMyBall * ball2 = new CMyBall1(pt.x + 30, pt.y + 10);
			ball2->SetMoveR();
			m_ObjList[0].AddTail(ball2);
		}
	}
	return TRUE;
}

int CMyMove::CallWing()
{
	if (GetKey(0X49)==1&&AppearWing())//I
	{
		m_ObjList[4].AddTail(new CWingPlane(GAME_WIDTH/4,GAME_HEIGHT));
		m_ObjList[4].AddTail(new CWingPlane(GAME_WIDTH-GAME_WIDTH/4-50,GAME_HEIGHT));
	}
	return true;
}

//P
int CMyMove::JudgeGod()
{
	if (GetKey(0x50) == 1)
	{
		m_pMe->wait = 5;
		m_pMe->SetGod();
		
	}
	return TRUE;
}

