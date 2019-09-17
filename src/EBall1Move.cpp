#pragma once 
#include "stdafx.h"
#include "EBall1Move.h"

#include <vector>
using namespace std;

CEBall1Move::CEBall1Move() {}
CEBall1Move::~CEBall1Move() {}
void CEBall1Move::init()
{
	AllPeriod = 1;
	NowPeriod = 0;
	Period.push_back(0);
	Vx.push_back(0);
	Vy.push_back(10);
}