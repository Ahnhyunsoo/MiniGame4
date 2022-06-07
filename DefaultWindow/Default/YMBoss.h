#pragma once
#include "ObjYM.h"
class CYMBoss :
	public CObjYM
{
public:
	CYMBoss();
	virtual ~CYMBoss();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	bool	m_bUi_Check;

	int m_iSide;
	int m_iSide2;
	int m_iSideCount;
	int m_iSideCount2;
};


