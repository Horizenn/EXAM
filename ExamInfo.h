#if !defined(AFX_EXAMINFO_H__9D885616_D827_404F_A539_17A8A2C73FAD__INCLUDED_)
#define AFX_EXAMINFO_H__9D885616_D827_404F_A539_17A8A2C73FAD__INCLUDED_
#include "ADOConn.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExamInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExamInfo dialog

class CExamInfo : public CDialog
{
// Construction
public:
	int subjectid;
	int studentid;
	CExamInfo(CWnd* pParent = NULL);   // standard constructor
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
// Dialog Data
	//{{AFX_DATA(CExamInfo)
	enum { IDD = IDD_EXAMINFO };
	CComboBox	m_SubjectCombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExamInfo)
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString Question;
	CString Subject;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMINFO_H__9D885616_D827_404F_A539_17A8A2C73FAD__INCLUDED_)
