#pragma once
#include "stdafx.h"
#include "MyBallRightMove.h"
CMyBallRightMove::CMyBallRightMove() {}
CMyBallRightMove::~CMyBallRightMove() {}
void CMyBallRightMove::init()
{
	AllPeriod = 1;
	NowPeriod = 0;
	Period.push_back(0);
	Vx.push_back(3);
	Vy.push_back(-8);
}