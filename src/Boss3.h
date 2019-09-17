#pragma once
#include "Boss.h"
#include "Ball.h"
#include "Plane.h"
class CBoss3 :public CBoss
{
public:
	CBall* ball;
	CBoss3();
	~CBoss3();
	BOOL Draw(CDC* pDC, BOOL bPause);
	void DoFired(CObList* List);
};
