#include "StdAfx.h"
#include "MyBall1.h"
#include "resource.h"
#include "MyBall1Move.h"
#include "EMove.h"
#include "MyBallLeftMove.h"
#include "MyBallRightMove.h"
CImageList CMyBall1::m_Images;

CMyBall1::CMyBall1(int x, int y,int z) :CMyBall(x, y, z,10,20)
{
	move = new CMyBall1Move;
	move->init();	
}
void CMyBall1::SetMoveL()
{
	move = new CMyBallLeftMove;
	move -> init();
}
void CMyBall1::SetMoveR()
{
	move = new CMyBallRightMove;
	move->init();
}

CMyBall1::CMyBall1()
{
	delete move;
}
CMyBall1::~CMyBall1(void)
{
	delete move;
}

BOOL CMyBall1::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBall::Draw(pDC, 0);
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}

BOOL CMyBall1::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP8, RGB(0, 0, 0), 10, 20, 1);
}
