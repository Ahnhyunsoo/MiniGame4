#pragma once
#include "ObjYM.h"
class CYMTownMoster :
	public CObjYM
{
public:
	CYMTownMoster();
	virtual ~CYMTownMoster();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	int m_iSide;
	int m_iSideCount;
};

