#include "stdafx.h"
#include "GHButton.h"
#include "GHScoreMgr.h"
#include "GHObj.h"
#include "GHFloar.h"
#include "SoundMgr.h"
CGHButton::CGHButton()
{
}


CGHButton::~CGHButton()
{
	Release();
}

void CGHButton::Initialize(void)
{
	m_eString = STRING_BUTTON;
	m_vOriVertex.push_back(D3DXVECTOR3{ -40.f	, -40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 40.f	, -40.f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ 66.65f	, 66.65f, 0.f });
	m_vOriVertex.push_back(D3DXVECTOR3{ -66.65f	, 66.65f, 0.f });

	m_vVertex.push_back(D3DXVECTOR3{ -40.f, -40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 40.f, -40.f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ 66.65f, 66.65f, 0.f });
	m_vVertex.push_back(D3DXVECTOR3{ -66.65f, 66.65f, 0.f });
	m_fSpeed = 1.f;
	m_fScale = 1.f;
	m_fAngle = 0.f;
	m_bDead = false;
	m_bPress = false;
	m_tInfo.vDir = { 1.f,1.f,1.f };
	m_tInfo.fCX = 133.3f;
	m_tInfo.fCY = 50.f;
	m_ScoreDelayTime = 0;
}

int CGHButton::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;
	/*m_tInfo.vPos += m_tInfo.vDir;*/


	Update_MatWorld();
	m_bPress = false;

	return OBJ_NOEVENT;
}

void CGHButton::Late_Update(void)
{
}

void CGHButton::Render(HDC hDC)
{
	if (m_bPress) {
		HPEN hpen;
		HPEN hpenOld;

		hpen = CreatePen(PS_SOLID, 3, RGB(235, 128, 22));   // 선 스타일, 굵기, 색상
		hpenOld = (HPEN)::SelectObject(hDC, (HGDIOBJ)hpen);   // 펜 선택

		Render_Vertex(hDC);

		hpen = (HPEN)SelectObject(hDC, hpenOld);   // 기존의 펜 다시 선택
		DeleteObject(hpen);   // 생성한 펜 삭제
	}

}

void CGHButton::Release(void)
{
}

void CGHButton::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	//Get_GHString
	if ((0 != dynamic_cast<CGHObj*>(_Other)->Get_GHString())) {
		if ((m_bPress) && (m_ScoreDelayTime + 10 <GetTickCount())) {
			//if((dynamic_cast<CGHFloar*>(_Other)->Get_FloarIndex()) == 6)

			CGHScoreMgr::Get_Instance()->Set_iScore();

			m_ScoreDelayTime = GetTickCount();
		}
		if (dynamic_cast<CGHFloar*>(_Other)->Get_First()) {
			CSoundMgr::Get_Instance()->PlaySound(L"GHUndertale.wav", SOUND_BGM, g_GHfSound);
			g_dwGHBGMStartTime = GetTickCount();
		}
		

		_Other->Set_Dead();
	}

}
