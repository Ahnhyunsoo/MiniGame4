#pragma once
#include "GHScore.h"

class CGHScoreMgr
{
public:
	CGHScoreMgr();
	~CGHScoreMgr();
public:
	void		Initialize(void);
	void		Update();
	void		Render(HDC hDC);
	void		Release(void);
public:
	void		Set_iScore() { ++m_iScore; }
	void		Set_Scale();
private:
	void		NewNumber();
private:
	int			m_iScore;
	bool		m_bScaleCount;
	DWORD		m_ScaleTime;
public:
	static		CGHScoreMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CGHScoreMgr;
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
	static CGHScoreMgr*		m_pInstance;
	vector<CGHScore*>			m_ScoreList;
};

