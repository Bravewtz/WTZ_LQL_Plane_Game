#pragma once
#include "Boss.h"
#include "Ball.h"
#include "Plane.h"
class CBoss1:public CBoss
{
public:
	CBall* ball;
	CBoss1();
	~CBoss1();
	BOOL Draw(CDC* pDC, BOOL bPause);
	void DoFired(CObList* List);
};
