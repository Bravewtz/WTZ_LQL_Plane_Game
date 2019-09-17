#pragma once
#include "stdafx.h"
#include "Boss2.h"
#include "Boss2Move.h"
#include "BossBall2.h"
#include "EBall1.h"
CBoss2::CBoss2()
{
	HP = 300;
	m_ptPos.x = GAME_WIDTH / 2 - BOSSWIDTH / 2;
	m_ptPos.y = BOSSHEIGHT / 2;
	move = new CBoss2Move;
	move->init();
	m_Wait = 0;
	m_limit = 40;
}

void CBoss2::DoFired(CObList* List)
{
	if (move->NowPeriod == 4&&Fired()) {

		List[3].AddTail(new CBossBall2(m_ptPos.x+BOSSWIDTH/2,m_ptPos.y+BOSSHEIGHT/2));
		List[3].AddTail(new CBossBall2(m_ptPos.x+BOSSWIDTH/2,m_ptPos.y-BOSSHEIGHT/2));
		List[3].AddTail(new CBossBall2(m_ptPos.x,m_ptPos.y));

		List[3].AddTail(new CBossBall2(m_ptPos.x+BOSSWIDTH/2+BOSSWIDTH/3,m_ptPos.y));

		List[3].AddTail(new CBossBall2(m_ptPos.x + BOSSWIDTH / 4, m_ptPos.y + BOSSHEIGHT /2));
		List[3].AddTail(new CBossBall2(m_ptPos.x + BOSSWIDTH / 4, m_ptPos.y - BOSSHEIGHT /2));

	}else if (Fired()) {
		
		List[3].AddTail(new CBossBall2(m_ptPos.x + BOSSWIDTH / 2, m_ptPos.y + BOSSHEIGHT));
		List[3].AddTail(new CBossBall2(m_ptPos.x + BOSSWIDTH, m_ptPos.y + BOSSHEIGHT));
		List[3].AddTail(new CBossBall2(m_ptPos.x, m_ptPos.y + BOSSHEIGHT));
		List[3].AddTail(new CBossBall2(m_ptPos.x - BOSSWIDTH / 2, m_ptPos.y + BOSSHEIGHT));
		List[3].AddTail(new CBossBall2(m_ptPos.x + BOSSWIDTH + 140, m_ptPos.y + BOSSHEIGHT));
		
	}
}
CBoss2::~CBoss2() { delete move; }
BOOL CBoss2::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBoss::Draw(pDC, bPause);
	m_Images.Draw(pDC, 1, m_ptPos, ILD_TRANSPARENT);
	if(flg)
		return TRUE;
	else return FALSE;
}
