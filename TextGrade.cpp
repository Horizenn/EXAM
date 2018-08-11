// TextGrade.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "TextGrade.h"
#include "EXAMRESULT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextGrade dialog


CTextGrade::CTextGrade(CWnd* pParent /*=NULL*/)
	: CDialog(CTextGrade::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextGrade)
	m_studentid = 0;
	m_subject = _T("");
	//}}AFX_DATA_INIT
}


void CTextGrade::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextGrade)
	DDX_Text(pDX, IDC_EDIT1, m_studentid);
	DDX_Text(pDX, IDC_EDIT2, m_subject);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTextGrade, CDialog)
	//{{AFX_MSG_MAP(CTextGrade)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextGrade message handlers

void CTextGrade::OnButton1() 
{
	UpdateData();
	// TODO: Add your control notification handler code here
	m_AdoConn.OnIniADOConn();
	CString sql;
	sql.Format("select * from result where studentid=%d and subject='%s'",m_studentid,m_subject);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)
	{
		AfxMessageBox("没有该学生ID的该门科目成绩，请检查！");
		return;
	}
	else
	{
		CEXAMRESULT dlg;
		dlg.studentid = m_studentid;
		dlg.m_subject = m_subject;
		dlg.DoModal();
	}
	m_AdoConn.ExitConn();
}

void CTextGrade::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CTextGrade::OnCancel();
}
