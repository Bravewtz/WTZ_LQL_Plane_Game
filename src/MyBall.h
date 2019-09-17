#pragma once
#include "Ball.h"

class CMyBall : public CBall
{
public:
	void Show(CDC* pMemDC);
	CMyBall(int x, int y, int attack = 1, int W = 0, int H = 0);
	CMyBall();
	~CMyBall(void);
	//virtual BOOL Draw(CDC* pDC, BOOL bPause); //绘制对象
	//virtual CRect GetRect();	//获得矩形区域
};