// EXAM.h : main header file for the EXAM application
//

#if !defined(AFX_EXAM_H__DED5AE71_B49A_4421_BB4A_8E7E23C62A1E__INCLUDED_)
#define AFX_EXAM_H__DED5AE71_B49A_4421_BB4A_8E7E23C62A1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEXAMApp:
// See EXAM.cpp for the implementation of this class
//

class CEXAMApp : public CWinApp
{
public:
	CEXAMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEXAMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEXAMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAM_H__DED5AE71_B49A_4421_BB4A_8E7E23C62A1E__INCLUDED_)
