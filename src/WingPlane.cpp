#pragma once
#include "stdafx.h"
#include "WingPlane.h"
#include "MyBall1.h"
#include "EMove.h"
#include "WingPlaneMove.h"
#include "resource.h"
#include "GameObject.h"
CImageList CWingPlane::m_Images;
CWingPlane::CWingPlane(int x, int y) : CPlane(x, y)
{
	PlaneWidth = 80;
	PlaneHeight = 60;
	m_Wait = 0;
	m_limit = 20;
	move = new CWingPlaneMove;
	move->init();
}
CWingPlane::CWingPlane()
{
	PlaneWidth=80; 
	PlaneHeight=60;
	m_Wait = 0;
	m_limit = 5;
	move = new CWingPlaneMove;
	move->init();
}

CWingPlane::~CWingPlane(){}
void CWingPlane::DoFired(CObList* List)
{
	//m_ptPos
	if (Fired()) {
		List[0].AddTail(new CMyBall1(m_ptPos.x + 20, m_ptPos.y + 10));
		CMyBall * ball1 = new CMyBall1(m_ptPos.x + 10, m_ptPos.y + 10);
		ball1->SetMoveL();
		List[0].AddTail(ball1);
		CMyBall * ball2 = new CMyBall1(m_ptPos.x + 30, m_ptPos.y + 10);
		ball2->SetMoveR();
		List[0].AddTail(ball2);
	}
}
BOOL CWingPlane::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		update();
		move->update();
		m_ptPos.y = m_ptPos.y + move->GetVy();
		m_ptPos.x = m_ptPos.x + move->GetVx();
	}
	if (m_ptPos.y > GAME_HEIGHT + PlaneHeight)return FALSE;
	if (m_ptPos.y < -PlaneHeight)return FALSE;
	if (m_ptPos.x > GAME_WIDTH + PlaneWidth)return FALSE;
	if (m_ptPos.y < -PlaneWidth)return FALSE;
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}

BOOL CWingPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP15, RGB(0, 0, 0), 80, 60, 4);
}
