
// ProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Project.h"
#include "ProjectDlg.h"
#include "afxdialogex.h"
#include "RegisterDlg.h"
#include <cmath>
#include <iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;


// CProjectDlg 대화 상자a



CProjectDlg::CProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProjectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CProjectDlg::StopRec)
	ON_BN_CLICKED(IDC_BUTTON1, &CProjectDlg::StartRec)
	ON_BN_CLICKED(IDC_REGISTER_BTN, &CProjectDlg::GoRegister)
	ON_BN_CLICKED(IDC_LOGIN_BTN, &CProjectDlg::Gologin)

END_MESSAGE_MAP()


// CProjectDlg 메시지 처리기

BOOL CProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetWindowText(_T("2019253071-안정수 객체지향프로그래밍 과제"));
	

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProjectDlg::GoRegister() 
{
	m_RegisterDlg = new RegisterDlg();
	m_CProjectDlg = new CProjectDlg();
	m_RegisterDlg->Create(IDD_DIALOG1, this);
	m_RegisterDlg->ShowWindow(SW_SHOW);
}

void CProjectDlg::Gologin() //로그인 플래그 출력
{
	if (pflag) {
		MessageBox(_T("비밀번호가 일치합니다"), _T("패스워드 확인"));
	}
	else
	MessageBox(_T("패스워드를 다시 확인해 주세요"), _T("인증 오류"));
}

void CProjectDlg::StartRec() //키 레코딩 시작
{
	uflag = true;
}

void CProjectDlg::StopRec() //레코딩 종료와 동시에 저장된 유저 데이터 비교 후 플래그 출력
{
	uflag = false;
	fstream rs,ps;

	int useravg[100][100], userstp[100][100];
	p = 0, k = 0;
	int co=0, f = 0,q=0;
	string str_buf, recs[10000];
	rs.open("rec.txt", ios::in | ios::out | ios::app);
	ps.open("result.txt", ios::in | ios::out | ios::app);
	while (!rs.eof()) {
		getline(rs, str_buf, ',');
		recs[q] = str_buf;
		q++;
	}
	
	for (int i = 0; i < q; i++) {
		rec[i] = stoi(recs[i]);
	}

	int i = 0;
	while(f<=100){
		if (rec[i] == 0) {
			f++;
			p = 0;
			k = 0;
			i++;
		}
		else if (co % 2 == 0) {
			useravg[f][p] = rec[i];
			p++;
			i++;
		}
		else {
			userstp[f][k] = rec[i];
			k++;
			i++;
		}
		co++;
	}

	int count = 0;
	int k = 0;
	i = 0;
	GetDlgItemText(IDC_INPUT_ID, id, 64);
	GetDlgItemText(IDC_INPUT_PW, pw, 64);

	fstream fs;
	string ID[100], PW[100];
	string a = TCHARToString(id), b = TCHARToString(pw);
	fs.open("input.txt", ios::in);
	int j = 0;
	while (!fs.eof()) {
		getline(fs, str_buf, ',');
		if (k % 2 == 0) {
			ID[i] = str_buf;
			i++;
		}
		else {
			PW[j] = str_buf;
			j++;
		}
		k++;
	}
	p = j+1;
	ofstream ts;
	ts.open("rec.txt", ios::in | ios::out | ios::app);
	for (int j = 1; j < p + 1; j++) {
		maintime[j - 1] = maintime[j];
		ps << to_string(maintime[j-1]) + "\n";
	}
	
	for (int k = 0; k < 100; k++) {
		for (int i = 0; i < p; i++) {
			if (ID[k] == a && PW[k] == b) {
				if ((((maintime[i] - useravg[k][i]) / userstp[k][i]) >= -0.21 && 
					((maintime[i] - useravg[k][i]) / userstp[k][i]) <= 0.21)||
					(((maintime[i] - useravg[k][i]) / userstp[k][i]) >= 0.58 &&
						((maintime[i] - useravg[k][i]) / userstp[k][i]) <= 1.96)||
					(((maintime[i] - useravg[k][i]) / userstp[k][i]) >= -1.96 &&
							((maintime[i] - useravg[k][i]) / userstp[k][i]) <= -0.58)) {
					ps << to_string(useravg[k][i]) + "\n";
					ps << to_string(userstp[k][i]) + "\n";
					count++;
					ps << to_string(count) + "\n";
				}
				ps << to_string(((maintime[i] - useravg[k][i]) / userstp[k][i])) + "\n";
			}
			else
				continue;
		}
	}
	t = 0;
	ps << to_string(p) + "\n";
	if (count == p)
		pflag = true;
	else
		pflag = false;
	count = 0;
	j = 0;
	p = 0;
}

BOOL CProjectDlg::PreTranslateMessage(MSG* pMsg) //다이어 로그에서 키보드 메시지 받기
{

	if (pMsg->message == WM_CHAR)
	{
		if (uflag) {
			if (flag) {
				start = clock();
				maintime[t] = start - finish;
				flag = false;
				t++;
			}
			else {
				finish = clock();
				maintime[t] = finish - start;
				flag = true;
				t++;
			}
		}
		else {
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}