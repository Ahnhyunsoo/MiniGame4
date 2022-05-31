#pragma once
#include "Scene.h"
class CStageSelect :
	public CScene
{
public:
	CStageSelect();
	virtual ~CStageSelect();



	// CScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
private: // 맴버함수
	int NowRank(void); // 현재 등수를 구해주기위한 함수
	void Timer(void); //시간을 기록해주는 함수
	void Check_Goal(void); //골인했는지 체크해주는 함수
private: // 맴버 변수
	DWORD m_LTimer; // 시간을 재기위한 변수	
	int m_iNowRank; // 내 현재 등수
	int m_iTotalRank; // 전체 카트의 수
	int m_iSecond; // 초를 저장하는 변수
	int m_iGoal; //골인 지점 변수
	bool m_bGoal; // 골인 했는지 체크해주는 변수

};

