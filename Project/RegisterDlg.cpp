// RegisterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Project.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"
#include "ProjectDlg.h"
#include "RecordDlg.h"
using namespace std;

// RegisterDlg 대화 상자

IMPLEMENT_DYNAMIC(RegisterDlg, CDialogEx)

RegisterDlg::RegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent){
}

RegisterDlg::~RegisterDlg(){
}

void RegisterDlg::DoDataExchange(CDataExchange* pDX){
	SetWindowText(_T("회원가입 페이지"));
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(RegisterDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &RegisterDlg::PWCheckBtn)
	ON_BN_CLICKED(IDC_RES_BTN, &RegisterDlg::GoRegister)
	ON_BN_CLICKED(IDC_GOREC_BTN, &RegisterDlg::GoRecord)
END_MESSAGE_MAP()


// RegisterDlg 메시지 처리기
void RegisterDlg::PWCheckBtn() {
	// 유니코드 형식의 문자열을 저장하기 위한 변수

	// IDC_INPUT_STR_EDIT 컨트롤에서 최대 64길이의 문자열을
	// str 변수에 복사한다.
	GetDlgItemText(IDC_EDIT1, id, 64);
	GetDlgItemText(IDC_EDIT2, pw1, 64);
	GetDlgItemText(IDC_EDIT3, pw2, 64);
	for (int i = 0; i < 64; i++) {
		if (pw1[i] == pw2[i]) {
			continue;
		}
		else {
			count = 0;
			break;
		}
	}
	string a = TCHARToString(pw1), b = TCHARToString(pw2);

	if (a == "\0" || b == "\0") {
		MessageBox(_T("공백입니다"), _T("입력 오류"));
		count = 1;
	}
	else if (count == 1)
		MessageBox(_T("비밀번호가 일치합니다"), _T("패스워드 확인"));
	else {
		MessageBox(_T("다시 입력해 주세요"), _T("패스워드 확인"));
		count = 1;
	}
}
void RegisterDlg::GoRegister() {
	m_RegisterDlg = new RegisterDlg();
	m_RegisterDlg->Create(IDD_DIALOG1, this);
	if (count == 2) {
		ofstream fs;
		string a = TCHARToString(id), b = TCHARToString(pw2);
		fs.open("input.txt", ios::in | ios::out | ios::app);
		if (a == "\0" || b == "\0") {
			MessageBox(_T("공백입니다"), _T("입력 오류"));
		}
		else {
			a = a + "," + b + "," ;
			cout << a;
			fs << a;
			fs.close();
			DestroyWindow();
		}
	}
	else if (count == 1) {
		MessageBox(_T("패스워드 기록을 해주세요"), _T("인증 오류"));
	}
	else
		MessageBox(_T("패스워드를 확인해 주세요"), _T("인증 오류"));
}
void RegisterDlg::GoRecord() {
	count = 2;
	m_RecordDlg = new RecordDlg();
	m_RecordDlg->Create(IDD_DIALOG2, this);
	m_RecordDlg->ShowWindow(SW_SHOW);
}