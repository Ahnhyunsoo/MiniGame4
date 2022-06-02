#pragma once
#include "Obj.h"
#include "GHFloar.h"
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

	static CObj* CreateGHFloar(float _fX, float _fY, int _iFloarType)
	{
		CObj* _Temp = new T;
		_Temp->Set_vPos(_fX, _fY);
		dynamic_cast<CGHFloar*> (_Temp)->Set_Floar(_iFloarType);
		_Temp->Initialize();		
		return _Temp;
	}

};