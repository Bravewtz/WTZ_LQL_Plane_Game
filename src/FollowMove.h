#pragma once
#include "EMove.h"
class CFollowMove :public CEMove {
public:
	CFollowMove();
	CFollowMove(CPoint p);
	~CFollowMove();
	void update();
	void init();
	int GetVx();
	int GetVy();
	int VX, VY, wait;
};
