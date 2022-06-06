#include "stdafx.h"
#include "HRObj.h"

#include "CameraMgr.h"

CHRObj::CHRObj()
	: m_bOnAir(false)
	, m_bJump(false)
	, m_bMove(false)
	, m_fJumpPower(0.f)
	, m_fValY(0.f)
	, m_fValX(0.f)
	, m_fRemitSpeed(0.f)
	, m_bRecord(false)
	, m_bRealDead(false)
{
	m_bDead = false;
}

CHRObj::~CHRObj()
{
}

void CHRObj::Initialize(void)
{
}

int CHRObj::Update(void)
{
	return 0;
}

void CHRObj::Late_Update(void)
{
}

void CHRObj::Render(HDC hDC)
{
}

void CHRObj::Release(void)
{
}

void CHRObj::Update_Gravity()
{
	m_vTempPos = m_tInfo.vPos;

	if (m_bJump)
	{
		m_vTempPos.y -= m_fJumpPower;
	}

	if (m_bOnAir)
	{
		m_fValY += 0.4f;
		m_vTempPos.y += m_fValY;
	}
	else
	{
		m_fValY = 0.f;
	}


	if (m_fValX > m_fRemitSpeed)
		m_fValX = m_fRemitSpeed;
	else if (m_fValX < -m_fRemitSpeed)
		m_fValX = -m_fRemitSpeed;

	m_vTempPos.x += m_fValX;

	if (!m_bMove && !m_bJump)
	{
		if (m_fValX > 1.f)
			m_fValX -= 0.1f;
		else if (m_fValX < -1.f)
			m_fValX += 0.1f;
		else
			m_fValX = 0.f;
	}

	m_bOnAir = true;


	m_vTempPos -= m_tInfo.vPos;

	// TODO: 중력 구현 가능
	// m_vTempPos *= CTimeMgr::Get_Instance()->Get_TimeValue();

	m_tInfo.vPos += m_vTempPos;
}

void CHRObj::Update_Record()
{
	m_vRecords.push_back(RECORD(m_tInfo.vPos.x, m_tInfo.vPos.y, m_bDead));
}
void CHRObj::Update_BackRecord()
{
	if (m_vRecords.size() == 0)
	{
		m_bRealDead = true;
		return;
	}

	m_tInfo.vPos = m_vRecords.back().m_vRecord;
	m_bDead = m_vRecords.back().m_bDead;
	m_vRecords.pop_back();

	if (m_vRecords.size() == 0)
	{
		m_bRealDead = true;
		return;
	}
	m_vRecords.pop_back();
}





void CHRObj::Render_Vertex(HDC hDC)
{
	int iScrollX = CCameraMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = CCameraMgr::Get_Instance()->Get_ScrollY();
	MoveToEx(hDC, (int)m_vVertex[0].x + iScrollX, (int)m_vVertex[0].y + iScrollY, nullptr);
	for (size_t i = 1; i < m_vVertex.size(); ++i)
	{
		LineTo(hDC, (int)m_vVertex[i].x + iScrollX, (int)m_vVertex[i].y + iScrollY);
	}
	LineTo(hDC, (int)m_vVertex[0].x + iScrollX, (int)m_vVertex[0].y + iScrollY);
}
