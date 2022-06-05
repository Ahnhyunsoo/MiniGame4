#include "stdafx.h"
#include "HSObj.h"
#include "ObjMgr.h"

CHSObj::CHSObj()
{
}


CHSObj::~CHSObj()
{
}



D3DXVECTOR3 CHSObj::Find_Target(float _fX, float _fY)
{
	D3DXVECTOR3 _Target = { 0.f,0.f,0.f };

	for (auto& iter : CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER))
	{
		//
		//sqrtf((_fX - iter->Get_Info().vPos.x * _fX - iter->Get_Info().vPos.x) + (_fY - iter->Get_Info().vPos.y * _fY - iter->Get_Info().vPos.y)
		if (abs(_fX - iter->Get_Info().vPos.x + _fY - iter->Get_Info().vPos.y)  < abs(_fX - _Target.x + _fY - _Target.y))
		{
			_Target = iter->Get_Info().vPos;
		}
	}
	return _Target;
}
