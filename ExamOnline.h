#if !defined(AFX_EXAMONLINE_H__A8A873CC_28D6_4B5A_ABAA_E1770364B2B8__INCLUDED_)
#define AFX_EXAMONLINE_H__A8A873CC_28D6_4B5A_ABAA_E1770364B2B8__INCLUDED_

#include "ADOConn.h"
#include "ExamInfo.h"
#include "EXAMRESULT.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExamOnline.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExamOnline dialog

class CExamOnline : public CDialog
{
// Construction
public:
	int subjectid;
	CString Subject;
	void CheckAnswer();
	int studentid;
	void SaveQuestion();
	CExamOnline(CWnd* pParent = NULL);   // standard constructor
	void PutAnswer();
// Dialog Data
	//{{AFX_DATA(CExamOnline)
	enum { IDD = IDD_EXAMONLINE };
	CString	m_Test;
	CString	m_TestID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamOnline)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExamOnline)
	afx_msg void OnAnswerB();
	afx_msg void OnAnswerC();
	afx_msg void OnAnswerA();
	afx_msg void OnAnswerD();
	afx_msg void OnLastOne();
	afx_msg void OnNextOne();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CExamOnline)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	int testnum;
	CString Answer;

	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMONLINE_H__A8A873CC_28D6_4B5A_ABAA_E1770364B2B8__INCLUDED_)
