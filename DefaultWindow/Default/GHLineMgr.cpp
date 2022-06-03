#include "stdafx.h"
#include "GHLineMgr.h"

CGHLineMgr*		CGHLineMgr::m_pInstance = nullptr;

CGHLineMgr::CGHLineMgr()
{
}


CGHLineMgr::~CGHLineMgr()
{
	Release();
}

void CGHLineMgr::Initialize(void)
{
	Load_Line();

}

void CGHLineMgr::Render(HDC hDC)
{
	for (auto& iter : m_LineList)
		iter->Render(hDC);
}

void CGHLineMgr::Release(void)
{
	for_each(m_LineList.begin(), m_LineList.end(), CDeleteObj());
	m_LineList.clear();
}

bool CGHLineMgr::Collision_Line(float & _fX, float * pY,CGHLine& _Line,int iIndex)
{
	if (m_LineList.empty())
		return false;

	CGHLine*		pTarget = nullptr;
	for (auto& iter : m_LineList)
	{
		if (iIndex == 5)
		{
			if ((*iter).Get_Info().tLPoint.x == 525.f)
			{
				pTarget = iter;
				_Line = *iter;
				break;
			}
			else
				continue;
		}
		if (_fX >= iter->Get_Info().tLPoint.x &&
			_fX <= iter->Get_Info().tRPoint.x)
		{
			pTarget = iter;
			_Line = *iter;
			break;
		}
	}

	if (!pTarget)
		return false;

	float	x1 = pTarget->Get_Info().tLPoint.x;
	float	x2 = pTarget->Get_Info().tRPoint.x;

	float	y1 = pTarget->Get_Info().tLPoint.y;
	float	y2 = pTarget->Get_Info().tRPoint.y;

	*pY = (((y2 - y1) / (x2 - x1)) * (_fX - x1)) + y1;
	//_fX = (((x2 - x1) /(y2 - y1) ) * (y2 - y1)) + x1;
	// X = (Y - y1) * ((x2 - x1) / (y2 - y1)) + x1 

	return true;
}

void CGHLineMgr::Load_Line()
{
	// 275, 325, 375, 425, 475, 525
	// 66.5, 199.8, 333.1, 466.4, 599.7, 733.3
	for (int i = 0; i < 6; ++i) {
		if (i == 0) {
			GYULINE tInfo(D3DXVECTOR3(66.5f, WINCY, 0.f), D3DXVECTOR3(275.f, 0.f, 0.f));
			m_LineList.push_back(new CGHLine(tInfo));
			continue;
		}
		if (i == 1) {
			GYULINE tInfo( D3DXVECTOR3(199.8f, WINCY, 0.f), D3DXVECTOR3(325.f, 0.f, 0.f));
			m_LineList.push_back(new CGHLine(tInfo));
			continue;

		}
		if (i == 2) {
			GYULINE tInfo( D3DXVECTOR3(333.1f, WINCY, 0.f), D3DXVECTOR3(375.f, 0.f, 0.f) );
			m_LineList.push_back(new CGHLine(tInfo));
			continue;
		}
		if (i == 3) {
			GYULINE tInfo(  D3DXVECTOR3(425.f, 0.f, 0.f),D3DXVECTOR3(466.f, WINCY, 0.f));
			m_LineList.push_back(new CGHLine(tInfo));
			continue;
		}
		if (i == 4) {
			GYULINE tInfo(  D3DXVECTOR3(475.f, 0.f, 0.f), D3DXVECTOR3(599.7f, WINCY, 0.f));
			m_LineList.push_back(new CGHLine(tInfo));
			continue;
		}
		if (i == 5) {
			GYULINE tInfo(  D3DXVECTOR3(525.f, 0.f, 0.f),D3DXVECTOR3(733.f, WINCY, 0.f));
			m_LineList.push_back(new CGHLine(tInfo));
			continue;
		}
		
	}
	
}
