#pragma once
#include "Obj.h"
#include "CollisionMgr.h"

class CObjMgr
{
public:
	CObjMgr();
	~CObjMgr();

public: // �ɹ� �Լ�
	void Add_Object(OBJID eID, CObj* pObj); // ���ڷ� ���� ��ü�� Ÿ�Կ����� ����Ʈ�� �߰����ִ� �Լ�
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

public: // ���� �Լ�
	static CObjMgr* Get_Instance() // �ν��Ͻ� ������ ���´�.
	{
		if (!m_pInstance)
			m_pInstance = new CObjMgr;
		return m_pInstance;
	}

	static	void	Destroy_Instance(void) // �ν��Ͻ� ������ �����Ѵ�.
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}


private: // �ɹ� ����
	list<CObj*> m_ObjList[OBJ_END]; //CObj�� ��ӹ޴� ��ü���� �����ϴ� ����Ʈ
private: // ���� ����
	static CObjMgr* m_pInstance; // CObjMgr �ν��Ͻ�

};


