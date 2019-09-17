#pragma once
#include "stdafx.h"
#include "Boss3.h"
#include "Boss1Move.h"
#include "BossBall3.h"
#include "EBall1.h"

CBoss3::CBoss3()
{
	HP = 300;
	m_ptPos.x = GAME_WIDTH / 2 - BOSSWIDTH / 2;
	m_ptPos.y = BOSSHEIGHT / 2;
	move = new CBoss1Move;
	move->init();
	m_Wait = 0;
	m_limit = 40;
}

void CBoss3::DoFired(CObList* List)
{
	if (Fired()) {
		List[3].AddTail(new CBossBall3(m_ptPos.x + BOSSWIDTH / 2, m_ptPos.y + BOSSHEIGHT));
	}
}

CBoss3::~CBoss3() { delete move; }

BOOL CBoss3::Draw(CDC* pDC, BOOL bPause)
{
	BOOL flg = CBoss::Draw(pDC, bPause);
	m_Images.Draw(pDC, 2, m_ptPos, ILD_TRANSPARENT);
	if (flg)
		return TRUE;
	else return FALSE;
}