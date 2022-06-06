#include "stdafx.h"
#include "CameraMgr.h"

#include "SceneMgr.h"
#include "ObjMgr.h"


CCameraMgr*	CCameraMgr::m_pInstance = nullptr;

CCameraMgr::CCameraMgr()
	: m_pTarget(nullptr)
	, m_pTempTarget(nullptr)
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
	, m_bScale(true)
	, m_fScaleValue(1.f)
	, m_fScaleTime(0.f)
	, m_fScaleOldTime(0.f)
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

	m_fScaleValue = 2.f;
	m_bScale = true;

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
		Update_Shake();
	if(m_bScale)
		Update_Scale();

	Update_Nomal();
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
void CCameraMgr::StartScale(CObj * _pTarget)
{
	// 1) 타겟을 바꾼다.
	Set_Target(_pTarget);

	m_bScale = true;

	m_fScaleValue = 1.f;
	m_fScaleTime = 2000.f;
	m_fScaleOldTime = GetTickCount64();
}








void CCameraMgr::Update_Nomal()
{
	// target이 없다면 0, 0 고정
	if (!m_pTarget)
		return;
	 
	//m_fScrollX = -m_pTarget->Get_Info().fX + WINCX * 0.5f;
	//m_fScrollY = -m_pTarget->Get_Info().fY + WINCY * 0.5f;

	int		iOffSetX = WINCX >> 1;
	int		iOffSetY = WINCY >> 1;
	int		iItvX = 100;
	int		iItvY = 50;

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
void CCameraMgr::Update_Shake()
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
void CCameraMgr::Update_Scale(void)
{
	if (m_fScaleOldTime + m_fScaleTime < GetTickCount())
	{
		m_bScale = false;
		Set_Target(m_pTempTarget);
		return;
	}

	if (m_fScaleValue < 3.f)
		m_fScaleValue += 0.1f;

	ScaleObj(OBJ_PLAYER);
	ScaleObj(OBJ_MONSTER);
	ScaleObj(OBJ_HR_BLOCK);
}






void CCameraMgr::ScaleObj(OBJID _eID)
{
	// TODO : 행렬 곱으로 최적화 필요

	// 1) 스케일 매트릭스를 만든다.
	D3DXMATRIX		matWorld, matScale, matBackTrans, matOriTrans;
	D3DXMatrixScaling(&matScale, m_fScaleValue, m_fScaleValue, 0.f);

	// 3) 타겟 vPos를 받아둔다.
	D3DXVECTOR3 vTargetPos = m_pTarget->Get_Info().vPos;

	// 4) vPos를 빼고 더하는 이동 행렬을 만든다.(빽 행렬, 오리 행렬)
	D3DXMatrixTranslation(&matBackTrans, -vTargetPos.x, -vTargetPos.y, 0.f);
	D3DXMatrixTranslation(&matOriTrans, vTargetPos.x, vTargetPos.y, 0.f);

	// 5) 모든 객체에 빽 행렬을 적용한다.
	list<CObj*>& ObjTemp = CObjMgr::Get_Instance()->Get_ObjList(_eID);

	for (list<CObj*>::iterator iter = ObjTemp.begin(); iter != ObjTemp.end(); ++iter)
	{
		vector<D3DXVECTOR3>& VerTemp = (*iter)->Get_VertexList();

		for (int i = 0; i < VerTemp.size(); ++i)
			D3DXVec3TransformCoord(&VerTemp[i], &VerTemp[i], &matBackTrans);
	}

	// 6) 모든 객체를 자신의 좌표에서 스케일링한다.
	for (list<CObj*>::iterator iter = ObjTemp.begin(); iter != ObjTemp.end(); ++iter)
	{
		vector<D3DXVECTOR3>& VerTemp = (*iter)->Get_VertexList();

		for (int i = 0; i < VerTemp.size(); ++i)
			D3DXVec3TransformCoord(&VerTemp[i], &VerTemp[i], &matScale);
	}

	// 7) 모든 객체에 오리 행렬을 적용한다.
	for (list<CObj*>::iterator iter = ObjTemp.begin(); iter != ObjTemp.end(); ++iter)
	{
		vector<D3DXVECTOR3>& VerTemp = (*iter)->Get_VertexList();

		for (int i = 0; i < VerTemp.size(); ++i)
			D3DXVec3TransformCoord(&VerTemp[i], &VerTemp[i], &matOriTrans);
	}
}