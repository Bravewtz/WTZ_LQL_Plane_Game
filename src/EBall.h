#pragma once
#include "Ball.h"

class CEBall : public CBall
{
public:
	CEBall(int x, int y, int attack = 1, int W = 0, int H = 0);
	CEBall(void);
	~CEBall();
	
	void Show(CDC* pMemDC);
};