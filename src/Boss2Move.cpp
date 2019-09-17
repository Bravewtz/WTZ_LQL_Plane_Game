#pragma once
#include "stdafx.h"
#include "EMove.h"
#include "Boss2Move.h"

#include <vector>
using namespace std;
CBoss2Move::CBoss2Move() {}
CBoss2Move::~CBoss2Move() {}

void CBoss2Move::init()
{
	AllPeriod = 8;
	NowPeriod = 0;

	Period.push_back(0);
	Period.push_back(30);
	Period.push_back(60);
	Period.push_back(90);
	Period.push_back(120);
	Period.push_back(150);
	Period.push_back(180);
	Period.push_back(210);

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

	Vx.push_back(0);
	Vy.push_back(10);

	Vx.push_back(0);
	Vy.push_back(-10);

	Vx.push_back(0);
	Vy.push_back(0);

}
void CBoss2Move::update()
{
	if (NowPeriod == AllPeriod - 1) {
		AllTime = 0;
		NowPeriod = 0;
	}
	CEMove::update();
}
