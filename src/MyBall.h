#pragma once
#include "Ball.h"

class CMyBall : public CBall
{
public:
	void Show(CDC* pMemDC);
	CMyBall(int x, int y, int attack = 1, int W = 0, int H = 0);
	CMyBall();
	~CMyBall(void);
	//virtual BOOL Draw(CDC* pDC, BOOL bPause); //���ƶ���
	//virtual CRect GetRect();	//��þ�������
};