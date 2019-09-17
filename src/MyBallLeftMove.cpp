#pragma once
#include "stdafx.h"
#include "MyBallLeftMove.h"

CMyBallLeftMove::CMyBallLeftMove(){}
CMyBallLeftMove::~CMyBallLeftMove(){}
void CMyBallLeftMove::init()
{
	AllPeriod = 1;
	NowPeriod = 0;
	Period.push_back(0);
	Vx.push_back(-3);
	Vy.push_back(-8);
}