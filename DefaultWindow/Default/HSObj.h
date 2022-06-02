#pragma once
#include "Obj.h"
class CHSObj :
	public CObj
{
public:
	CHSObj();
	virtual ~CHSObj();

public:
	int Get_Damage() { return m_iDamage; }
	D3DXVECTOR3 Find_Target(float _fX, float _fY);

protected:
	int m_iDamage;
};

