#pragma once

#include "HRObj.h"

class CSwing
	: public CHRObj
{
public:
	CSwing();
	~CSwing();

public:
	void SetDir(D3DXVECTOR3 _vDir) { m_tInfo.vDir = _vDir; }

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

};