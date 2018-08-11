#if !defined(AFX_TEXTGRADE_H__0103C2B4_9283_429E_8ED6_B6D98B693FED__INCLUDED_)
#define AFX_TEXTGRADE_H__0103C2B4_9283_429E_8ED6_B6D98B693FED__INCLUDED_

#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextGrade.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextGrade dialog

class CTextGrade : public CDialog
{
// Construction
public:
	CTextGrade(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
// Dialog Data
	//{{AFX_DATA(CTextGrade)
	enum { IDD = IDD_TEXTGRADE_DIALOG };
	int		m_studentid;
	CString	m_subject;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextGrade)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTextGrade)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTGRADE_H__0103C2B4_9283_429E_8ED6_B6D98B693FED__INCLUDED_)
