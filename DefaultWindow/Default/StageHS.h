#pragma once
#include "Scene.h"
class CStageHS :
	public CScene
{
public:
	CStageHS();
	virtual ~CStageHS();

public:
	void Draw_Rect(HDC hDC);
	void Draw_UI(HDC hDC);
	void CreateTower(void);
	POINT	pt{};
public:
	// CScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	static int g_iHP;
	static int g_iGold;
	static int g_iKill;
	static int g_iExp;
private:
	DWORD m_LSponMonster;
	RECT m_tTowerPos[19];
	int m_iMaxMonster;
	int m_iNowMonster;
	int m_iSponSpeed;
	int m_iMaxExp;
	int m_iLevel;
	int m_iRound;


};

