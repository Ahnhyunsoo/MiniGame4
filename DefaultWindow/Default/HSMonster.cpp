#include "stdafx.h"
#include "HSMonster.h"


CHSMonster::CHSMonster()
	:m_LCollision(GetTickCount()), m_iDirNum(0)
{
}


CHSMonster::~CHSMonster()
{
}


void CHSMonster::Initialize(void)
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fAngle = 0.f;
	m_fSpeed = 2.5f;
	m_fScale = 1.f;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;
	m_iHp = 5;

	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 15.f, 15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, -15.f, 0.f });

	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, -15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -15.f, 0.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, 15.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 0.f, -15.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, -10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -10.f, 10.f, 0.f });

	ZeroMemory(m_vPt, sizeof(D3DXVECTOR3) * 15);
	m_vPt[0] = { 705.f,25.f,0.f };
	m_vPt[1] = { 705.f,425.f,0.f };
	m_vPt[2] = { 275.f,425.f,0.f };
	m_vPt[3] = { 275.f,125.f,0.f };
	m_vPt[4] = { 525.f,125.f,0.f };
	m_vPt[5] = { 525.f,295.f,0.f };
	m_vPt[6] = { 445.f,295.f,0.f };
	m_vPt[7] = { 445.f,205.f,0.f };
	m_vPt[8] = { 355.f,205.f,0.f };
	m_vPt[9] = { 355.f,365.f,0.f };
	m_vPt[10] = { 615.f,365.f,0.f };
	m_vPt[11] = { 615.f,25.f,0.f };
	m_vPt[12] = { 125.f,25.f,0.f };
	m_vPt[13] = { 125.f,425.f,0.f };
	m_vPt[14] = { 0.f,425.f,0.f };

}

int CHSMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_MatWorld();
	Move_Monster();
	return OBJ_NOEVENT;
}

void CHSMonster::Late_Update(void)
{
	if (m_vPt[m_iDirNum].x == m_tInfo.vPos.x && m_vPt[m_iDirNum].y == m_tInfo.vPos.y)
	{
		m_iDirNum += 1;
		switch (m_iDirNum)
		{
		case 1:
			m_fAngle -= 90.f;
			break;
		case 2:
			m_fAngle += 90.f;
			break;
		case 3:
			m_fAngle += 90.f;
			break;
		case 4:
			m_fAngle -= 90.f;
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;

		default:
			break;
		}
	}

}

void CHSMonster::Render(HDC hDC)
{
	Render_Vertex(hDC);
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	TCHAR mName2[30];

	wsprintf(mName2, TEXT("x√‡ : %d, y√‡ : %d"), pt.x, pt.y);
	TextOut(hDC, 500, 30, mName2, lstrlen(mName2));
}

void CHSMonster::Release(void)
{
}

void CHSMonster::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	if (m_LCollision + 300 < GetTickCount())
	{
		m_iHp -= _Other->Get_Damage();
		m_LCollision = GetTickCount();

	}

	if (m_iHp <= 0)
		Set_Dead();
}

void CHSMonster::Update_Dir()
{

}

void CHSMonster::Move_Monster()
{
	m_tInfo.vDir = m_vPt[m_iDirNum] - m_tInfo.vPos;
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
	m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;
}

