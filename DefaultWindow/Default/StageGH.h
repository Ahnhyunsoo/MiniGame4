#pragma once
#include "Scene.h"
class CStageGH : public CScene
{
public:
	CStageGH();
	virtual ~CStageGH();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
public:
	void	SetWarigari();
private:
	void	Create_Floar();
	void	Key_Input();
private:
	int		m_iRoutine;
	int		m_iRoutine1_Count;
	int		m_iFloarIndex;
	int		m_iRoutine0_Count;
private:
	bool	m_bFloarCreate;
	bool	m_bStart;
	bool	m_bMusicStart_Block;
	bool	m_bWarigari;
	DWORD	m_RoutineTime;
	DWORD	m_ScrollTime;
	DWORD	m_MusicTime;
private:
	GYULINE  m_Col_Left_RightLine[2];
	CObj*	m_WarigariFloar;

	GYULINE m_Rotation_Left_Right;
};

