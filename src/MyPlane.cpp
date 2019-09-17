#pragma once
#include "stdafx.h"
#include "MyPlane.h"
#include "Plane.h"
#include "Resource.h"
CImageList CMyPlane::m_Images;
CImageList CMyPlane::m_ImagesDF;

CMyPlane::CMyPlane():CPlane(0,0,10, MYPLANE_WIDTH, MYPLANE_HEIGHT){
	m_Wait = 0;
	m_ptPos.x = GAME_WIDTH * 1 / 2 - MYPLANE_WIDTH / 2;
	m_ptPos.y = GAME_HEIGHT * 2 / 3 - MYPLANE_HEIGHT / 2;
	bar = new CBloodBar(MYPLANE_WIDTH,MYPLANE_HEIGHT);
	God = 0;
}

CMyPlane::~CMyPlane(){}
BOOL CMyPlane::LoadImage()
{
	CGameObject::LoadImage(m_ImagesDF, IDB_BITMAP17, RGB(0, 0, 0), 90, 90, 1);//我的护盾图形
	return CGameObject::LoadImage(m_Images, IDB_BITMAP6, RGB(0, 0, 0), MYPLANE_WIDTH, MYPLANE_HEIGHT, 5); //我的飞机图形
}
/*
BOOL CMyPlane::LoadImage2()
{
	return CGameObject::LoadImage2(m_ImagesDF, IDB_BITMAP17, RGB(0, 0, 0), 90, 90, 1);//我的护盾图形
}
*/
BOOL CMyPlane::Draw(CDC* pDC, BOOL bPause)
{
	update();
	if (!bPause) {
		m_ptPos.x = m_ptPos.x + V_x * 8;
		m_ptPos.y = m_ptPos.y + V_y * 8;	
	}
	if (m_ptPos.x >= GAME_WIDTH - MYPLANE_WIDTH)
		m_ptPos.x = GAME_WIDTH - MYPLANE_WIDTH;
	if (m_ptPos.x <= 0)
		m_ptPos.x = 0;
	if (m_ptPos.y <= 0)
		m_ptPos.y = 0;
	if (m_ptPos.y >= GAME_HEIGHT - MYPLANE_HEIGHT)
		m_ptPos.y = GAME_HEIGHT - MYPLANE_HEIGHT;
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if (God)
	{
		m_ImagesDF.Draw(pDC, 0, CPoint(m_ptPos.x-21 , m_ptPos.y-10 ), ILD_TRANSPARENT);
	}
	bar->DrawBloodBar(pDC, HP, m_ptPos,RGB(255,0,0));
	return TRUE;
}
