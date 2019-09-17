#pragma once
#include "stdafx.h"
#include "EMove.h"

CEMove::CEMove(){}
CEMove::~CEMove(){}
int CEMove::GetVx()
{
	return Vx[NowPeriod];
}
int CEMove::GetVy()
{
	return Vy[NowPeriod];
}
void CEMove::init() {
	AllTime = 0;
}

CEMove::CEMove(CPoint p)
{
	My.x = p.x;
	My.y = p.y;
}

void CEMove::update()
{
	SetTime(1);
	for (int i = AllPeriod-1; i >=0; i--) {
		if (AllTime >= Period[i]) {
			NowPeriod = i;
			break;
		}
	}
}
