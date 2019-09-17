#pragma once
#include "stdafx.h"
#include "EPlane1Move.h"
CEPlane1Move::CEPlane1Move(){}

CEPlane1Move::~CEPlane1Move(){}

void CEPlane1Move::init()
{
	AllPeriod = 1;
	NowPeriod = 0;
	Period.push_back(0);
	Vx.push_back(0);
	Vy.push_back(4);
}
