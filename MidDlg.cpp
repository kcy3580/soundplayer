// MidDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Music.h"
#include "MidDlg.h"
#include "afxdialogex.h"

#include "mmsystem.h"
static DWORD dwID_Mid;


// CMidDlg ��ȭ �����Դϴ�.

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


// CMidDlg �޽��� ó�����Դϴ�.


void CMidDlg::OnClickedButtonF()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// File��ư�� ������ ���Ͽ���â�� ���.
	OPENFILENAME ofFile_Mid;
	MCI_OPEN_PARMS ofOpen_Mid;
	MCIERROR ofErr;

	char lpstrFileName[MAX_PATH] = "";
	memset(&ofFile_Mid, 0, sizeof(OPENFILENAME));
	ofFile_Mid.lStructSize = sizeof(OPENFILENAME);
	ofFile_Mid.hwndOwner = m_hWnd;
	ofFile_Mid.lpstrFilter = _T("MID File\0*.mid");//MID���ϸ� �ߵ��� �Ѵ�.
	ofFile_Mid.lpstrFile = lpstrFileName;

	ofFile_Mid.nMaxFile = 256;
	ofFile_Mid.lpstrInitialDir = _T("C:\\");

	if (GetOpenFileName(&ofFile_Mid) == 0) //������ ������ ������ "Can't Open File" ������ ���.
	{
		MessageBox(_T("Can't Open File"), NULL, NULL);
	}
	else //�ƴ� ��� ���� ������ �Լ��� ����
	{
		ofOpen_Mid.lpstrDeviceType = _T("sequencer");
		ofOpen_Mid.lpstrElementName = ofFile_Mid.lpstrFile;
		ofErr = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&ofOpen_Mid);

		if (ofErr) //������ ���� ��, "Can't Open File" ������ ���.
		{
			MessageBox(_T("Can't Open File"), NULL, NULL);
		}
		else //�ƴ� ���, ���� m_strMM�� ������ ������ ��ϵȴ�.
		{
			m_strMM = ofFile_Mid.lpstrFile;
			UpdateData(FALSE);
			dwID_Mid = ofOpen_Mid.wDeviceID;
		}
	}
}


void CMidDlg::OnClickedButtonE2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MCI_GENERIC_PARMS genericExit;
	MCIERROR sErr;
	sErr = mciSendCommand(dwID_Mid, MCI_CLOSE, MCI_WAIT, (DWORD)&genericExit);//���������� ���� �����⸦ �ϸ� �ٷ� ���������� �׳� �����⸸ �� ��� "ERROR" ������ ���.
	if (sErr)
	{
		MessageBox(_T("ERROR"), NULL, NULL);
	}
	OnOK();
}


void CMidDlg::OnClickedButtonFs()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MCI_SEEK_PARMS sSeek;
	MCIERROR sErr;

	sSeek.dwTo = 0;

	sErr = mciSendCommand(dwID_Mid, MCI_SEEK, MCI_TO, (DWORD)&sSeek); //���������� �ٽ� ó���κ����� �����Ѵ�.
	if (sErr)
	{
		MessageBox(_T("ERROR"), NULL, NULL); //������ ���� ��� "ERROR" ������ ���.
	}
}


void CMidDlg::OnClickedButtonP()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MCI_PLAY_PARMS sPlay;
	MCIERROR sErr;

	sPlay.dwCallback = (DWORD)m_hWnd;
	sErr = mciSendCommand(dwID_Mid, MCI_PLAY, MCI_NOTIFY, (DWORD)&sPlay); //���������� ����Ѵ�.
	if (sErr)
	{
		MessageBox(_T("ERROR"), NULL, NULL); //������ ���� ��� "ERROR" ������ ���.
	}
}


void CMidDlg::OnClickedButtonPa()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MCI_GENERIC_PARMS genericPa;
	MCIERROR sErr;

	sErr = mciSendCommand(dwID_Mid, MCI_PAUSE, MCI_WAIT, (DWORD)&genericPa); //���������� �Ͻ����� �Ѵ�.
	if (sErr)
	{
		MessageBox(_T("PAUSE ERROR"), NULL, NULL); //������ ���� ��� "ERROR" ������ ���.
	}
}
