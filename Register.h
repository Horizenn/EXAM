#if !defined(AFX_REGISTER_H__49EFAED0_F4FD_4937_9FF5_41BAF03D6472__INCLUDED_)
#define AFX_REGISTER_H__49EFAED0_F4FD_4937_9FF5_41BAF03D6472__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Register.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog

class CRegister : public CDialog
{
// Construction
public:
	int radio;
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CRegister(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegister)
	enum { IDD = IDD_REGISTER };
	CStatic	m_Check;
	CString	m_UserName;
	CString	m_Passwd;
	CString	m_PasswdRepeat;
	CString	m_RealName;
	CString	m_IDcard;
	int		m_Age;
	CString	m_Phone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegister)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegister)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__49EFAED0_F4FD_4937_9FF5_41BAF03D6472__INCLUDED_)
