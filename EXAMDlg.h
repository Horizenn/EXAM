// EXAMDlg.h : header file
//

#if !defined(AFX_EXAMDLG_H__8B74F417_B805_44A6_A8F2_D486CEF172F1__INCLUDED_)
#define AFX_EXAMDLG_H__8B74F417_B805_44A6_A8F2_D486CEF172F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEXAMDlg dialog

class CEXAMDlg : public CDialog
{
// Construction
public:
	int studentid;
	CEXAMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEXAMDlg)
	enum { IDD = IDD_EXAM_DIALOG };
	CComboBox	m_TypeList;
	CString	m_UserName;
	CString	m_UserPasswd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEXAMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEXAMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMDLG_H__8B74F417_B805_44A6_A8F2_D486CEF172F1__INCLUDED_)
