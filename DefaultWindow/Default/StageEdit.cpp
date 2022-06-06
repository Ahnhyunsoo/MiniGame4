#include "stdafx.h"
#include "StageEdit.h"
#include "LineMgr.h"

CStageEdit::CStageEdit()
{
}


CStageEdit::~CStageEdit()
{
	Release();
}

void CStageEdit::Initialize(void)
{
	CLineMgr::Get_Instance()->Initialize();
}

void CStageEdit::Update(void)
{
	CLineMgr::Get_Instance()->Update();
}

void CStageEdit::Late_Update(void)
{
	CLineMgr::Get_Instance()->Late_Update();
}

void CStageEdit::Render(HDC hDC)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	TCHAR mName2[30];

	/*wsprintf(mName2, TEXT("xÃà : %d, yÃà : %d"), pt.x, pt.y);
	TextOut(hDC, 500, 30, mName2, lstrlen(mName2));
	CLineMgr::Get_Instance()->Render(hDC);*/
}

void CStageEdit::Release(void)
{

	
}
