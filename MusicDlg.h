
// MusicDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "MidDlg.h"


// CMusicDlg ��ȭ ����
class CMusicDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMusicDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	CMidDlg m_MidDlg;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUSIC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listM;
	afx_msg void OnSelchangeListM();
	afx_msg void OnClickedButtonA();
	afx_msg void OnClickedButtonE();
	afx_msg void OnClickedButtonM();
};
