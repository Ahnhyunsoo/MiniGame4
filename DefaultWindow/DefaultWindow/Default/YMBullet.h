#pragma once
#include "ObjYM.h"
class CYMBullet :
	public CObjYM
{
public:
	CYMBullet(D3DXVECTOR3 _Dir);
	virtual ~CYMBullet();

	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual void OnCollision(DIRECTION _DIR, CObj * _Other) override;

private:
	int	m_iCount;
	int	m_iCountText;
	bool m_bText;
};