#pragma once
#include "HSObj.h"
class CGunTower :
	public CHSObj
{
public:
	CGunTower();
	virtual ~CGunTower();
public:
	void Create_Bullet(void);
public:
	// CHSObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
public:
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;



private:
	DWORD m_LBullet;
	D3DXVECTOR3 m_vTarget;
	bool m_bBattle;
};

