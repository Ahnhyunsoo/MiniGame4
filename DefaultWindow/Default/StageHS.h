#pragma once
#include "Scene.h"
class CStageHS :
	public CScene
{
public:
	CStageHS();
	virtual ~CStageHS();

public:
	enum ObjType {STOPITEM,GUNTOWER,RASERTOWER,ICETOWER,ENDTOWER};
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
	ObjType Get_Tower() { return m_eTowerType; }
	void Set_Tower(ObjType _Type) { m_eTowerType = _Type; }
	bool Get_Stop() { return m_bStop; }
	void Set_Stop(bool _Stop) { m_bStop = _Stop; }
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
	bool m_bStop;
	bool m_bMonsterUpgrade;
	ObjType m_eTowerType;
	


};

