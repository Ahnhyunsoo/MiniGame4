#include "stdafx.h"
#include "TimeMgr.h"

#include "SceneMgr.h"
#include "ObjMgr.h"


CTimeMgr*	CTimeMgr::m_pInstance = nullptr;

CTimeMgr::CTimeMgr()
	: m_fTimeValue(10.f)
	, m_dwTime(0.f)
	, m_iFPS(0)
	, m_iDelayScond(0)
	, m_fTempTimeValue(0.f)
{
}
CTimeMgr::~CTimeMgr()
{
}



void CTimeMgr::Initialize(void)
{

}
void CTimeMgr::Update(void)
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SHIFT))
	{
		if (10.f > m_fTempTimeValue)
			m_fTempTimeValue += 0.02f;
		else
			m_fTempTimeValue = 10.f;
	}
	else
	{
		if (-10.f < m_fTempTimeValue)
			m_fTempTimeValue -= 0.02f;
		else
			m_fTempTimeValue = -10.f;
	}


	m_fTimeValue += m_fTempTimeValue;

	if (100.f < m_fTimeValue)
	{
		m_fTimeValue = 100.f;
		m_fTempTimeValue = 0.f;
	}
	else if (0.f > m_fTimeValue)
	{
		m_fTimeValue = 0.f;
		m_fTempTimeValue = 0.f;
	}

}


void CTimeMgr::CalTimeUpdate()
{
	++m_iFPS;
	if (m_dwTime + 1000.f < GetTickCount())
	{
		m_iDelayScond = 65 - m_iFPS;
		m_iDelayScond = m_iDelayScond * 12.f;

		if (0 > m_iDelayScond)
			m_iDelayScond = 0;

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}
}
