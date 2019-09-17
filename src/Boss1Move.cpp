#pragma once
#include "stdafx.h"
#include "EMove.h"
#include "Boss1Move.h"
#include <vector>
using namespace std;

CBoss1Move::CBoss1Move(){}
CBoss1Move::~CBoss1Move(){}

void CBoss1Move::init()
{
	AllPeriod = 5;
	NowPeriod = 0;
	Period.push_back(0);
	Period.push_back(30);
	Period.push_back(60);
	Period.push_back(90);
	Period.push_back(120);

	Vx.push_back(-3);
	Vy.push_back(3);

	Vx.push_back(3);
	Vy.push_back(3);
	
	Vx.push_back(3);
	Vy.push_back(-3);

	Vx.push_back(-3);
	Vy.push_back(-3);

	Vx.push_back(0);
	Vy.push_back(0);
}
void CBoss1Move::update() 
{
	if (NowPeriod == AllPeriod - 1) {
		AllTime = 0;
		NowPeriod = 0;
	}
	CEMove::update();
}
