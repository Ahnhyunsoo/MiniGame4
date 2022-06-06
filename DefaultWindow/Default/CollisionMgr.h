#pragma once

#include "Obj.h"

class CCollisionMgr
{
private:
	CCollisionMgr();
	~CCollisionMgr();


public:
	static CCollisionMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CCollisionMgr;

		}

		return m_pInstance;
	}

	static void Delete_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	static bool Check_Rect(CObj* pDest, CObj* pSour, float *pX, float *pY);
	static void Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour, bool _IsPush);
	static void Collision_HR_RectEx(list<CObj*> _Dest, list<CObj*> _Sour, bool _IsPush);

private:
	static CCollisionMgr* m_pInstance;
};

