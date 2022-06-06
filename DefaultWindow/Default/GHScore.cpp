#include "stdafx.h"
#include "GHScore.h"


CGHScore::CGHScore()
{//1ÀÇÀÚ¸®
	m_iScore = 0;
	m_fScale = 1.f;
	m_fAngle = 0.f;
	m_tInfo.vDir = { 0.f,0.f,0.f };
	m_tInfo.vPos = { float(WINCX / 2 + 30),100.f,0.f };
	m_iIndexCount = 9;
}

CGHScore::CGHScore(int _iNumber)
{
	m_iScore = 1;
	m_fScale = 1.f;
	m_fAngle = 0.f;
	m_tInfo.vDir = { 0.f,0.f,0.f };
	m_tInfo.vPos = { float((WINCX / 2) - (30 * _iNumber)),100.f,0.f };
	m_iIndexCount = 9;
}

CGHScore::~CGHScore()
{
}

void CGHScore::Update(int _iNumber)
{
	
	m_iScore = _iNumber;
	Update_Score();
	Update_MatWorld();
}

void CGHScore::Update_Score()
{
	if (m_iScore == 1)
	{
		m_vVertex[0] = { -10.f,-10.f, 0.f };
		m_vVertex[1] = { 0.f, -15.f, 0.f };
		m_vVertex[2] = { 0.f, -10.f, 0.f };
		m_vVertex[3] = { 0.f, -5.f,0.f };
		m_vVertex[4] = { 0.f, 0.f, 0.f };
		m_vVertex[5] = { 0.f, 10.f, 0.f };
		m_vVertex[6] = { 0.f, 15.f, 0.f };
		m_vVertex[7] = { -10.f,15.f,0.f };
		m_vVertex[8] = { 10.f,15.f,0.f };
	}
	else if (m_iScore == 2)
	{
		m_vVertex[0] = { -10.f,-10.f, 0.f };
		m_vVertex[1] = { -5.f, -12.5f, 0.f };
		m_vVertex[2] = { 0.f, -15.f, 0.f };
		m_vVertex[3] = { 5.f, -12.5f,0.f };
		m_vVertex[4] = { 10.f, -10.f, 0.f };
		m_vVertex[5] = { -10.f, 15.f, 0.f };
		m_vVertex[6] = { -7.5f, 15.f, 0.f };
		m_vVertex[7] = { -10.f, 15.f, 0.f };
		m_vVertex[8] = { 10.f, 15.f,0.f };
	}
	else if (m_iScore == 3)
	{
		m_vVertex[0] = { -10.f,-15.f, 0.f };
		m_vVertex[1] = { 10.f, -15.f, 0.f };
		m_vVertex[2] = { 10.f, 0.f, 0.f };
		m_vVertex[3] = { -10.f, 0.f,0.f };
		m_vVertex[4] = m_vVertex[2];
		m_vVertex[5] = { 10.f, 15.f, 0.f };
		m_vVertex[6] = { -10.f, 15.f, 0.f };
		m_vVertex[7] = { -10.f, 15.f, 0.f };
		m_vVertex[8] = { -10.f, 15.f, 0.f };
	}
	else if (m_iScore == 4)
	{
		m_vVertex[0] = { -8.f,-15.f, 0.f };
		m_vVertex[1] = { -10.f, 0.f, 0.f };
		m_vVertex[2] = { 8.f, 0.f, 0.f };
		m_vVertex[3] = { 8.f, -15.f,0.f };
		m_vVertex[4] = m_vVertex[2];
		m_vVertex[5] = { 10.f, 0.f,0.f };
		m_vVertex[6] = m_vVertex[2];
		m_vVertex[7] = { 8.f,15.f,0.f };
		m_vVertex[8] = { 8.f,15.f,0.f };
	}
	else if (m_iScore == 5)
	{
		m_vVertex[0] = { 10.f,-15.f, 0.f };
		m_vVertex[1] = { -10.f, -15.f, 0.f };
		m_vVertex[2] = { -10.f, 0.f, 0.f }; 
		m_vVertex[3] = { 6.f, 0.f,0.f };
		m_vVertex[4] = { 10.f,7.5f,0.f };
		m_vVertex[5] = { 6.f, 15.f,0.f };
		m_vVertex[6] = {-10.f,15.f,0.f};
		m_vVertex[7] = m_vVertex[6];
		m_vVertex[8] = m_vVertex[6];
	}
	else if (m_iScore == 6)
	{
		m_vVertex[0] = { 10.f,-15.f, 0.f };
		m_vVertex[1] = { -10.f, -15.f, 0.f };
		m_vVertex[2] = { -10.f, 0.f, 0.f };
		m_vVertex[3] = { 10.f, 0.f,0.f };
		m_vVertex[4] = { 10.f,15.f,0.f };
		m_vVertex[5] = { -10.f, 15.f,0.f };
		m_vVertex[6] = m_vVertex[2];
		m_vVertex[7] = m_vVertex[6];
		m_vVertex[8] = m_vVertex[6];
	}
	else if (m_iScore == 7)
	{
		m_vVertex[0] = { -10.f, 3.f, 0.f };
		m_vVertex[1] = { -10.f, -15.f, 0.f };
		m_vVertex[2] = { 10.f, -15.f, 0.f };
		m_vVertex[3] = { 10.f, 15.f,0.f };
		m_vVertex[4] = m_vVertex[3];
		m_vVertex[5] = m_vVertex[3];
		m_vVertex[6] = m_vVertex[3];
		m_vVertex[7] = m_vVertex[3];
		m_vVertex[8] = m_vVertex[3];
	}
	else if (m_iScore == 8)
	{
		m_vVertex[0] = { -10.f,-15.f, 0.f };
		m_vVertex[1] = { 10.f, -15.f, 0.f };
		m_vVertex[2] = { 10.f, 0.f, 0.f };
		m_vVertex[3] = { 10.f, 15.f, 0.f };
		m_vVertex[4] = { -10.f, 15.f, 0.f };
		m_vVertex[5] = { -10.f, 0.f, 0.f };
		m_vVertex[6] = m_vVertex[0];
		m_vVertex[7] = m_vVertex[5];
		m_vVertex[8] = m_vVertex[2];
	}
	else if (m_iScore == 9)
	{
		m_vVertex[0] = { 10.f,-15.f, 0.f };
		m_vVertex[1] = { -7.5f, -15.f, 0.f };
		m_vVertex[2] = { -10.f, -7.5f, 0.f };
		m_vVertex[3] = { -7.5f, -5.f, 0.f };
		m_vVertex[4] = { 7.f, -5.f, 0.f };
		m_vVertex[5] = m_vVertex[0];
		m_vVertex[6] = {10.f,15.f,0.f};
		m_vVertex[7] = m_vVertex[6];
		m_vVertex[8] = m_vVertex[6];
	}
	else if (m_iScore == 0)
	{
		
		m_vVertex[0] = { -10.f,-15.f, 0.f };
		m_vVertex[1] = { -10.f, 15.f, 0.f };
		m_vVertex[2] = { 10.f, 15.f, 0.f };
		m_vVertex[3] = { 10.f, -15.f, 0.f };
		m_vVertex[4] = m_vVertex[0];
		m_vVertex[5] = m_vVertex[4];
		m_vVertex[6] = m_vVertex[4];
		m_vVertex[7] = m_vVertex[4];
		m_vVertex[8] = m_vVertex[4];
		
	}
	for (int i = 0; i < m_iIndexCount; ++i)
		m_vOriVertex[i] = m_vVertex[i];
}

void CGHScore::Update_MatWorld()
{
	D3DXMATRIX		matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, m_fScale, m_fScale, 0.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (size_t i = 0; i < m_iIndexCount; ++i)
	{
		D3DXVec3TransformCoord(&m_vVertex[i], &m_vOriVertex[i], &m_tInfo.matWorld);
	}
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
}

void CGHScore::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vVertex[0].x, (int)m_vVertex[0].y, nullptr);
	for (int i = 0; i < m_iIndexCount; ++i)
	{
		LineTo(hDC, (int)m_vVertex[i].x , (int)m_vVertex[i].y);
	}
	//LineTo(hDC, (int)m_vVertex[0].x , (int)m_vVertex[0].y);
}

