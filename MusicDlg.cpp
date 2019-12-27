
// MusicDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Music.h"
#include "MusicDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "mmsystem.h"


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMusicDlg 대화 상자



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


// CMusicDlg 메시지 처리기

BOOL CMusicDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// 변수m_listM 리스트박스에 "도,레,미,파,솔,라,시,도"를 추가한다.

	m_listM.AddString(_T("도"));
	m_listM.AddString(_T("레"));
	m_listM.AddString(_T("미"));
	m_listM.AddString(_T("파"));
	m_listM.AddString(_T("솔"));
	m_listM.AddString(_T("라"));
	m_listM.AddString(_T("시"));
	m_listM.AddString(_T("도"));
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMusicDlg::OnPaint()
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
HCURSOR CMusicDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMusicDlg::OnSelchangeListM()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// m_listM에 있는 목록 중 하나를 선택하면 그 소리가 재생된다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 이어듣기를 눌렀을 때, 'IDR_WAVE1'~'IDR_WAVE8'까지 연속으로 재생된다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 나가기
	OnOK();
}


void CMusicDlg::OnClickedButtonM()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// MidDlg 클래스가 화면에 뜬다.
	m_MidDlg.DoModal();
}
