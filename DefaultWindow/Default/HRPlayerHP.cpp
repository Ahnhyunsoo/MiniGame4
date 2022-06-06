#include "stdafx.h"
#include "HRPlayerHP.h"
#include "CAbstractFactory.h"

#include "KeyMgr.h"
#include "ObjMgr.h"
#include "HRSwing.h"
#include "CameraMgr.h"
#include "TimeMgr.h"
#include "HRBullet.h"

CHRPlayerHP::CHRPlayerHP()
{
}
CHRPlayerHP::~CHRPlayerHP()
{
}




void CHRPlayerHP::Initialize(void)
{
	m_tInfo.fCX = 55.f;
	m_tInfo.fCY = 55.f;
	m_fAngle = 0.f;
	m_fSpeed = 0.1f;
	m_fScale = 1.f;
	m_tInfo.vDir = { -1.f,0.f,0.f };
	m_bDead = false;
}
int CHRPlayerHP::Update(void)
{
	m_tInfo.vPos.x = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos.x;
	m_tInfo.vPos.y = CObjMgr::Get_Instance()->Get_Player()->Get_Info().vPos.y;

	return 0;
}
void CHRPlayerHP::Late_Update(void)
{

}
void CHRPlayerHP::Render(HDC hDC)
{
	
}
void CHRPlayerHP::Release(void)
{
}



void CHRPlayerHP::OnCollision(DIRECTION _DIR, CObj * _Other)
{
	CHRObj* temp = (CHRObj*)_Other;

	if (temp->Get_Tag() == "Bullet")
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_RBUTTON))
		{
			((CHRBullet*)temp)->SetPadding();
			((CHRBullet*)temp)->SetDefferDir();
			CCameraMgr::Get_Instance()->StartScale(temp);
			CCameraMgr::Get_Instance()->StartShake(10.f, 10.f, 200.f);

			return;
		}
	}
}
