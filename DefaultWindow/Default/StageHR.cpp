#include "stdafx.h"
#include "StageHR.h"

#include "BmpMgr.h"
#include "ObjMgr.h"
#include "CAbstractFactory.h"
#include "HRPlayer.h"
#include "HRBlock.h"
#include "HRMonster.h"
#include "CameraMgr.h"
#include "TimeMgr.h"
#include "HRPlayerHP.h"


CStageHR::CStageHR()
	: m_dwOldTime(0.f)
{
}


CStageHR::~CStageHR()
{
	Release();
}

void CStageHR::Initialize(void)
{
	CObj* temp = CAbstractFactory<CHRPlayer>::CreateObj(-100.f, 400.f);
	CCameraMgr::Get_Instance()->Set_Target(temp);
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, temp);
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CHRPlayerHP>::CreateObj(-100.f, 400.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(400.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(600.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(1100.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(1200.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(1300.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CHRMonster>::CreateObj(1400.f, 300.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(300.f, WINCY, 10000.f, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(650.f, WINCY, 200.f, 600.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(300.f, 300.f, 100.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_HR_BLOCK, CAbstractFactory<CHRBlock>::CreateHRBlock(1200.f, 200.f, 300.f, 100.f));

}

void CStageHR::Update(void)
{
	float fDelayTime = CTimeMgr::Get_Instance()->Get_TimeValue();

	if (m_dwOldTime + fDelayTime <= GetTickCount())
	{
		CObjMgr::Get_Instance()->Update();
		CCameraMgr::Get_Instance()->Update();
		CTimeMgr::Get_Instance()->CalTimeUpdate();

		m_dwOldTime = GetTickCount();
	}
	
	CTimeMgr::Get_Instance()->Update();
}

void CStageHR::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStageHR::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(hDC);



	LOGFONT m_labelFontInfo{};
	m_labelFontInfo.lfCharSet = 129;
	m_labelFontInfo.lfHeight = 14;
	m_labelFontInfo.lfWidth = 6;
	m_labelFontInfo.lfWeight = FW_EXTRABOLD;
	HFONT textFont, oldFont;
	textFont = CreateFontIndirect(&m_labelFontInfo);
	oldFont = (HFONT)SelectObject(hDC, textFont);
	SetBkMode(hDC, TRANSPARENT);
	SetBkColor(hDC, RGB(0, 0, 0));

	SetTextColor(hDC, RGB(255, 0, 255));
	TCHAR mName[30];
	wsprintf(mName, TEXT("TimeValue: %d"), int(CTimeMgr::Get_Instance()->Get_TimeValue()));
	TextOut(hDC, 10, 30, mName, lstrlen(mName));

	wsprintf(mName, TEXT("DelayTime: %d"), int(CTimeMgr::Get_Instance()->Get_DelaySecond()));
	TextOut(hDC, 10, 60, mName, lstrlen(mName));

	if (CTimeMgr::Get_Instance()->Get_Record())
	{
		SetTextColor(hDC, RGB(0, 0, 0));
		wsprintf(mName, TEXT("¸Ó¾³..."));
		TextOut(hDC, 430, 220, mName, lstrlen(mName));
	}

	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(0, 0, 0));

	SelectObject(hDC, oldFont);
	DeleteObject(textFont);


}

void CStageHR::Release(void)
{
	CObjMgr::Get_Instance()->Release();
}
