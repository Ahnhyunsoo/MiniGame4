#pragma once
#include "ObjYM.h"
class CYMMonsterBullet :
	public CObjYM
{
public:
	CYMMonsterBullet(D3DXVECTOR3 _Dir);
	virtual ~CYMMonsterBullet();

	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
};

