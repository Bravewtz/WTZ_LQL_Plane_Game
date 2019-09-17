#include "StdAfx.h"
#include "Ball1.h"
#include "resource.h"
CImageList CBomb::m_Images;
CBomb::CBomb(int x, int y) :CMyBall(x, y,-1)
{
	move = new CMyBall1Move;
	move->init();
}

CBomb::~CBomb(void)
{
	delete move;
}

BOOL CBomb::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BITMAP8, RGB(0, 0, 0), 10, 20, 1);
}

BOOL CBomb::Draw(CDC* pDC, BOOL bPause)
{
	if (!bPause)
	{
		move->update();
		m_ptPos.y = m_ptPos.y + move->GetVy();
	}
	if (m_ptPos.y < -BOMB_HEIGHT)
		return FALSE;
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	return TRUE;
}