#include "stdafx.h"
#include "CollisionMgr.h"

CCollisionMgr* CCollisionMgr::m_pInstance = nullptr;

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::Check_Rect(CObj * pDest, CObj * pSour, float * pX, float * pY)
{
	float fWidth = abs(pDest->Get_Info().vPos.x - pSour->Get_Info().vPos.x); 
	float fHeight = abs(pDest->Get_Info().vPos.y - pSour->Get_Info().vPos.y);

	float fCX = (pDest->Get_Info().fCX + pSour->Get_Info().fCX) * 0.5f; 
	float fCY = (pDest->Get_Info().fCY + pSour->Get_Info().fCY) * 0.5f; 

	if ((fCX > fWidth) && (fCY > fHeight)) 
	{
		*pX = fCX - fWidth;
		*pY = fCY - fHeight;

		return true; 
	}

	return false;
}


void CCollisionMgr::Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour, bool _bIsPush)
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			float    fX = 0.f, fY = 0.f;

			if (Check_Rect(Dest, Sour, &fX, &fY))
			{
				// 상하 충돌
				if (fX > fY)
				{
					// 상 충돌
					if (Dest->Get_Info().vPos.y > Sour->Get_Info().vPos.y)
					{
						if (_bIsPush) Sour->Set_vPosY(-fY);
						Dest->OnCollision(DIR_UP, Sour);
						Sour->OnCollision(DIR_UP, Dest);
					}

					else // 하 충돌
					{
						if (_bIsPush) Sour->Set_vPosY(fY);
						Dest->OnCollision(DIR_DOWN, Sour);
						Sour->OnCollision(DIR_DOWN, Dest);
					}
				}
				// 좌우 충돌
				else
				{
					// 좌 충돌
					if (Dest->Get_Info().vPos.x> Sour->Get_Info().vPos.y)
					{
						if (_bIsPush) Sour->Set_vPosX(-fX);
						Dest->OnCollision(DIR_LEFT, Sour);
						Sour->OnCollision(DIR_LEFT, Dest);
					}


					// 우 충돌
					else
					{
						if (_bIsPush) Sour->Set_vPosX(fX);
						Dest->OnCollision(DIR_RIGHT, Sour);
						Sour->OnCollision(DIR_RIGHT, Dest);
					}

				}
			}
		}
	}

}
