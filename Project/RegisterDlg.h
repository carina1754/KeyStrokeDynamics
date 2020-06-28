#pragma once
#include"RecordDlg.h"
#pragma warning(disable : 4996)
// RegisterDlg 대화 상자

class RegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RegisterDlg)
public:
	RecordDlg *m_RecordDlg;
	RegisterDlg *m_RegisterDlg;
	RegisterDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~RegisterDlg();

	wchar_t id[64];// 입력한 id 변수
	wchar_t pw1[64];// 입력한 pw1 변수
	wchar_t pw2[64];// 입력한 pw2 변수
	int count = 1;//재입력비밀번호가 일치하는지 확인하는 변수
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void GoRecord();//비밀번호를 기록하는 다이얼로그로 넘어가는 버튼 이벤트 함수
	afx_msg void PWCheckBtn();// 두 비밀번호를 올바르게 입력했는지 확인하는 버튼 이벤트 함수
	afx_msg void GoRegister();//패스워드 및 기록을 했는지 체크하고 메인 다이얼로그로 넘어가는 버튼 이벤트 함수
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