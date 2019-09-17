#pragma once
#include "stdafx.h"
#include "Boss.h"
#include "resource.h"

CImageList CBoss::m_Images;

CBoss::CBoss(int x, int y, int HP, int Width, int Height):CPlane(x,y,HP,Width,Height)
{
	bar = new CBloodBar;
}

CBoss::~CBoss(){}

BOOL CBoss::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP13, RGB(0, 0, 0), 300, 200, 5);
}
void CBoss::DoFired(CObList* List)
{
}

BOOL CBoss::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		update();
		move->update();
		m_ptPos.y = m_ptPos.y + move->GetVy();
		m_ptPos.x = m_ptPos.x + move->GetVx();
	}
	if (m_ptPos.y > GAME_HEIGHT + BOSSHEIGHT)return FALSE;
	if (m_ptPos.y < -BOSSHEIGHT)return FALSE;
	if (m_ptPos.x > GAME_WIDTH + BOSSWIDTH)return FALSE;
	if (m_ptPos.y < -BOSSWIDTH)return FALSE;
	bar->DrawBloodBar(pDC, HP, m_ptPos, RGB(255, 0, 0));
	return TRUE;
}
