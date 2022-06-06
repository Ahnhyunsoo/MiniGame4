#include "stdafx.h"
#include "GHLine.h"


CGHLine::CGHLine() : m_tInfo()
{
}

CGHLine::CGHLine(GYULINE tLine)
	: m_tInfo(tLine)
{
}

CGHLine::CGHLine(D3DXVECTOR3 & tLeft, D3DXVECTOR3 & tRight) : m_tInfo(tLeft , tRight)
{
}


CGHLine::~CGHLine()
{
}

void CGHLine::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_tInfo.tLPoint.x, (int)m_tInfo.tLPoint.y, nullptr);
	LineTo(hDC, (int)m_tInfo.tRPoint.x , (int)m_tInfo.tRPoint.y);
}
