#pragma once
#include "Ball.h"
#include "EBall.h"
class CEBall1 : public CEBall
{
public:
	CEBall1(int x_, int y_);
	CEBall1();
	~CEBall1(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
private:
	static const int EBALL1_HEIGHT = 8;
	static const int EBALL1_WIDTH = 8;
	static CImageList m_Images;
};
