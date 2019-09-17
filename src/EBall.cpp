#pragma once
#include "StdAfx.h"
#include "EBall.h"
#include "resource.h"
#include "GameObject.h"
#include "BossBall3.h"
#include <typeinfo>

CEBall::CEBall(int x, int y, int atk,int W,int H) :CBall(x, y, atk,W,H)
{
}

CEBall::CEBall()
{
}
CEBall::~CEBall()
{
}
void CEBall::Show(CDC* pMemDC)
{
	POSITION pos1, pos2;
	for (pos1 = m_ObjList[3].GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CEBall* pObj = (CEBall*)m_ObjList[3].GetNext(pos1);
		
		if (typeid(*pObj) ==typeid(CBossBall3))
		{
			pObj->move->SetGoal(me->GetPoint());
		}

		if(	!pObj->Draw(pMemDC, FALSE))
		{
			m_ObjList[3].RemoveAt(pos2);
			delete pObj;
		}

	}
}
