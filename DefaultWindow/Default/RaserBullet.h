#pragma once
#include "HSObj.h"
class CRaserBullet :
	public CHSObj
{
public:
	CRaserBullet(D3DXVECTOR3 _DIR, CObj* pObj);
	virtual ~CRaserBullet();

	// CHSObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

	DWORD m_LTarget;
	DWORD m_LBulletSpon;
	D3DXVECTOR3 m_vTarget;
	CObj* m_pTower;
	bool m_bRaser;
};

