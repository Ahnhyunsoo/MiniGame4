#pragma once
class CYMScoreMgr
{
public:
	CYMScoreMgr();
	~CYMScoreMgr();

	static CYMScoreMgr*& Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CYMScoreMgr;
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

	static int Get_Score()
	{
		return m_iScore;
	}

	static void Plus_Score(const int& _coin)
	{
		m_iScore += _coin;
	}

private:
	static CYMScoreMgr* m_pInstance;
	static int m_iScore;
};

