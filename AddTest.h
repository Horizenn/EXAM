#if !defined(AFX_ADDTEST_H__289CA871_1332_4AD8_B441_D0F5F37D5286__INCLUDED_)
#define AFX_ADDTEST_H__289CA871_1332_4AD8_B441_D0F5F37D5286__INCLUDED_

#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddTest dialog

class CAddTest : public CDialog
{
// Construction
public:
	int subjectid;
	CAddTest(CWnd* pParent = NULL);
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;// standard constructor

// Dialog Data
	//{{AFX_DATA(CAddTest)
	enum { IDD = IDD_ADDTEST_DIALOG };
	CString	m_Question;
	CString	m_Answer;
	CString	m_AnswerA;
	CString	m_AnswerB;
	CString	m_AnswerC;
	CString	m_AnswerD;
	int		m_Totle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddTest)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDTEST_H__289CA871_1332_4AD8_B441_D0F5F37D5286__INCLUDED_)
