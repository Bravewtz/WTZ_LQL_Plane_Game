#pragma once
#include "stdafx.h"
#include "BossBall2.h"
#include "resource.h"
#include "EBall1Move.h"
#include "EMove.h"
CImageList CBossBall2::m_Images;


CBossBall2::CBossBall2(int x, int y) :CEBall(x, y, 1, BOSSBALL2_WIDTH, BOSSBALL2_HEIGHT)
{
	move = new CEBall1Move;
	move->init();
}

CBossBall2::CBossBall2()
{
	move = new CEBall1Move;
	move->init();
}

CBossBall2::~CBossBall2(void)
{
	delete move;
}

BOOL CBossBall2::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBall::Draw(pDC, bPause);
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}

BOOL CBossBall2::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP16, RGB(255, 255, 255), 43, 43, 1);
}
