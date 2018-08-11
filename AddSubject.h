#if !defined(AFX_ADDSUBJECT_H__E538D771_FD08_4560_869E_510E2CFF3104__INCLUDED_)
#define AFX_ADDSUBJECT_H__E538D771_FD08_4560_869E_510E2CFF3104__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSubject.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSubject dialog

class CAddSubject : public CDialog
{
// Construction
public:
	CAddSubject(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSubject)
	enum { IDD = IDD_ADDSUBJECT_DIALOG };
	CString	m_SubjectName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSubject)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSubject)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSUBJECT_H__E538D771_FD08_4560_869E_510E2CFF3104__INCLUDED_)
