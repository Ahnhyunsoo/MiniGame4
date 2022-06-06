#pragma once
#include "Obj.h"
#include "CollisionMgr.h"

class CObjMgr
{
public:
	CObjMgr();
	~CObjMgr();

public: // 맴버 함수
	void Add_Object(OBJID eID, CObj* pObj); // 인자로 받은 객체의 타입에따라 리스트에 추가해주는 함수
	void Update();
	void Late_Update();
	void Render(HDC hDC);
	void Release();


	list<CObj*>& Get_ObjList(OBJID _ID) { return m_ObjList[_ID]; }
	CObj* Get_Player() { return m_ObjList[OBJ_PLAYER].front(); }

	void Delete_ID(OBJID eID);

private:
	void Late_Update_ColCheck();

	void Late_UpdateSeclect();
	void Late_UpdateST();
	void Late_UpdateGH();
	void Late_UpdateYM();
	void Late_UpdateHS();
	void Late_UpdateHR();
	void Late_UpdateEND();

public: // 전역 함수
	static CObjMgr* Get_Instance() // 인스턴스 정보를 얻어온다.
	{
		if (!m_pInstance)
			m_pInstance = new CObjMgr;
		return m_pInstance;
	}

	static	void	Destroy_Instance(void) // 인스턴스 정보를 삭제한다.
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}


private: // 맴버 변수
	list<CObj*> m_ObjList[OBJ_END]; //CObj를 상속받는 객체들을 저장하는 리스트
private: // 전역 변수
	static CObjMgr* m_pInstance; // CObjMgr 인스턴스

};


