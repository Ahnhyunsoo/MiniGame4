#include "stdafx.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "GHPlayer.h"
#include "Scene.h"
#include <iostream>

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{

}


CObjMgr::~CObjMgr()
{
}

void CObjMgr::Add_Object(OBJID eID, CObj * pObj)
{
	if (eID < OBJ_END && pObj != nullptr)
		m_ObjList[eID].push_back(pObj);
	else
		return;
}



void CObjMgr::Update()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();
			if (iResult == OBJ_DEAD)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
	cout << m_ObjList[OBJ_PLAYER].size() << endl;
}

void CObjMgr::Late_Update()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();

			if (m_ObjList[i].empty())
				break;
		}
	}

	Late_Update_ColCheck();
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hDC);
		}
	}

	CSceneMgr::Get_Instance()->Check_Reserve();
}

void CObjMgr::Release()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
			Safe_Delete<CObj*>(iter);

		m_ObjList[i].clear();
	}
}

void CObjMgr::Delete_ID(OBJID eID)
{
	for (auto& iter : m_ObjList[eID])
		Safe_Delete(iter);

	m_ObjList[eID].clear();
}


void CObjMgr::Late_Update_ColCheck()
{
	switch (CSceneMgr::Get_Instance()->Get_Scene())
	{
	case STAGE_SELECT:
		Late_UpdateSeclect();
		break;
	case STAGE_ST:
		Late_UpdateST();
		break;
	case STAGE_GH:
		Late_UpdateGH();
		break;
	case STAGE_YM:
		Late_UpdateYM();
		break;
	case STAGE_HS:
		Late_UpdateHS();
		break;
	case STAGE_HR:
		Late_UpdateHR();
		break;
	}
}

void CObjMgr::Late_UpdateSeclect()
{
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_MONSTER], true);
}
void CObjMgr::Late_UpdateST()
{
	if(!m_ObjList[OBJ_PLAYER].size() == 1|| !m_ObjList[OBJ_UI].empty())
		CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_UI], false);

}
void CObjMgr::Late_UpdateGH()
{
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_GYU_BUTTON], false);
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_GYU_BUTTON], m_ObjList[OBJ_GYU_FLOAR], false);
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_GYU_FLOAR], m_ObjList[OBJ_PLAYER], false); 
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_ITEM], m_ObjList[OBJ_PLAYER], false);
}
void CObjMgr::Late_UpdateYM()
{
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET], false);
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_BULLET], false);
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_BULLET], false);
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ITEM], false);
}
void CObjMgr::Late_UpdateHS()
{
	CCollisionMgr::Get_Instance()->Collision_RectEx(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET], false);
}
void CObjMgr::Late_UpdateHR()
{
	CCollisionMgr::Get_Instance()->Collision_HR_RectEx(m_ObjList[OBJ_HR_BLOCK], m_ObjList[OBJ_PLAYER], true);
	CCollisionMgr::Get_Instance()->Collision_HR_RectEx(m_ObjList[OBJ_HR_BLOCK], m_ObjList[OBJ_MONSTER], true);
								   
	CCollisionMgr::Get_Instance()->Collision_HR_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_MONSTER], true);
	CCollisionMgr::Get_Instance()->Collision_HR_RectEx(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_BULLET], false);
	CCollisionMgr::Get_Instance()->Collision_HR_RectEx(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET], false);
}
void CObjMgr::Late_UpdateEND()
{
}
