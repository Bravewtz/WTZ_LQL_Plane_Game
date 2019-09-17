#pragma once
#include "Plane.h"
#include "MyBall.h"
#include "EMove.h"

class CWingPlane :public CPlane
{
public:

	CWingPlane();
	CWingPlane(int x, int y);
	~CWingPlane();
	CEMove* move;
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + PlaneWidth, m_ptPos.y + PlaneHeight));
	}
	void DoFired(CObList* List);
	BOOL Draw(CDC* pDC, BOOL bPause);

	static CImageList m_Images;
	static BOOL LoadImage();
};