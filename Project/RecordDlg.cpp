// RecodDlg.cpp: 구현 파일
//
#include "pch.h"
#include "Project.h"
#include "RecordDlg.h"
#include "ProjectDlg.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

// RecodDlg 대화 상자

IMPLEMENT_DYNAMIC(RecordDlg, CDialogEx)

RecordDlg::RecordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent){
}

RecordDlg::~RecordDlg(){
}

void RecordDlg::DoDataExchange(CDataExchange* pDX){

	SetWindowText(_T("비밀번호 기록 페이지"));
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RecordDlg, CDialogEx)
	ON_BN_CLICKED(IDC_REC_BTN2, &RecordDlg::StopRec)
	ON_BN_CLICKED(IDC_REC_BTN, &RecordDlg::StartRec)
	ON_BN_CLICKED(IDC_RECOK_BTN, &RecordDlg::GoMain)
END_MESSAGE_MAP()


// RecodDlg 메시지 처리기

void RecordDlg::StartRec() {
	uflag = true;
}
void RecordDlg::StopRec() {
	uflag = false;
	p = i;
	for (int j = 1; j < i ; j++) {
		time[j - 1] = time[j];
	}
	
	for (int q = 0; q < i - 1; q++) {
		usertime[k][q] = time[q];
	}
	start = 0;
	finish = 0;
	i = 0;
	k++;
	}
void RecordDlg:: GoMain() {
	p -= 1;
	int i;
	ofstream fs;
	RegisterDlg m_RegisterDlg;
	string y = "0";
	fs.open("rec.txt", ios::in | ios::out | ios::app);
	for (i = 0; i < p; i++) {
		for (k = 0; k < 10; k++) {
			usersum[i] += usertime[k][i];
		}
		
		//fs << to_string(usersum[i]) + "\n";
	}
	for (k = 0; k < p; k++) {
		useravg[k] = usersum[k] / 10;
		
		//fs << to_string(useravg[k]) + "\n";
	}

	for (i = 0; i < p; i++) {
		for (k = 0; k < 10; k++) {
			userstd[i] += pow(usertime[k][i] - useravg[i], 2);
		}
		
		//fs << to_string(userstd[i]) + "\n";
	}
	fs << ",";
	for (i = 0; i < p; i++) {
		userstd[i] /= 10;
		userstd[i] = sqrt(userstd[i]);
		
		//fs << to_string(userstd[i]) + "\n";

		fs << to_string((int)(userstd[i])) + "," + to_string((int)(useravg[i])) + "," ;
		
	}

	fs << y;
	DestroyWindow();
}

BOOL RecordDlg::PreTranslateMessage(MSG* pMsg) {//다이어 로그에서 키보드 메시지 받기

	if (pMsg->message == WM_CHAR)
	{
		if (uflag) {
			if (flag) {
				start = clock();
				time[i] = start - finish;
				flag = false;
				i++;
			}
			else {
				finish = clock();
				time[i] = finish - start;
				flag = true;
				i++;
			}
		}
		else {
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}