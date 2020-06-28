#include "RegisterDlg.h"
#include "RecordDlg.h"
#include "pch.h"
// ProjectDlg.h: 헤더 파일
//

#pragma once
#pragma warning(disable : 4996)
// CProjectDlg 대화 상자
class CProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	wchar_t id[64];// 입력한 id 변수
	wchar_t pw[64];// 입력한 pw 변수
	int rec[10000],userrec[100][100];//rec파일에서 불러온 데이터 저장 버퍼, 유저 keystorke값 저장 배열 변수
	double maintime[100];//입력한 사용자의 keystorke값 변수
	int t=0,p=0,k=0;//반복문 변수
	clock_t start, finish;//키입력 시작, 종료 변수
	bool flag=false, uflag=false,pflag=false;//키 입력을 번갈아가면서 maintime에 저장하기 위한 flag 변수, 기록 시작 종료 flag 변수, 로그인 확인 flag 변수
	CProjectDlg* m_CProjectDlg;
	RegisterDlg *m_RegisterDlg;
	RecordDlg* m_RecordDlg;
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void GoRegister(); //회원가입 다이얼로그로 넘어가는 버튼 이벤트 함수
	afx_msg void Gologin(); // StopRec 함수에서 받아온 pflag 변수를 통해서 로그인 여부 출력 함수
	afx_msg void StartRec();// 비밀번호 기록 시작 버튼 이벤트 함수
	afx_msg void StopRec(); //비밀번호 기록 종료 및 rec, input 파일을 불러오고 기록한 데이터와 비교하여 결과값을 result파일에 출력 및 pflag 값 변경 버튼 이벤트 함수
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);// 다이얼로그에서의 키이벤트 함수
	std::string TCHARToString(const TCHAR* ptsz)// TCHAR을 String으로 변환하는 함수
	{
		int len = wcslen((wchar_t*)ptsz);
		char* psz = new char[2 * len + 1];
		wcstombs(psz, (wchar_t*)ptsz, 2 * len + 1);
		std::string s = psz;
		delete[] psz;
		return s;
	}

};
