#pragma once
#include "GHLine.h"

class CGHLineMgr
{
public:
	CGHLineMgr();
	~CGHLineMgr();
public:
	void		Initialize(void);
	void		Render(HDC hDC);
	void		Release(void);

	bool		Collision_Line(float& _fX, float* pY, CGHLine& _Line,int iIndex);
	void		Load_Line();

public:
	static		CGHLineMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CGHLineMgr;
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
	static CGHLineMgr*		m_pInstance;
	list<CGHLine*>			m_LineList;
	
};

