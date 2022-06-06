#pragma once

#include "Obj.h"

class CTimeMgr
{
private:
	CTimeMgr();
	~CTimeMgr();


#pragma region Ins
public:
	static		CTimeMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CTimeMgr;
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
	static CTimeMgr* m_pInstance;
#pragma endregion

public:
	float Get_TimeValue() { return m_fTimeValue; }
	float Get_DelaySecond() { return m_iDelayScond; }
	bool Get_Record() { return m_bRecord; }
	void Set_Record(bool _bValue) { m_bRecord = _bValue; }

public:
	void CalTimeUpdate();

public:
	void		Initialize(void);
	void		Update(void);

private:
	float m_fTimeValue;
	float m_fTempTimeValue;
	
	float m_dwTime;

	int m_iFPS;
	float m_iDelayScond;

	bool m_bRecord;
};
