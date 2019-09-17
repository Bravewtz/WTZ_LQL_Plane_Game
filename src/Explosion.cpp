#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Explosion.h"

CExplosion::CExplosion(int x, int y, int limit) :CGameObject(x, y), limit(limit) { m_nProcess = 0; }
CExplosion::~CExplosion(){}
bool CExplosion::Update(){
	if (m_nProcess >= limit) {
		m_nProcess = 0;
		return false;
	}
	m_nProcess++;
}

BOOL CExplosion::Draw(CDC* pDC, BOOL bPause) //绘制对象
{
	return 1;
}
CRect CExplosion::GetRect()	//获得矩形区域
{
	RECT r;
	return r;
}
void CExplosion::SetList(CObList* List)
{
	m_ObjList = List;
}

void CExplosion::Show(CDC* pMemDC)
{
	POSITION pos1, pos2;
	for (pos1 = m_ObjList[2].GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CGameObject* pObj = (CGameObject*)m_ObjList[2].GetNext(pos1);
		if (!pObj->Draw(pMemDC, FALSE)){
			m_ObjList[2].RemoveAt(pos2);
			delete pObj;
		}
	}
}