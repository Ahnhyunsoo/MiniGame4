#include "stdafx.h"
#include "SceneMgr.h"
#include "StageST.h"
#include "StageHS.h"
#include "StageSelect.h"
#include "StageGH.h"
#include "StageYM.h"
#include "StageHR.h"


CSceneMgr*	CSceneMgr::m_pInstance = nullptr;


CSceneMgr::CSceneMgr()
	: m_pScene(nullptr), m_eCurScene(STAGE_SELECT)
{

}

CSceneMgr::~CSceneMgr()
{
	Release();
}

// FSM(finite state machine) : 유한 상태 기계, 자신이 취할 수 있는 유한한 개수의 상태

void CSceneMgr::Scene_Change(SCENE eID)
{
	m_eCurScene = eID;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case STAGE_SELECT:
			m_pScene = new CStageSelect;
			break;
		case STAGE_ST:
			m_pScene = new CStageST;
			break;
		case STAGE_GH:
			m_pScene = new CStageGH;
			break;
		case STAGE_YM:
			m_pScene = new CStageYM;
			break;
		case STAGE_HS:
			m_pScene = new CStageHS;
			break;
		case STAGE_HR:
			m_pScene = new CStageHR;
			break;
		case STAGE_END:
			break;
		default:
			break;
		}
		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}
}

void CSceneMgr::Update(void)
{
	m_pScene->Update();


}

void CSceneMgr::Late_Update(void)
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
	
	
}

void CSceneMgr::Release(void)
{
	Safe_Delete(m_pScene);
}








