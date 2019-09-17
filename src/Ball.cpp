#pragma once
#include "StdAfx.h"
#include "Ball.h"
#include "resource.h"

CBall::CBall(int x, int y, int atk,int W,int H) :CGameObject(x, y),attack(atk),Ball_Width(W),Ball_Height(H)
{
}
BOOL CBall::Draw(CDC* pDC, BOOL bPause) //»æÖÆ¶ÔÏó
{
	if (!bPause)
	{
		move->update();
		m_ptPos.y = m_ptPos.y + move->GetVy();
		m_ptPos.x = m_ptPos.x + move->GetVx();
	}
	if (m_ptPos.y > GAME_HEIGHT + Ball_Height)return FALSE;
	if (m_ptPos.y < -Ball_Height)return FALSE;
	if (m_ptPos.x > GAME_WIDTH + Ball_Width)return FALSE;
	if (m_ptPos.x < -Ball_Width)return FALSE;
	return TRUE;
}
void CBall::SetMoveL(){}
void CBall::SetMoveR(){}

CBall::CBall(){}
CBall::~CBall(void){}
void CBall::SetList(CObList* List) { m_ObjList = List; }
void CBall::SetMy(CMyPlane* ME) { me = ME; }
void CBall::Show(CDC* pMemDC) {}