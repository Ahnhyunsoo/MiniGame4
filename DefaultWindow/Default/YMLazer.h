#pragma once
#include "ObjYM.h"
class CYMLazer :
	public CObjYM
{
public:
	CYMLazer(D3DXVECTOR3 _Dir);
	virtual ~CYMLazer();

	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	int	m_iCount;
};

