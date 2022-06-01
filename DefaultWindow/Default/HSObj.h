#pragma once
#include "Obj.h"
class CHSObj :
	public CObj
{
public:
	CHSObj();
	virtual ~CHSObj();

public:
	void Draw_Triangle(HDC hDC);
	D3DXVECTOR3 Find_Target(float _fX, float _fY);
};

