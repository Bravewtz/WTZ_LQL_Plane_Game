#pragma once 
#include "stdafx.h"
#include "GameObject.h"
#include "EPlane.h"
#include "EPlane2Move.h"
CEPlane2Move::CEPlane2Move() {}
CEPlane2Move::~CEPlane2Move() {}

void CEPlane2Move::init()
{
	AllPeriod = 2;
	V_x = rand() % 6 + 2;
	V_y = rand() % 6 + 2;
	int dir = rand() % 2;
	if (V_x > V_y) swap(V_x, V_y);
	if (dir == 0)V_x = -V_x;

	Vx.push_back(V_x);
	Vy.push_back(V_y);
	Vx.push_back(0);
	Vy.push_back(30);
	Period.push_back(0);
	Period.push_back(60);
}
