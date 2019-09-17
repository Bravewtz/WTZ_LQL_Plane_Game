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
	int JudgeMoveKey();//���а����ƶ�
	int JudgeFire();//����ս��������J����ͨ����)
	int JudgeGod();//�ϵ�ģʽ��P��)
	int CallWing();
	/*
	int JudgeDazhao();//������У�K��)
	*/
};