#pragma once

#include "Include.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

class CollisionMgr;
class CObjMgr;

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO&				Get_Info(void) const { return m_tInfo; }

	void Set_vPos(float fX, float fY) { m_tInfo.vPos.x = fX, m_tInfo.vPos.y = fY; }
	void Set_vPosX(float fX) { m_tInfo.vPos.x += fX; }
	void Set_vPosY(float fY) { m_tInfo.vPos.y += fY; }
	void Set_Dead(void) { m_bDead = true; }
	int Get_Hp() { return m_iHp; }
	void Set_Hp(int _Damage) { m_iHp -= _Damage; }
	const int& Get_Damage() { return m_iDamage; }
	void Set_Damage(int _Damage) { m_iDamage = _Damage; }

	vector<D3DXVECTOR3>& Get_VertexList() { return m_vVertex; }
	vector<D3DXVECTOR3>& Get_OriVertexList() { return m_vOriVertex; }

public:
	virtual		void	Initialize(void)	PURE;
	virtual		int		Update(void)		PURE;
	virtual		void	Late_Update(void)   PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;

public:
	virtual		void	OnCollision(DIRECTION _DIR, CObj* _Other) PURE;
	void ColRender(HDC hDC);
	void HR_ColRender(HDC hDC);

public:
	void Update_MatWorld(void);
	void Render_Vertex(HDC hDC);
	

protected:
	INFO		m_tInfo;
	float		m_fAngle;
	float		m_fSpeed;
	float		m_fScale;
	int			m_iHp;
	int			m_iDamage;
	bool		m_bDead;

protected:
	vector<D3DXVECTOR3> m_vVertex;
	vector<D3DXVECTOR3> m_vOriVertex;
	



};

