#pragma once
#include "stdafx.h"
#include "WingPlaneMove.h"

CWingPlaneMove::CWingPlaneMove(){}
CWingPlaneMove::~CWingPlaneMove(){}

void CWingPlaneMove::init()
{
	AllPeriod = 6;
	NowPeriod = 0;
	Period.push_back(0);
	Period.push_back(20);
	Period.push_back(50);
	Period.push_back(80);
	Period.push_back(120);
	Period.push_back(150);

	Vx.push_back(0);
	Vy.push_back(-20);

	
	Vx.push_back(-5);
	Vy.push_back(0);

	Vx.push_back(5);
	Vy.push_back(0);

	Vx.push_back(-5);
	Vy.push_back(0);

	Vx.push_back(5);
	Vy.push_back(0);

	Vx.push_back(0);
	Vy.push_back(-20);
}