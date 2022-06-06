#include "stdafx.h"
#include "STStageName.h"


CSTStageName::CSTStageName()
{
}


CSTStageName::~CSTStageName()
{
}

void CSTStageName::Initialize(void)
{

	m_tInfo.vPos = { 0.f,300.f,0.f };
	
	m_fAngle = 0.f;
	m_fSpeed = 6.f;
	m_fScale = 30.f;
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_bDead = false;
	
	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, -1.f, 0.f	});
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, -1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 2.f, 1.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -2.f, 1.f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -2.f, -1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, -1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 2.f, 1.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -2.f, 1.f, 0.f });
}

int CSTStageName::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	Update_MatWorld();
	m_tInfo.fCX = abs(m_vVertex[0].x - m_vVertex[1].x);
	m_tInfo.fCY = abs(m_vVertex[1].y - m_vVertex[2].y);

	return OBJ_NOEVENT;

}
void CSTStageName::Render_Name(HDC hdc)
{
	LOGFONT m_labelFontInfo{};
	m_labelFontInfo.lfHeight = m_tInfo.fCX/2;
	m_labelFontInfo.lfWidth = m_tInfo.fCY/2;
	HFONT textFont, oldFont;
	textFont = CreateFontIndirect(&m_labelFontInfo);
	oldFont = (HFONT)SelectObject(hdc, textFont);
	SetBkMode(hdc, OPAQUE);
	SetBkColor(hdc, RGB(255, 255, 255));
	SetTextColor(hdc, RGB(0, 0, 0));;
	TCHAR cRank[30];
	//wsprintf(cRank, TEXT("±ÔÇö"));
	//TextOut(hdc, m_tInfo.vPos.x - (m_tInfo.fCX/2), m_tInfo.vPos.y - (m_tInfo.fCY / 2), cRank, lstrlen(cRank));



	if (m_iIndexNum == 0)
	{//±ÔÇö
		wsprintf(cRank, TEXT("±ÔÇö"));

	}
	else if (m_iIndexNum == 1)
	{//À¯¹Î
		wsprintf(cRank, TEXT("À¯¹Î"));

	}
	else if (m_iIndexNum == 2)
	{//Çö¼ö
		wsprintf(cRank, TEXT("Çö¼ö"));

	}
	else if (m_iIndexNum == 3)
	{//¿µ¿õ
		wsprintf(cRank, TEXT("¿µ¿õ"));

	}
	TextOut(hdc, m_tInfo.vPos.x - (m_tInfo.fCX / 2), m_tInfo.vPos.y - (m_tInfo.fCY / 2), cRank, lstrlen(cRank));

}
void CSTStageName::Late_Update(void)
{
}

void CSTStageName::Render(HDC hDC)
{
	Render_Vertex(hDC);
	ColRender(hDC);
	Render_Name(hDC);
}

void CSTStageName::Release(void)
{
}

void CSTStageName::OnCollision(DIRECTION _DIR, CObj * _Other)
{
}

void CSTStageName::Set_Name(int _iNum)
{
	m_iIndexNum = _iNum;
}
