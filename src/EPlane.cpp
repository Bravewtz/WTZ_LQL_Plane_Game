#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "EPlane.h"
#include "resource.h"
#include "EPlane1.h"
CImageList CEPlane::m_ImagesUp;
CImageList CEPlane::m_ImagesDown;
CEPlane::CEPlane(int x, int y, int z,int h,int W,int H):CPlane(x,y,h,W,H),attack(z){}
CEPlane::~CEPlane(){}
//CEPlane::CEPlane(){}
void CEPlane::Show(CDC* pMemDC)
{
	POSITION pos1, pos2;
	for (pos1 = m_ObjList[1].GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CGameObject* pObj = (CGameObject*)m_ObjList[1].GetNext(pos1);
		if (!pObj->Draw(pMemDC, FALSE))
		{
			m_ObjList[1].RemoveAt(pos2);
			delete pObj;
		}
	}
}
BOOL CEPlane::LoadImageUp()
{
	return CGameObject::LoadImage(m_ImagesUp, IDB_BITMAP10, RGB(0, 0, 0), 100, 60, 5);
}
BOOL CEPlane::LoadImageDown()
{
	return CGameObject::LoadImage(m_ImagesDown, IDB_BITMAP11, RGB(0, 0, 0), 100, 60, 5);
}	
void CEPlane::DoFired(CObList* List)
{
}
BOOL CEPlane::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		update();
		move->update();
		m_ptPos.y = m_ptPos.y + move->GetVy();
		m_ptPos.x = m_ptPos.x + move->GetVx();
	}
	if (m_ptPos.y > GAME_HEIGHT + ENEMY_HEIGHT)return FALSE;
	if (m_ptPos.y < -ENEMY_HEIGHT)return FALSE;
	if (m_ptPos.x > GAME_WIDTH + ENEMY_WIDTH)return FALSE;
	if (m_ptPos.y < -ENEMY_WIDTH)return FALSE;
	//m_ImagesDown.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}
