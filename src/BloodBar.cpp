#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "BloodBar.h"

CBloodBar::CBloodBar(){}
CBloodBar::~CBloodBar(){}
CBloodBar::CBloodBar(int W,int H):WIDTH(W), HEIGHT(H){}

BOOL CBloodBar::Draw(CDC* pDC, BOOL bPause) { return 1; }
CRect CBloodBar::GetRect() { return RECT(); }
BOOL CBloodBar::DrawBloodBar(CDC* pDC, int HP, CPoint pos, unsigned long color)
{
	CBrush b1(color);
	pDC->SelectObject(&b1);

	int len = HP * 8;
	pDC->Rectangle(pos.x-len/2, pos.y+HEIGHT, pos.x+len, pos.y+HEIGHT+10);
	return TRUE;
}