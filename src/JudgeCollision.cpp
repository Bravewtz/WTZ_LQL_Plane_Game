#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "JudgeCollision.h"
#include "resource.h"
#include "MyBall1.h"
#include "EPlane.h"
#include "Explosion_1.h"
#include "Plane.h"
#include "EBall.h"
#include "EBall1.h"

BOOL CJudgeCollision::JudgeIntersection(CGameObject* a, CGameObject* b)
{
	CRect mRect = a->GetRect();
	CRect bRect = b->GetRect();
	CRect tmpRect;
	if (tmpRect.IntersectRect(&bRect, mRect))
	{
		return true;
	}
	return false;
}
BOOL CJudgeCollision::IsDead(CPlane* plane)
{
	if (plane->GetHP() <= 0)return TRUE;
	return FALSE;
}

void CJudgeCollision::BeAttacked(CPlane*plane,int atk)
{
	plane->SetHP(-atk);
}
void CJudgeCollision::AddExp(CPoint p)
{
	m_ObjList[2].AddTail(new CExplosion_1(p.x, p.y));
}
void CJudgeCollision::MyBallAttack()
{
	//战机导弹炸掉敌机

	if (Pass->InBoss)
	{
		POSITION mPos1 = NULL, mPos2 = NULL;
		for (mPos1 = m_ObjList[0].GetHeadPosition(); (mPos2 = mPos1) != NULL;)
		{
			CMyBall* pMyBall = (CMyBall*)m_ObjList[0].GetNext(mPos1);
			CRect bRect = pMyBall->GetRect();

			CRect bosRect = Pass->boss->GetRect();
			CRect tmpRect;
			if (tmpRect.IntersectRect(&bosRect, bRect))
			{
				BeAttacked(Pass->boss, pMyBall->GetAttack());
				AddExp(CPoint(bRect.left, bRect.top));
				m_ObjList[0].RemoveAt(mPos2);//删除导弹
				delete pMyBall;
				pMyBall = NULL;
				if (IsDead(Pass->boss)) {
					delete Pass->boss;
					Pass->boss = NULL;
					Pass->InBoss = 0;
				}
				break;
			}
		}
	}

	POSITION mPos1 = NULL, mPos2 = NULL;
	for (mPos1 = m_ObjList[0].GetHeadPosition(); (mPos2 = mPos1) != NULL;)
	{
		CMyBall* pMyBall = (CMyBall*)m_ObjList[0].GetNext(mPos1);
		CRect bRect = pMyBall->GetRect();


		POSITION ePos1 = NULL, ePos2 = NULL;
		for (ePos1 = m_ObjList[1].GetHeadPosition(); (ePos2 = ePos1) != NULL;)
		{
			CEPlane* pEPlane = (CEPlane*)m_ObjList[1].GetNext(ePos1);	
			CRect mRect = pEPlane->GetRect();
			CRect tmpRect;
			if (tmpRect.IntersectRect(&bRect, mRect))
			{
				BeAttacked(pEPlane,pMyBall->GetAttack());
				AddExp(CPoint(mRect.left, mRect.top));//m_ObjList[2].AddTail(new CExplosion_1(mRect.left, mRect.top));
				m_ObjList[0].RemoveAt(mPos2);//删除导弹
				delete pMyBall;
				pMyBall = NULL;
				if (IsDead(pEPlane)) {
					//删除敌机
					if(!Pass->InBoss)Pass->SetScore(pEPlane->GetScore());
					m_ObjList[1].RemoveAt(ePos2);
					delete pEPlane;
					break;				
				}
			}
		}
	}
}
bool CJudgeCollision::EPlaneAttack()//敌机攻击飞机
{
	POSITION bPos1 = NULL, bPos2 = NULL;
	CRect mRect = m_pMe->GetRect();

	for (bPos1 = m_ObjList[3].GetHeadPosition(); (bPos2 = bPos1) != NULL;)
	{
		CEBall* pBall = (CEBall*)m_ObjList[3].GetNext(bPos1);
		CRect bRect = pBall->GetRect();
		CRect tmpRect;
		if (tmpRect.IntersectRect(&bRect, mRect))
		{
			AddExp(CPoint(mRect.left,mRect.top));
			if (!m_pMe->IsGod()) {
				BeAttacked(m_pMe, pBall->GetAttack());
				if (IsDead(m_pMe)) {
					//添加爆炸效果
					//删除战机
					delete m_pMe;
					m_pMe = NULL;
					return true;
				}			
			}
			//删除子弹
			m_ObjList[3].RemoveAt(bPos2);
			delete pBall;

		}
	}
	return false;
}
bool CJudgeCollision::DPlaneTouch()
{
	//战机与敌机相撞
	CRect mRect = m_pMe->GetRect();
	POSITION p1 = NULL, p2 = NULL;
	for (p1 = m_ObjList[1].GetHeadPosition(); (p2 = p1) != NULL;) {
		CEPlane* Ep = (CEPlane*)m_ObjList[1].GetNext(p1);
		CRect eRect = Ep->GetRect();
		CRect Rtmp;
		if (Rtmp.IntersectRect(&eRect, mRect)) {
			//m_ObjList[2].AddTail(new CExplosion_1(eRect.left, eRect.top));
			AddExp(CPoint(eRect.left, eRect.top));
			if (!m_pMe->IsGod()) {
			//m_ObjList[2].AddHead(new CExplosion_1(mRect.left, mRect.top));
			BeAttacked(m_pMe, Ep->GetAttack());
				if (IsDead(m_pMe)) {
					delete m_pMe;
					m_pMe = NULL;
					return 1;
				}
			}
			m_ObjList[1].RemoveAt(p2);
			delete Ep;
			Ep = NULL;
		}
	}
	return 0;
}