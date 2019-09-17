#pragma once
#include "GameObject.h"
class CExplosion :public CGameObject {
protected:
	int m_nProcess;
	int limit;
public:
	CExplosion(int x=0,int y=0,int limit=18);
	~CExplosion();
	BOOL Draw(CDC* pDC, BOOL bPause); //绘制对象
	CRect GetRect();	//获得矩形区域
	bool Update();
	CObList*    m_ObjList;
	void SetList(CObList* List);
	virtual void Show(CDC* pMemDC);
};
