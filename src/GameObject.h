#pragma once
#include "stdafx.h"

//��Ϸ����ĸ���
class CGameObject : public CObject
{
public:
	CGameObject(int x = 0, int y = 0);
	virtual ~CGameObject();
	virtual BOOL Draw(CDC* pDC, BOOL bPause) = 0; //���ƶ���
	virtual CRect GetRect() = 0;	//��þ�������
	//������Ͻ�����
	CPoint GetPoint()
	{
		return m_ptPos;
	}
protected:
	//����ͼ��
	static BOOL LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int cx, int cy, int nInitial);

protected:
	CPoint  m_ptPos;	//�����λ��
};


