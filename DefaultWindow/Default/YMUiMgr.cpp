#include "stdafx.h"
#include "YMUiMgr.h"
#include "CAbstractFactory.h"

CYMUiMgr* CYMUiMgr::m_pInstance = nullptr;

CYMUiMgr::CYMUiMgr()
{
}


CYMUiMgr::~CYMUiMgr()
{
	Release();
}

void CYMUiMgr::Initialize()
{
	CObj*	pUi = CAbstractFactory<CYMUi>::Create();
	m_listUi.push_back(pUi);
}

void CYMUiMgr::Update()
{
	for (auto& iter : m_listUi)
		iter->Update();
}

void CYMUiMgr::Late_Update()
{
	for (auto& iter : m_listUi)
		iter->Late_Update();
}

void CYMUiMgr::Render(HDC hDC)
{
	for (auto& iter : m_listUi)
		iter->Render(hDC);
}

void CYMUiMgr::Release()
{
	for_each(m_listUi.begin(), m_listUi.end(), CDeleteObj());
	m_listUi.clear();
}
