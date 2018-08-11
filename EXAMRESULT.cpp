// EXAMRESULT.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "EXAMRESULT.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEXAMRESULT dialog


CEXAMRESULT::CEXAMRESULT(CWnd* pParent /*=NULL*/)
	: CDialog(CEXAMRESULT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEXAMRESULT)
	m_starttime = _T("");
	m_closetime = _T("");
	m_studentid = _T("");
	m_subject = _T("");
	m_totle = _T("");
	//}}AFX_DATA_INIT
}


void CEXAMRESULT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEXAMRESULT)
	DDX_Text(pDX, IDC_STATIC1, m_starttime);
	DDX_Text(pDX, IDC_STATIC2, m_closetime);
	DDX_Text(pDX, IDC_STATIC3, m_studentid);
	DDX_Text(pDX, IDC_STATIC4, m_subject);
	DDX_Text(pDX, IDC_STATIC5, m_totle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEXAMRESULT, CDialog)
	//{{AFX_MSG_MAP(CEXAMRESULT)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEXAMRESULT message handlers

BOOL CEXAMRESULT::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_AdoConn.OnIniADOConn();
	CString sql;
	sql.Format("select * from result where studentid=%d and subject='%s'",studentid,m_subject);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString starttime = (char*)(_bstr_t)m_pRs->GetCollect("starttime");
	CString closetime = (char*)(_bstr_t)m_pRs->GetCollect("closetime");
	CString subject = (char*)(_bstr_t)m_pRs->GetCollect("subject");
	int totle = m_pRs->GetCollect("totle").lVal;
	m_starttime.Format("开始时间：%s",starttime);
	m_closetime.Format("结束时间：%s",closetime);
	m_subject.Format("考试科目：%s",subject);
	m_studentid.Format("学生号：%d",studentid);
	m_totle.Format("考试分数：%d",totle);
	GetDlgItem(IDC_STATIC1)->SetWindowText(m_starttime);
	GetDlgItem(IDC_STATIC2)->SetWindowText(m_closetime);
	GetDlgItem(IDC_STATIC3)->SetWindowText(m_subject);
	GetDlgItem(IDC_STATIC4)->SetWindowText(m_studentid);
	GetDlgItem(IDC_STATIC5)->SetWindowText(m_totle);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
