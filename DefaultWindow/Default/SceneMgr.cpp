#include "stdafx.h"
#include "SceneMgr.h"
#include "StageST.h"
#include "StageHS.h"
#include "StageSelect.h"
#include "StageGH.h"
#include "StageYM.h"
#include "StageEdit.h"
#include "StageHR.h"
#include "SoundMgr.h"

CSceneMgr*	CSceneMgr::m_pInstance = nullptr;


CSceneMgr::CSceneMgr()
	: m_pScene(nullptr), m_eCurScene(STAGE_SELECT), m_eReserveScene(STAGE_END)
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
		case STAGE_EDIT:
			m_pScene = new CStageEdit;
			break;
		case STAGE_END:
			break;
		default:
			break;
		}
		m_pScene->Initialize();
		CScrollMgr::Get_Instance()->Scroll_Reset();
		m_ePreScene = m_eCurScene;
		m_eReserveScene = STAGE_END;
	}
}

void CSceneMgr::Check_Reserve()
{
	if (m_eReserveScene == STAGE_END)
		return;

	Scene_Change(m_eReserveScene);
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
	
	//CObjMgr::Get_Instance()->Release();
	Safe_Delete(m_pScene);
	
}








