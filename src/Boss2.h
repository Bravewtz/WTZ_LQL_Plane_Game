#pragma once
#include "Boss.h"
#include "Ball.h"
#include "Plane.h"
class CBoss2 :public CBoss
{
public:
	CBall* ball;
	CBoss2();
	~CBoss2();
	BOOL Draw(CDC* pDC, BOOL bPause);
	void DoFired(CObList* List);
};
