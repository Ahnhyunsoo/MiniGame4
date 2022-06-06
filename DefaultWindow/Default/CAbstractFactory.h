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

	static CObj* CreateObj(float _fX, float _fY)
	{
		CObj* _Temp = new T;
		_Temp->Initialize();
		_Temp->Set_vPos(_fX, _fY);
		return _Temp;
	}

	static CObj* CreateHRBlock(float _fX, float _fY, float _fCX, float _fCY)
	{
		CObj* _Temp = new T;
		_Temp->Initialize();
		dynamic_cast<CHRBlock*> (_Temp)->Set_Scale(_fCX, _fCY);
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

	static CObj* CreateBullet(D3DXVECTOR3 _Dir, float _fX, float _fY, DIRECTION Num)
	{
		CObj* _Temp = new T(_Dir,Num);
		_Temp->Initialize();
		_Temp->Set_vPos(_fX, _fY);
		return _Temp;
	}

	static CObj* CreateBullet(D3DXVECTOR3 _Dir, float _fX, float _fY, CObj* pObj)
	{
		CObj* _Temp = new T(_Dir,pObj);
		_Temp->Initialize();
		_Temp->Set_vPos(_fX, _fY);
		return _Temp;
	}

	static CObj* CreateGHFloar(int _iFloarType, bool _bFirst)
	{
		CObj* _Temp = new T;
		dynamic_cast<CGHFloar*> (_Temp)->Set_Floar(_iFloarType, _bFirst);
		_Temp->Initialize();		
		return _Temp;
	}

};