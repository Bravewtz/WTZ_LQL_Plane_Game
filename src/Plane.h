#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "BloodBar.h"
class CPlane:public CGameObject{
public:
	//CPlane();
	CPlane(int x=0, int y=0, int HP=0, int Width=0, int Height=0);
	~CPlane();
	int HP;
	void SetHP(int x) { HP += x; }
	int GetHP() { return HP; }
	int V_x, V_y;
	void SetVx(int x) { V_x = x; }
	void SetVy(int x) { V_y = x; }
	int GetVx() { return V_x; }
	int GetVy() { return V_y; }
	int m_Wait,m_limit;
	void Setlimit(int x) { m_limit = x; }
	int Getlimit() { return m_limit; }
	bool Fired();
	void update();

	CBloodBar * bar;
public:
	CObList*    m_ObjList;
	void SetList(CObList* List);
	virtual void Show(CDC* pMemDC);
protected:
	int PlaneWidth, PlaneHeight;
};