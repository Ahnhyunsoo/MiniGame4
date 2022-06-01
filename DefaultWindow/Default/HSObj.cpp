#include "stdafx.h"
#include "HSObj.h"
#include "ObjMgr.h"

CHSObj::CHSObj()
{
}


CHSObj::~CHSObj()
{
}

void CHSObj::Draw_Triangle(HDC hDC)
{
	MoveToEx(hDC, int(m_tInfo.vPos.x), int(m_tInfo.vPos.y - m_tInfo.fCY*0.5 +3), nullptr);
	LineTo(hDC, int(m_tInfo.vPos.x - m_tInfo.fCX*0.5 + 3), int(m_tInfo.vPos.y));
	LineTo(hDC, int(m_tInfo.vPos.x), int(m_tInfo.vPos.y + m_tInfo.fCY*0.5 - 3));
	LineTo(hDC, int(m_tInfo.vPos.x), int(m_tInfo.vPos.y-m_tInfo.fCY *0.5 + 3));
}

D3DXVECTOR3 CHSObj::Find_Target(float _fX, float _fY)
{
	D3DXVECTOR3 _Target = { 0.f,0.f,0.f };
	for (auto& iter : CObjMgr::Get_Instance()->Get_ObjList(OBJ_MONSTER))
	{
		if (_Target.x == 0 && _Target.y == 0)
			_Target = iter->Get_Info().vPos;
		//abs(((_fX - _Target.x) + (_fY - _Target.y))) > abs(((_fX - iter->Get_Info().vPos.x) + (_fY - iter->Get_Info().vPos.y)))
		else if(abs(_fX - iter->Get_Info().vPos.x + _fY - iter->Get_Info().vPos.y)  < abs(_fX - _Target.x + _fY - _Target.y))
		{
			_Target = iter->Get_Info().vPos;
		}	
	}
	return _Target;
}


	//iter->Get_Info().vPos.x <  _Target.x