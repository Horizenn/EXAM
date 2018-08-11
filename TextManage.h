#if !defined(AFX_TEXTMANAGE_H__B02CEB5B_4AD3_4FE5_856D_C2EDDF69F401__INCLUDED_)
#define AFX_TEXTMANAGE_H__B02CEB5B_4AD3_4FE5_856D_C2EDDF69F401__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextManage dialog

class CTextManage : public CDialog
{
// Construction
public:
	void AddToList(int Sid);
	void AddToTree();
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	CTextManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTextManage)
	enum { IDD = IDD_TEXTMANAGE };
	CTreeCtrl	m_TextTree;
	CListCtrl	m_TextList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTextManage)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTMANAGE_H__B02CEB5B_4AD3_4FE5_856D_C2EDDF69F401__INCLUDED_)
