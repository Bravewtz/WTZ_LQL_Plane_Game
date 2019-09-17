#pragma once
#include "stdafx.h"
#include "resource.h"
#include "EPlane1.h"
#include "Plane.h"
#include "GameObject.h"
#include "EPlane1Move.h"
#include "EBall1.h"
CEPlane1::CEPlane1(int x, int y, int z, int h,int num):CEPlane(x,y,z,h),m_nImgIndex(num)
{
	m_limit = 10;
}
void CEPlane1::DoFired(CObList* List)
{
	if(Fired())List[3].AddTail(new CEBall1(m_ptPos.x+ENEMY_WIDTH/2,m_ptPos.y+ENEMY_HEIGHT));
}

CEPlane1::CEPlane1(){
	HP = 1;
	Score = 1;
	m_nImgIndex = 0;
	attack = 1;
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMY_HEIGHT) + 1;
	m_ptPos.y = -ENEMY_HEIGHT;
	m_Wait = rand()%60;
	m_limit = 60;
	move = new CEPlane1Move;
	move->init();
}

int CEPlane1::n_Wait = 0;
int CEPlane1::Limit = 15;
CEPlane1::~CEPlane1() { delete move; }

void CEPlane1::Mupdate()
{
	n_Wait++;
	if (n_Wait >= Limit)n_Wait = 0;
}
bool CEPlane1::Isappear()
{
	if (n_Wait == 0)return true;
	return false;
	//return true;
}

BOOL CEPlane1::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CEPlane::Draw(pDC, bPause);
	m_ImagesDown.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}
