#pragma once


// CMidDlg ��ȭ �����Դϴ�.

class CMidDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMidDlg)

public:
	CMidDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMidDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMM;
	afx_msg void OnClickedButtonF();
	afx_msg void OnClickedButtonE2();
	afx_msg void OnClickedButtonFs();
	afx_msg void OnClickedButtonP();
	afx_msg void OnClickedButtonPa();
};
