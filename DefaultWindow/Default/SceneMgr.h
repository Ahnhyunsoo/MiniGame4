#pragma once
#include "Include.h"

class CScene;

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

public:
	void		Scene_Change(SCENE eID);
	void		Scene_Reserve(SCENE eID) { m_eReserveScene = eID; }
	void		Check_Reserve();


	void		Update(void);
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

public:
	static		CSceneMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CSceneMgr;
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

	SCENE Get_Scene() { return m_eCurScene; }
	CScene* Get_PScene() { return m_pScene; }

private:
	static CSceneMgr*		m_pInstance;
	CScene*					m_pScene;
	SCENE					m_eCurScene;
	SCENE					m_ePreScene;

	SCENE					m_eReserveScene;

};

