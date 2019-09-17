#pragma once
#include "Resource.h"
#include "EPlane1.h"
#include "Boss.h"
#include "WingPlane.h"
class CPass {
public:
	CPass();
	CPass(int socre);
	~CPass();
	void init();
	int NowScore;
	int NowPass;
	int have_pass;
	int PassScore[4];
	int GetPass();
	void Work(CDC* pMemDC);
	void DrawBack(CDC* pMemDC,int num);
	void SetScore(int x) { NowScore += x; }
	int GetScore() { return NowScore; }
	bool InBoss;
	bool has_Boss[4];
	void MakeBoss();
	void ShowWing(CDC* pMemDC);
	CBoss * boss;

	CObList*    m_ObjList;
	void SetList(CObList* List)
	{
		m_ObjList = List;
	}
	void EPlaneFire();
	void MakeEPlane();
};