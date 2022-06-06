#pragma once

#include "HRObj.h"

class CHRBullet
	: public CHRObj
{
public:
	CHRBullet();
	~CHRBullet();

public:
	void SetDir(D3DXVECTOR3 _vDir) { m_tInfo.vDir = _vDir; }
	void SetDefferDir() { m_tInfo.vDir *= -1.f; }
	void SetPadding() { m_bPadding = true; }
	bool GetPadding() { return m_bPadding; }

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other);

private:
	float m_fLenth;

	float m_fDeadTime;
	float m_fOldDeadTime;

	bool m_bFirst;
	bool m_bPadding;
};