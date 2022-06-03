#include "stdafx.h"
#include "HRObj.h"


CHRObj::CHRObj()
	: m_bOnAir(false)
	, m_bJump(false)
	, m_bMove(false)
	, m_fJumpPower(0.f)
	, m_fValY(0.f)
	, m_fValX(0.f)
	, m_fRemitSpeed(0.f)
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
	if (m_bJump)
	{
		m_tInfo.vPos.y -= m_fJumpPower;
	}

	if (m_bOnAir)
	{
		m_fValY += 0.4f;
		m_tInfo.vPos.y += m_fValY;
	}
	else
	{
		m_fValY = 0.f;
	}


	if (m_fValX > m_fRemitSpeed)
		m_fValX = m_fRemitSpeed;
	else if (m_fValX < -m_fRemitSpeed)
		m_fValX = -m_fRemitSpeed;

	m_tInfo.vPos.x += m_fValX;

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
}
