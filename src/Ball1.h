#pragma once
#include "gameobject.h"
#include "Move.h"
#include "EMove.h"
#include "MyBall1Move.h"
#include "Ball.h"
#include "MyBall.h"
class CBomb :public CMyBall
{
public:
	CBomb(int x, int y);
	~CBomb(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 10, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 20;
	static CImageList m_Images;
};
