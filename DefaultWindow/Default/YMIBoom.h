#pragma once
#include "ObjYM.h"
class CYMIBoom :
	public CObjYM
{
public:
	CYMIBoom();
	virtual ~CYMIBoom();
	
public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;
};

