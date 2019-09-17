#pragma once
#include "Move.h"
#include "MyPlane.h"
#include "WingPlane.h"
class CMyMove :public CMove {
public:
	CMyPlane *m_pMe;
	CObList*    m_ObjList;
	int Wing_wait;
public:
	bool AppearWing();
	void update_Wing();
	CMyMove();
	~CMyMove(void);
	void SetMe(CMyPlane *Me);
	void SetList(CObList* ObjList);
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000) ? 1 : 0;
	}
	int JudgeMoveKey();//进行按键移动
	int JudgeFire();//发射战机导弹（J键普通攻击)
	int JudgeGod();//上帝模式（P键)
	int CallWing();
	/*
	int JudgeDazhao();//发射大招（K键)
	*/
};