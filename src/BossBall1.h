#pragma once
#include "stdafx.h"
#include "EBall.h"
class CBossBall1 : public CEBall
{
public:
	CBossBall1(int x_, int y_);
	CBossBall1();
	~CBossBall1();
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
private:
	static const int BOSSBALL1_HEIGHT = 65;
	static const int BOSSBALL1_WIDTH = 65;
	static CImageList m_Images;
};