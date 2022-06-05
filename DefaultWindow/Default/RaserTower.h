#pragma once
#include "HSObj.h"
class CRaserTower :
	public CHSObj
{
public:
	CRaserTower();
	virtual ~CRaserTower();

	void Create_Bullet(void);

	// CHSObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	DWORD m_LBullet;
	D3DXVECTOR3 m_vTarget;
	bool m_bBattle;
	int m_iShotDelay;
};

