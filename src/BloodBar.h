#pragma once
#include "stdafx.h"
#include "GameObject.h"

class CBloodBar :public CGameObject {
public:
	CBloodBar();
	CBloodBar(int W, int H);
	~CBloodBar();
	BOOL Draw(CDC* pDC, BOOL bPause);
	CRect GetRect();
	BOOL DrawBloodBar(CDC* pDC, int HP_,CPoint pos, unsigned long color);
	int WIDTH, HEIGHT;
};
