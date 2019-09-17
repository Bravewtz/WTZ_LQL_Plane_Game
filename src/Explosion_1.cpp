#pragma once
#include "stdafx.h"
#include "resource.h"
#include "GameObject.h"
#include "Explosion.h"
#include "Explosion_1.h"
CImageList CExplosion_1::m_Images;
CExplosion_1::CExplosion_1(int x,int y,int limit):CExplosion(x,y,18){}
CExplosion_1::~CExplosion_1(){}

BOOL CExplosion_1::Draw(CDC* pDC, BOOL bPause)
{

	//用新位置绘制图像
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	if (Update())return TRUE;
	return FALSE;
}

BOOL CExplosion_1::LoadImage(){
	return CGameObject::LoadImage(m_Images, IDB_BITMAP9, RGB(0, 0, 0), 66, 66, 8);
}