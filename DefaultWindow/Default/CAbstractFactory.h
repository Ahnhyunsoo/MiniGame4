#pragma once
#include "Obj.h"

template <typename T>
class CAbstractFactory
{
public:
	CAbstractFactory()
	{
	}

	~CAbstractFactory()
	{
	}

public:
	static CObj* Create()
	{
		CObj* _Temp = new T;
		_Temp->Initialize();
		return _Temp;
	}

	static CObj* CreateSelectMonster(float _fX, float _fY)
	{
		CObj* _Temp = new T;
		_Temp->Set_vPos(_fX, _fY);
		_Temp->Initialize();
		return _Temp;
	}
};