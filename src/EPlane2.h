#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Plane.h"
#include "EPlane.h"

class CEPlane2 : public CEPlane
{
public:
	CEPlane2(int x, int y, int z = 1, int h = 1, int num = 1);
	CEPlane2();

	~CEPlane2();
	BOOL Draw(CDC* pDC, BOOL bPause);
	int m_nImgIndex;
	static int n_Wait, Limit;
	static void Mupdate();
	static bool Isappear();
	void DoFired(CObList* List);
};