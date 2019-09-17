#pragma once
#include "stdafx.h"
#include "BossBall1.h"
#include "resource.h"
#include "EBall1Move.h"
//#include "BossBall1Move.h"
#include "EMove.h"
CImageList CBossBall1::m_Images;


CBossBall1::CBossBall1(int x, int y) :CEBall(x, y, 1, BOSSBALL1_WIDTH, BOSSBALL1_HEIGHT)
{
	move = new CEBall1Move;
	move->init();
}

CBossBall1::CBossBall1()
{
	move = new CEBall1Move;
	move->init();
}

CBossBall1::~CBossBall1(void)
{
	delete move;
}

BOOL CBossBall1::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBall::Draw(pDC, bPause);
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}

BOOL CBossBall1::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP14, RGB(255, 255, 255), 65, 65, 1);
}
