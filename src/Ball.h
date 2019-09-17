#pragma once
#include "GameObject.h"
#include "Move.h"
#include "EMove.h"
#include "MyPlane.h"
class CBall :public CGameObject
{
public:
	CBall(int x, int y, int attack = 1, int W = 0, int H = 0);
	CBall();
	~CBall(void);
	CObList*    m_ObjList;
	CMyPlane* me;

	void SetList(CObList* List);
	void SetMy(CMyPlane* me);
	virtual void Show(CDC* pMemDC);
	int GetAttack() { return attack; }
	virtual BOOL Draw(CDC* pDC, BOOL bPause); //ªÊ÷∆∂‘œÛ
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + Ball_Width, m_ptPos.y + Ball_Height));
	}
	virtual void SetMoveL();
	virtual void SetMoveR();
protected:
	int attack;
	CEMove* move;
	int Ball_Width, Ball_Height;
};