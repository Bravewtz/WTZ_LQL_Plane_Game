#pragma once
#include "stdafx.h"
#include "EBall1.h"
#include "resource.h"
#include "EBall1Move.h"
#include "EMove.h"

CImageList CEBall1::m_Images;

CEBall1::CEBall1(int x, int y) :CEBall(x, y, 1,EBALL1_WIDTH,EBALL1_HEIGHT)
{
	move = new CEBall1Move;
	move->init();
}

CEBall1::CEBall1()
{
	move = new CEBall1Move;
	move->init();
}

CEBall1::~CEBall1(void)
{
	delete move;
}

BOOL CEBall1::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBall::Draw(pDC, bPause);
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}

BOOL CEBall1::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP12, RGB(0, 0, 0), 8, 8, 1);
}
