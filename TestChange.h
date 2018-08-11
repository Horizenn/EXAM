#if !defined(AFX_TESTCHANGE_H__048C9F2A_002D_4124_B448_A05E52FF49C6__INCLUDED_)
#define AFX_TESTCHANGE_H__048C9F2A_002D_4124_B448_A05E52FF49C6__INCLUDED_

#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestChange.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestChange dialog

class CTestChange : public CDialog
{
// Construction
public:
	int subjectid;
	int testid;
	CTestChange(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
// Dialog Data
	//{{AFX_DATA(CTestChange)
	enum { IDD = IDD_TESTCHANGE_DIALOG };
	CString	m_Question;
	CString	m_Answer;
	CString	m_AnswerA;
	CString	m_AnswerB;
	CString	m_AnswerC;
	CString	m_AnswerD;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestChange)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestChange)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCHANGE_H__048C9F2A_002D_4124_B448_A05E52FF49C6__INCLUDED_)
