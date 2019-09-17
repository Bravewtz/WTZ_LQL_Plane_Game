#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include "Plane.h"
#include "EPlane.h"
#include "EPlane2.h"
#include "EPlane2Move.h"
#include "EBall1.h"
//#include "EBall2.h"


CEPlane2::CEPlane2(int x, int y, int z, int h, int num) :CEPlane(x, y, z, h), m_nImgIndex(num)
{
	m_limit = 10;
}

void CEPlane2::DoFired(CObList* List)
{
	if (Fired())List[3].AddTail(new CEBall1(m_ptPos.x + ENEMY_WIDTH / 2, m_ptPos.y + ENEMY_HEIGHT));
}

CEPlane2::CEPlane2() {
	HP = 1;
	m_nImgIndex = 1;
	Score = 1;
	attack = 1;
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMY_HEIGHT) + 1;
	m_ptPos.y = -ENEMY_HEIGHT;
	m_Wait = rand() % 60;
	m_limit = 60;
	move = new CEPlane2Move;
	move->init();
}

int CEPlane2::n_Wait = 0;
int CEPlane2::Limit = 15;
CEPlane2::~CEPlane2() { delete move; }
void CEPlane2::Mupdate()
{
	n_Wait++;
	if (n_Wait >= Limit)n_Wait = 0;
}

bool CEPlane2::Isappear()
{
	if (n_Wait == 0)return true;
	return false;
}

BOOL CEPlane2::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CEPlane::Draw(pDC, bPause);
	m_ImagesDown.Draw(pDC,1, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}