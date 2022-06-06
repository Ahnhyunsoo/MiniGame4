#include "stdafx.h"
#include "GHScoreMgr.h"
#include "SoundMgr.h"
CGHScoreMgr*		CGHScoreMgr::m_pInstance = nullptr;

CGHScoreMgr::CGHScoreMgr(): m_iScore(0), m_bScaleCount(false), m_ScaleTime(0)
{
}


CGHScoreMgr::~CGHScoreMgr()
{
	Release();

}

void CGHScoreMgr::Initialize(void)
{
	//CGHScore tInfo();
	m_ScoreList.push_back(new CGHScore());
}
void CGHScoreMgr::NewNumber()
{
	if ((m_iScore / 10 == 1) && (m_ScoreList.size() <= 1))
	{
		m_ScoreList.push_back(new CGHScore(0));
	}
	else if ((m_iScore / 100 == 1) && (m_ScoreList.size() <= 2))
	{
		
		CSoundMgr::Get_Instance()->PlaySound(L"GHWow.wav", SOUND_EFFECT, g_GHfSound);

		m_ScoreList.push_back(new CGHScore(1));
	}
}
void CGHScoreMgr::Set_Scale()
{
	if(m_ScaleTime == 0)
		m_ScaleTime = GetTickCount();

	if ((m_ScaleTime!= 0)&&(m_ScaleTime + 250 < GetTickCount())) {
		for (auto& iter : m_ScoreList)
		{
			if (!m_bScaleCount) 
				(*iter).Set_Scale(2);
			else 
				(*iter).Set_Scale(0.5);
		}
		if (!m_bScaleCount) 
			m_bScaleCount = true;
		else
			m_bScaleCount = false;

		m_ScaleTime = GetTickCount();
	}
}
void CGHScoreMgr::Update()
{
	NewNumber();
	int iHundred(0);
	int	iTen(0);
	int	iOne(0);
	if (1 == m_ScoreList.size()) {
		iOne = m_iScore;
		m_ScoreList[0]->Update(iOne);
	}
	else if (2 == m_ScoreList.size()) {
		iTen = m_iScore / 10;
		iOne = (m_iScore % 10);
		m_ScoreList[0]->Update(iOne);
		m_ScoreList[1]->Update(iTen);
	}
	else if (3 == m_ScoreList.size()) {
		iHundred = (m_iScore / 100);
		iTen = ((m_iScore % 100) / 10);
		iOne = ((m_iScore % 100) % 10);
		m_ScoreList[0]->Update(iOne);
		m_ScoreList[1]->Update(iTen);
		m_ScoreList[2]->Update(iHundred);
	}
	
}

void CGHScoreMgr::Render(HDC hDC)
{
	for (auto& iter : m_ScoreList)
		iter->Render(hDC);
	
}

void CGHScoreMgr::Release(void)
{
	for_each(m_ScoreList.begin(), m_ScoreList.end(), CDeleteObj());
	m_ScoreList.clear();
}
