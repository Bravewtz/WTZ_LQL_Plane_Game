#pragma once
#include "Move.h"
#include <vector>
using namespace std;

class CEMove :public CMove {
public:
	int AllTime;
	int AllPeriod;
	int NowPeriod;
	int V_x, V_y;
	vector<int>Period;
	vector<int>Vx;
	vector<int>Vy;

	CPoint My, Goal;
	void SetGoal(CPoint p)
	{
		Goal.x = p.x;
		Goal.y = p.y;
	}

public:
	CEMove();
	~CEMove();
	CEMove(CPoint p);

	void SetTime(int x) { AllTime += x; }
	void SetPeriod(int x) { AllPeriod = x; }
	int GetTime() { return AllTime; }
	int GetPeriod() { return AllPeriod; }
	virtual int GetVx();
	virtual int GetVy();
	int GetNow() { return NowPeriod; }
	virtual void update();
	virtual void init();


};