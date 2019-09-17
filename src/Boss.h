#pragma once
#include "Plane.h"
#include "EMove.h"
#include "GameObject.h"
class CBoss:public CPlane
{
public:
	CBoss(int x = 0, int y = 0, int HP = 0, int Width = BOSSWIDTH, int Height = BOSSHEIGHT);
	~CBoss();
	CEMove* move;
	virtual BOOL Draw(CDC* pDC, BOOL bPause);
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSWIDTH, m_ptPos.y + BOSSHEIGHT));
	}
	virtual void DoFired(CObList* List);
	static BOOL LoadImage();
	static CImageList m_Images;
protected:
	static const int BOSSWIDTH = 300;
	static const int BOSSHEIGHT = 200;
};