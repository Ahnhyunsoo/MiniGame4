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
private:
	void	Create_Floar();
	void	Key_Input();
private:
	int		m_iRoutine;
	int		m_iRoutine1_Count;
	int		m_iFloarIndex;
private:
	bool	m_bFloarCreate;
	bool	m_bStart;
	bool	m_bMusicStart_Block;
	DWORD	m_RoutineTime;
	DWORD	m_ScrollTime;
	DWORD	m_MusicTime;
};

