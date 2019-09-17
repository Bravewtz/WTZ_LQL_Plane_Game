#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "GameObject.h"
class CMyPlane:public CPlane{
public:
	CMyPlane();
	~CMyPlane();
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	static BOOL LoadImage2();
	static const int MYPLANE_WIDTH = 50;
	static const int MYPLANE_HEIGHT = 60;
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + MYPLANE_WIDTH, m_ptPos.y + MYPLANE_HEIGHT));
	}
	void SetGod() { God ^=1; }
	bool IsGod() { return God; }
private:
	static CImageList m_Images;
	static CImageList m_ImagesDF;
	bool God;
public:
	int wait = 0;
};