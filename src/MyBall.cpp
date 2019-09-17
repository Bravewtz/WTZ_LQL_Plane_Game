#include "StdAfx.h"
#include "MyBall.h"
#include "resource.h"
#include "GameObject.h"

CMyBall::CMyBall(int x, int y, int atk,int W,int H) :CBall(x, y, atk,W,H)
{
}
CMyBall::CMyBall() 
{
}
CMyBall::~CMyBall(void)
{
}
/*
BOOL CMyBall::Draw(CDC* pDC, BOOL bPause) //绘制对象
{
	return 0;
}

CRect CMyBall::GetRect()//获得矩形区域
{
	RECT r;
	return r;
}
*/
void CMyBall::Show(CDC* pMemDC) 
{
	POSITION pos1, pos2;
	for (pos1 = m_ObjList[0].GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CGameObject* pObj = (CGameObject*)m_ObjList[0].GetNext(pos1);
		if (!pObj->Draw(pMemDC, FALSE))
		{
			m_ObjList[0].RemoveAt(pos2);
			delete pObj;
		}
	}
}

