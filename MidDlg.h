#pragma once


// CMidDlg 대화 상자입니다.

class CMidDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMidDlg)

public:
	CMidDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMidDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMM;
	afx_msg void OnClickedButtonF();
	afx_msg void OnClickedButtonE2();
	afx_msg void OnClickedButtonFs();
	afx_msg void OnClickedButtonP();
	afx_msg void OnClickedButtonPa();
};
