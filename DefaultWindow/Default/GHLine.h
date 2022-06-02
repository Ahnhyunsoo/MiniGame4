#pragma once

#include "Include.h"

class CGHLine
{
public:
	CGHLine();
	CGHLine(GYULINE tLine);
	CGHLine(D3DXVECTOR3& tLeft, D3DXVECTOR3& tRight);
	~CGHLine();

public:
	const GYULINE & Get_Info(void) const { return m_tInfo; }

public:
	void	Render(HDC hDC);

private:
	GYULINE		m_tInfo;
};

