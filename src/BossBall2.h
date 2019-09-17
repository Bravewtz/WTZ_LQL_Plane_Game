#pragma once
#include "stdafx.h"
#include "EBall.h"
class CBossBall2 : public CEBall
{
public:
	CBossBall2(int x_, int y_);
	CBossBall2();
	~CBossBall2();
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
private:
	static const int BOSSBALL2_HEIGHT = 43;
	static const int BOSSBALL2_WIDTH = 43;
	static CImageList m_Images;
};