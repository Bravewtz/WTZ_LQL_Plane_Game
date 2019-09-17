#pragma once
#include "Ball.h"
#include "MyBall.h"

class CMyBall1 : public CMyBall
{
public:
	CMyBall1(int x_, int y_, int attack = 1);
	CMyBall1();
	~CMyBall1(void);
	BOOL Draw(CDC* pDC, BOOL bPause);
	static BOOL LoadImage();
	void CMyBall1::SetMoveL();
	void CMyBall1::SetMoveR();
private:
	static const int BALL_HEIGHT = 20;
	static const int BALL_WIDTH = 10;
	static CImageList m_Images;
	int    MyBall1_Motion;
};
