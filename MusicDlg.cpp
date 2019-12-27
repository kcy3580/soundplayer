
// MusicDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Music.h"
#include "MusicDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "mmsystem.h"


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMusicDlg ��ȭ ����



CMusicDlg::CMusicDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MUSIC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMusicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_M, m_listM);
}

BEGIN_MESSAGE_MAP(CMusicDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST_M, &CMusicDlg::OnSelchangeListM)
	ON_BN_CLICKED(IDC_BUTTON_A, &CMusicDlg::OnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_E, &CMusicDlg::OnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_M, &CMusicDlg::OnClickedButtonM)
END_MESSAGE_MAP()


// CMusicDlg �޽��� ó����

BOOL CMusicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// ����m_listM ����Ʈ�ڽ��� "��,��,��,��,��,��,��,��"�� �߰��Ѵ�.

	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	m_listM.AddString(_T("��"));
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMusicDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMusicDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMusicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMusicDlg::OnSelchangeListM()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// m_listM�� �ִ� ��� �� �ϳ��� �����ϸ� �� �Ҹ��� ����ȴ�.
	int a = 0;

	a = m_listM.GetCurSel();
	switch (a)
	{
	case 0:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 1:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE2), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 2:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE3), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 3:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE4), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 4:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE5), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 5:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE6), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 6:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE7), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	case 7:
		PlaySound(MAKEINTRESOURCE(IDR_WAVE8), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		break;
	}
}


void CMusicDlg::OnClickedButtonA()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// �̾��⸦ ������ ��, 'IDR_WAVE1'~'IDR_WAVE8'���� �������� ����ȴ�.
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE3), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE4), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE5), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE6), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE7), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE8), AfxGetInstanceHandle(), SND_RESOURCE | SND_SYNC);
}


void CMusicDlg::OnClickedButtonE()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������
	OnOK();
}


void CMusicDlg::OnClickedButtonM()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// MidDlg Ŭ������ ȭ�鿡 ���.
	m_MidDlg.DoModal();
}
