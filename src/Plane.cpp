#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "GameObject.h"
//CPlane::CPlane() { HP = 0; m_Wait = 0; V_x = 0; V_y = 0; }
CPlane::CPlane(int x, int y, int z,int W, int H) :CGameObject(x, y), HP(z), PlaneWidth(W), PlaneHeight(H)
{
	m_Wait = 0; V_x = 0; V_y = 0;
}
CPlane::~CPlane() {}
bool CPlane::Fired() {
	if (m_Wait == 0)return true;
	return false;
}

void CPlane::update() {
	int Limit = Getlimit();
	m_Wait++;
	if (m_Wait >= m_limit)m_Wait = 0;
	//return 1;
}

void CPlane::SetList(CObList* List) 
{
	m_ObjList = List;
}
void CPlane::Show(CDC* pMemDC){}
