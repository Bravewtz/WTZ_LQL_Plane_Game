#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include "MyPlane.h"
#include "Plane.h"
#include "Pass.h"
class CJudgeCollision
{
public:
	BOOL JudgeIntersection(CGameObject* a, CGameObject* b);
	BOOL IsDead(CPlane* plane);
	void AddExp(CPoint p);
	void BeAttacked(CPlane*plane,int atk);
	void SetMe(CMyPlane* Me)
	{
		m_pMe = Me;
	}
	void SetList(CObList* List)
	{
		m_ObjList = List;
	}
	void SetPass(CPass* P)
	{
		Pass = P;
	}
	bool EPlaneAttack();//敌机攻击飞机
	void MyBallAttack();
	bool DPlaneTouch();//飞机敌机相撞
protected:
	CMyPlane*  m_pMe;
	CObList* m_ObjList;
	CPass* Pass;
};