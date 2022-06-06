#pragma once
#include "ObjYM.h"
class CYMBoom :
	public CObjYM
{
public:
	CYMBoom(D3DXVECTOR3 _Dir);
	virtual ~CYMBoom();
public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
};

