#pragma once
#include "stdafx.h"
#include "BossBall3.h"
#include "resource.h"
#include "EBall1Move.h"
#include "EMove.h"
#include "FollowMove.h"
CImageList CBossBall3::m_Images;


CBossBall3::CBossBall3(int x, int y) :CEBall(x, y, 1, BOSSBALL3_WIDTH, BOSSBALL3_HEIGHT)
{
	move = new CFollowMove(CPoint(x,y));
	move->init();
}

CBossBall3::CBossBall3()
{
	move = new CFollowMove;
	move->init();
}

CBossBall3::~CBossBall3(void)
{
	delete move;
}

BOOL CBossBall3::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBall::Draw(pDC, bPause);
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if (flg)
		return TRUE;
	else return FALSE;
}

BOOL CBossBall3::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP14, RGB(255, 255, 255), 65, 65, 1);
}
