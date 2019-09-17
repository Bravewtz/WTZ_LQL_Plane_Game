#pragma once
#include "stdafx.h"
#include "MyBall1Move.h"
#include <vector>
using namespace std;

CMyBall1Move::CMyBall1Move(){}
CMyBall1Move::~CMyBall1Move(){}
void CMyBall1Move::init()
{
	AllPeriod = 1;
	NowPeriod = 0;
	Period.push_back(0);
	Vx.push_back(0);
	Vy.push_back(-8);
}