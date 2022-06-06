#pragma once

#include "Include.h"

class CScrollMgr
{
private:
	CScrollMgr();
	~CScrollMgr();

public:
	int		Get_ScrollX(void) { return m_fScrollX; }
	int		Get_ScrollY(void) { return m_fScrollY; }

	void		Set_ScrollX(int _fX) { m_fScrollX += _fX; }
	void		Set_ScrollY(int _fY) { m_fScrollY += _fY; }

public:
	static		CScrollMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CScrollMgr;
		}

		return m_pInstance;
	}

	static	void	Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CScrollMgr*		m_pInstance;
	int					m_fScrollX = 0;
	int					m_fScrollY = 0;
};

