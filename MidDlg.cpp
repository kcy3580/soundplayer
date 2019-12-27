// MidDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Music.h"
#include "MidDlg.h"
#include "afxdialogex.h"

#include "mmsystem.h"
static DWORD dwID_Mid;


// CMidDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMidDlg, CDialogEx)

CMidDlg::CMidDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strMM(_T(""))
{

}

CMidDlg::~CMidDlg()
{
}

void CMidDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_M_M, m_strMM);
}


BEGIN_MESSAGE_MAP(CMidDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_F, &CMidDlg::OnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_E2, &CMidDlg::OnClickedButtonE2)
	ON_BN_CLICKED(IDC_BUTTON_Fs, &CMidDlg::OnClickedButtonFs)
	ON_BN_CLICKED(IDC_BUTTON_P, &CMidDlg::OnClickedButtonP)
	ON_BN_CLICKED(IDC_BUTTON_Pa, &CMidDlg::OnClickedButtonPa)
END_MESSAGE_MAP()


// CMidDlg 메시지 처리기입니다.


void CMidDlg::OnClickedButtonF()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// File버튼을 누르면 파일오픈창이 뜬다.
	OPENFILENAME ofFile_Mid;
	MCI_OPEN_PARMS ofOpen_Mid;
	MCIERROR ofErr;

	char lpstrFileName[MAX_PATH] = "";
	memset(&ofFile_Mid, 0, sizeof(OPENFILENAME));
	ofFile_Mid.lStructSize = sizeof(OPENFILENAME);
	ofFile_Mid.hwndOwner = m_hWnd;
	ofFile_Mid.lpstrFilter = _T("MID File\0*.mid");//MID파일만 뜨도록 한다.
	ofFile_Mid.lpstrFile = lpstrFileName;

	ofFile_Mid.nMaxFile = 256;
	ofFile_Mid.lpstrInitialDir = _T("C:\\");

	if (GetOpenFileName(&ofFile_Mid) == 0) //오픈한 파일이 없으면 "Can't Open File" 문구가 뜬다.
	{
		MessageBox(_T("Can't Open File"), NULL, NULL);
	}
	else //아닐 경우 밑의 설정한 함수로 진행
	{
		ofOpen_Mid.lpstrDeviceType = _T("sequencer");
		ofOpen_Mid.lpstrElementName = ofFile_Mid.lpstrFile;
		ofErr = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&ofOpen_Mid);

		if (ofErr) //에러가 있을 시, "Can't Open File" 문구가 뜬다.
		{
			MessageBox(_T("Can't Open File"), NULL, NULL);
		}
		else //아닐 경우, 변수 m_strMM에 선택한 파일이 등록된다.
		{
			m_strMM = ofFile_Mid.lpstrFile;
			UpdateData(FALSE);
			dwID_Mid = ofOpen_Mid.wDeviceID;
		}
	}
}


void CMidDlg::OnClickedButtonE2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MCI_GENERIC_PARMS genericExit;
	MCIERROR sErr;
	sErr = mciSendCommand(dwID_Mid, MCI_CLOSE, MCI_WAIT, (DWORD)&genericExit);//음악파일을 열고 나가기를 하면 바로 나가지지만 그냥 나가기만 할 경우 "ERROR" 문구가 뜬다.
	if (sErr)
	{
		MessageBox(_T("ERROR"), NULL, NULL);
	}
	OnOK();
}


void CMidDlg::OnClickedButtonFs()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MCI_SEEK_PARMS sSeek;
	MCIERROR sErr;

	sSeek.dwTo = 0;

	sErr = mciSendCommand(dwID_Mid, MCI_SEEK, MCI_TO, (DWORD)&sSeek); //음악파일을 다시 처음부분으로 리셋한다.
	if (sErr)
	{
		MessageBox(_T("ERROR"), NULL, NULL); //파일이 없을 경우 "ERROR" 문구가 뜬다.
	}
}


void CMidDlg::OnClickedButtonP()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MCI_PLAY_PARMS sPlay;
	MCIERROR sErr;

	sPlay.dwCallback = (DWORD)m_hWnd;
	sErr = mciSendCommand(dwID_Mid, MCI_PLAY, MCI_NOTIFY, (DWORD)&sPlay); //음악파일을 재생한다.
	if (sErr)
	{
		MessageBox(_T("ERROR"), NULL, NULL); //파일이 없을 경우 "ERROR" 문구가 뜬다.
	}
}


void CMidDlg::OnClickedButtonPa()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MCI_GENERIC_PARMS genericPa;
	MCIERROR sErr;

	sErr = mciSendCommand(dwID_Mid, MCI_PAUSE, MCI_WAIT, (DWORD)&genericPa); //음악파일을 일시정지 한다.
	if (sErr)
	{
		MessageBox(_T("PAUSE ERROR"), NULL, NULL); //파일이 없을 경우 "ERROR" 문구가 뜬다.
	}
}
