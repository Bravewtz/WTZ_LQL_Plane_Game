#pragma once
#include "Explosion.h"
#include "GameObject.h"
class CExplosion_1:public CExplosion{
public:
	CExplosion_1(int x, int y, int limit = 18);
	~CExplosion_1();
	static const int  EXPLOSION_WIDTH = 66;
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + EXPLOSION_WIDTH, m_ptPos.y + EXPLOSION_WIDTH));
	}
private:
	static CImageList m_Images;
};