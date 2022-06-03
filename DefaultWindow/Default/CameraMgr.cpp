#include "stdafx.h"
#include "CameraMgr.h"

#include "SceneMgr.h"


CCameraMgr*	CCameraMgr::m_pInstance = nullptr;

CCameraMgr::CCameraMgr()
	: m_pTarget(nullptr)
	, m_fScrollX(0.f)
	, m_fScrollY(0.f)
	, m_bMoveX(false)
	, m_bMoveY(false)
	, m_bShake(false)
	, m_bShakeTemp(0.f)
	, m_fShakeTime(0.f)
	, m_fShakeOldTime(0.f)
	, m_fShakeValue(0.f)
	, m_bShakeTurn(false)
	, m_bScale(false)
{

}

CCameraMgr::~CCameraMgr()
{
}

void CCameraMgr::Initialize(void)
{
	// x, y축 제한

	if (!m_pTarget)
		return;

	//m_fScrollX = -m_pTarget->Get_Info().vPos.x + WINCX * 0.5f;
	//m_fScrollY = -m_pTarget->Get_Info().vPos.y + WINCY * 0.5f;

	//int		iOffSetX = WINCX >> 1;
	//int		iOffSetY = WINCY >> 1;
	//if (0.f >= m_pTarget->Get_Info().vPos.x - iOffSetX)
	//{
	//	m_fScrollX = -0;
	//}
	//else if (3000.f <= m_pTarget->Get_Info().vPos.x + iOffSetX)
	//{
	//	m_fScrollX = -3000.f + WINCX;
	//}
	//if (0.f >= m_pTarget->Get_Info().vPos.y - iOffSetY)
	//{
	//	m_fScrollY = -0.f;
	//}
	//else if (-900.f <= m_pTarget->Get_Info().vPos.y + iOffSetY)
	//{
	//	m_fScrollY = -900.f + WINCY;
	//}
}

void CCameraMgr::Update(void)
{
	if (m_bShake)
		Shake();
	if (m_bScale)
		Update_Scale();

	Nomal();
}

void CCameraMgr::Update_Scale(void)
{
	D3DXMATRIX		matScale;

	D3DXMatrixScaling(&matScale, m_fScaleValue, m_fScaleValue, 0.f);
/*
	for (size_t i = 0; i < m_vVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vVertex[i], &m_vOriVertex[i], &matScale);
	}*/
}

void CCameraMgr::StartShake(float _fShakeValue, float _fShakeSpeed, float _fTime, float _fATime)
{
	m_bShake = true;
	m_fShakeValue = _fShakeValue;

	m_bShakeTemp = 0.f;
	m_fShakeTime = _fTime;
	m_fShakeOldTime = GetTickCount64();

	m_fShakeSpeed = _fShakeSpeed;

	m_fATime = _fATime;
	m_fOldATime = GetTickCount64();
}

void CCameraMgr::Nomal()
{
	// target이 없다면 0, 0 고정
	if (!m_pTarget)
		return;

	//m_fScrollX = -m_pTarget->Get_Info().fX + WINCX * 0.5f;
	//m_fScrollY = -m_pTarget->Get_Info().fY + WINCY * 0.5f;

	int		iOffSetX = WINCX >> 1;
	int		iOffSetY = WINCY >> 1;
	int		iItvX = 200;
	int		iItvY = 100;

	if (iOffSetX - iItvX > m_pTarget->Get_Info().vPos.x + m_fScrollX)
	{
		m_bMoveX = true;
	}
	else if (iOffSetX + iItvX < m_pTarget->Get_Info().vPos.x + m_fScrollX)
	{
		m_bMoveX = true;
	}

	if (iOffSetY - iItvY > m_pTarget->Get_Info().vPos.y + m_fScrollY)
	{
		m_bMoveY = true;
	}
	else if (iOffSetY + iItvY < m_pTarget->Get_Info().vPos.y + m_fScrollY)
	{
		m_bMoveY = true;
	}

	if (m_bMoveX)
	{
		float disX = m_pTarget->Get_Info().vPos.x + m_fScrollX - iOffSetX;

		if (disX > 3.f)
		{
			if (disX > 200.f)
				m_fScrollX += -6.f;
			else
				m_fScrollX += -3.f;
		}
		else if (disX < -3.f)
		{
			if (disX < -200.f)
				m_fScrollX += 6.f;
			else
				m_fScrollX += 3.f;
		}
		else
			m_bMoveX = false;
	}
	if (m_bMoveY)
	{
		float disY = m_pTarget->Get_Info().vPos.y + m_fScrollY - iOffSetY;

		if (disY > 3.f)
		{
			if (disY > 200.f)
				m_fScrollY += -6.f;
			else
				m_fScrollY += -3.f;
		}
		else if (disY < -3.f)
		{
			if (disY < -200.f)
				m_fScrollY += 6.f;
			else
				m_fScrollY += 3.f;
		}
		else
			m_bMoveY = false;
	}



	//if (0.f >= m_pTarget->Get_Info().vPos.x - iOffSetX)
	//{
	//	m_fScrollX = -0;
	//}
	//else if (3000.f <= m_pTarget->Get_Info().vPos.x + iOffSetX)
	//{
	//	m_fScrollX = -3000.f + WINCX;
	//}
	//if (0.f >= m_pTarget->Get_Info().vPos.y - iOffSetY)
	//{
	//	m_fScrollY = -0.f;
	//}
	//else if (-900.f <= m_pTarget->Get_Info().vPos.y + iOffSetY)
	//{
	//	m_fScrollY = -900.f + WINCY;
	//}
}

void CCameraMgr::Shake()
{
	if (m_fOldATime + m_fATime < GetTickCount64())
	{
		if (m_fShakeOldTime + m_fShakeTime < GetTickCount64())
		{
			m_bShake = false;
			return;
		}

		if (m_bShakeTemp > m_fShakeValue)
		{
			m_bShakeTurn = false;
		}
		else if (m_bShakeTemp < -m_fShakeValue)
		{
			m_bShakeTurn = true;
		}

		if (m_bShakeTurn)
		{
			m_bShakeTemp += m_fShakeSpeed;
			m_fScrollX += 10.f;
			m_fScrollY += 10.f;
		}
		else
		{
			m_bShakeTemp -= m_fShakeSpeed;
			m_fScrollX -= 10.f;
			m_fScrollY -= 10.f;
		}
	}
	else
		m_fShakeOldTime = GetTickCount();

}

