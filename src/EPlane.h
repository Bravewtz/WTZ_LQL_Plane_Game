#pragma once
#include "Plane.h"
#include "EMove.h"
#include "Ball.h"

class CEPlane :public CPlane {
public:
	CEPlane(int x=0, int y=0, int z=0, int h = 1, int W = ENEMY_HEIGHT, int H = ENEMY_WIDTH);
	//CEPlane();
	~CEPlane();
	CEMove* move;
	int attack;
	int GetAttack() { return attack; }
	int Score;
	int GetScore() { return Score; }

	virtual BOOL Draw(CDC* pDC, BOOL bPause);
	void Show(CDC* pMemDC);
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMY_WIDTH, m_ptPos.y + ENEMY_HEIGHT));
	}
	virtual void DoFired(CObList* List);
	static BOOL LoadImageUp();
	static BOOL LoadImageDown();
public:
	static const int ENEMY_HEIGHT = 60;
	static const int ENEMY_WIDTH = 100;
	static CImageList m_ImagesUp;
	static CImageList m_ImagesDown;
};