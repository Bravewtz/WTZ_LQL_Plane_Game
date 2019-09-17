#pragma once
#include "stdafx.h"
#include "EBall.h"
class CBossBall3 : public CEBall
{
public:
	CBossBall3(int x_, int y_);
	CBossBall3();
	~CBossBall3();
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
private:
	static const int BOSSBALL3_HEIGHT = 43;
	static const int BOSSBALL3_WIDTH = 43;
	static CImageList m_Images;
};