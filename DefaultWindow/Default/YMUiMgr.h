#pragma once
#include "YMUi.h"


class CYMUiMgr
{
public:
	CYMUiMgr();
	~CYMUiMgr();
public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();
	list<CObj*>	Get_Ui_List() { return m_listUi; }



public:
	static		CYMUiMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CYMUiMgr;
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
	static CYMUiMgr*			m_pInstance;
	list<CObj*>					m_listUi;
};