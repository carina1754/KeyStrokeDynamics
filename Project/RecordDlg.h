#pragma once

// RecodDlg 대화 상자
class RecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RecordDlg)

public:

	RecordDlg* m_RecordDlg;
	bool flag, uflag = false;//기록시작 종료 스위치, 기록 확인 변수
	clock_t start, finish ;//키입력 시작, 종료 변수
	int i = 0,k=0,p;//반복문 변수
	RecordDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~RecordDlg();
	double time[100], usertime[100][100], usersum[100], useravg[100], userstd[100];//사용자 keystroke값을 저장하기 위한 버퍼 변수, 유저들의 타임 버퍼 변수, 사용자의 keystroke값 합, 평균, 표준편차 값 변수
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void StartRec();//생성할 비밀번호의 기록을 시작하는 버튼 이벤트 함수
	afx_msg void StopRec();//생성할 비밀번호의 기록을 종료하는 버튼 이벤트 함수
	afx_msg void GoMain();//기록을 종료 후 rec파일에 입력하고 다시 회원가입 창으로 변경하는 버튼 이벤트 함수
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);//다이얼로그에서의 키이벤트 함수
};
