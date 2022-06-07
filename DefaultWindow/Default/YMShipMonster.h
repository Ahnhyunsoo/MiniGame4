#pragma once
#include "ObjYM.h"
class YMShipMonster :
	public CObjYM
{
public:
	YMShipMonster();
	virtual ~YMShipMonster();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
private:
	int m_iBulletCount;
	bool m_bBulletCount;
};

