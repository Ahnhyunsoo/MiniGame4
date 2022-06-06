#pragma once
#include "Obj.h"
class CHSObj :
	public CObj
{
public:
	CHSObj();
	virtual ~CHSObj();

public:

	D3DXVECTOR3 Find_Target(float _fX, float _fY);

protected:
	
};

