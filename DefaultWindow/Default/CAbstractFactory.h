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

	static CObj* CreateObj(float _fX, float _fY)
	{
		CObj* _Temp = new T;		
		_Temp->Initialize();
		_Temp->Set_vPos(_fX, _fY);
		return _Temp;
	}

	static CObj* CreateBullet(D3DXVECTOR3 _Dir, float _fX, float _fY)
	{
		CObj* _Temp = new T(_Dir);
		_Temp->Initialize();
		_Temp->Set_vPos(_fX, _fY);
		return _Temp;
	}
};