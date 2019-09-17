#pragma once
#include "stdafx.h"
#include "Boss1.h"
#include "Boss1Move.h"
#include "BossBall1.h"
#include "EBall1.h"

CBoss1::CBoss1()
{
	HP = 300;
	m_ptPos.x = GAME_WIDTH / 2-BOSSWIDTH/2;
	m_ptPos.y = BOSSHEIGHT/2;
	move = new CBoss1Move;
	move->init();
	m_Wait = 0;
	m_limit = 40;
}

void CBoss1::DoFired(CObList* List)
{
	if (Fired()) {
		List[3].AddTail(new CBossBall1(m_ptPos.x + BOSSWIDTH / 2, m_ptPos.y + BOSSHEIGHT));	
		List[3].AddTail(new CBossBall1(m_ptPos.x + BOSSWIDTH, m_ptPos.y + BOSSHEIGHT));
		List[3].AddTail(new CBossBall1(m_ptPos.x,m_ptPos.y+BOSSHEIGHT));
		List[3].AddTail(new CBossBall1(m_ptPos.x - BOSSWIDTH / 2, m_ptPos.y + BOSSHEIGHT));
		List[3].AddTail(new CBossBall1(m_ptPos.x + BOSSWIDTH+140 , m_ptPos.y + BOSSHEIGHT));
	}
}

CBoss1::~CBoss1() { delete move; }
BOOL CBoss1::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBoss::Draw(pDC, bPause);
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}
