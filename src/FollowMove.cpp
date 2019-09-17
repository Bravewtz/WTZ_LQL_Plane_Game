#pragma once
#include "stdafx.h"
#include "EMove.h"
#include "FollowMove.h"

#include <vector>
using namespace std;

CFollowMove::CFollowMove(){}
CFollowMove::~CFollowMove(){}
CFollowMove::CFollowMove(CPoint p)
{
	wait = 0;
	My.x = p.x;
	My.y = p.y;
	VX = 0, VY = 0;
}
void CFollowMove::init()
{
}
void CFollowMove::update()
{
	if (VY == 0) {
		if (Goal.y < My.y)VY = -6;
		else VY = 6;
		if (Goal.x < My.x)VX = -6;
		else VX = 6;
	}
	//if (wait > 0)wait--;
}

int CFollowMove::GetVx()
{

	if ((Goal.y > My.y&&VY < 0) || (Goal.y < My.y&&VY>0)) {
		My.x += VX;
		return VX;
	}
	
	 else if (Goal.x > My.x) {
		if (Goal.x - My.x < 10) {
			int d = Goal.x - My.x;
			My.x += d;
			VX = d;
			return d;
		}
		else {
			My.x += 10;
			VX = 10;
			return 10;
		}
	}
	else if (Goal.x < My.x) {
		if (My.x - Goal.x < 10) {
			int d = My.x - Goal.x;
			My.x -= d;
			VX = -d;
			return -d;
		}
		else {
			My.x -= 10;
			VX = -10;
			return -10;
		}
	}
	return 0;
}

int CFollowMove::GetVy()
{
/*	if (VX != 0&&(My.x!=Goal.x)) {
		int t = abs(My.x - Goal.x) / VX;
		int v = abs(My.x - Goal.x) / t;
		VY = max(5, v);
	}*/
	My.y += VY;
	return VY;
}