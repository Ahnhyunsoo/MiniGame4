#pragma once
#include "Include.h"

class CGHScore
{
public:
	CGHScore();
	CGHScore(int _iNumber);
	~CGHScore();
public:
	void	Render(HDC hDC);
	void	Update(int _iNumber);
	void	Update_Score();
	void	Update_MatWorld();
public:
	void	Set_Scale(float _fScale) { m_fScale *= _fScale; }
private:
	int			m_iIndexCount;
private:
	int			m_iScore;
	float		m_fScale;
	INFO		m_tInfo;
	float		m_fAngle;
	D3DXVECTOR3 m_vVertex[9];
	D3DXVECTOR3 m_vOriVertex[9];
};

