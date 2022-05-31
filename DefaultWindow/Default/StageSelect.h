#pragma once
#include "Scene.h"
class CStageSelect :
	public CScene
{
public:
	CStageSelect();
	virtual ~CStageSelect();



	// CScene��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
private: // �ɹ��Լ�
	int NowRank(void); // ���� ����� �����ֱ����� �Լ�
	void Timer(void); //�ð��� ������ִ� �Լ�
	void Check_Goal(void); //�����ߴ��� üũ���ִ� �Լ�
private: // �ɹ� ����
	DWORD m_LTimer; // �ð��� ������� ����	
	int m_iNowRank; // �� ���� ���
	int m_iTotalRank; // ��ü īƮ�� ��
	int m_iSecond; // �ʸ� �����ϴ� ����
	int m_iGoal; //���� ���� ����
	bool m_bGoal; // ���� �ߴ��� üũ���ִ� ����

};

