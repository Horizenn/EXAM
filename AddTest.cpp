// AddTest.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "AddTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddTest dialog


CAddTest::CAddTest(CWnd* pParent /*=NULL*/)
	: CDialog(CAddTest::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddTest)
	m_Question = _T("");
	m_Answer = _T("");
	m_AnswerA = _T("");
	m_AnswerB = _T("");
	m_AnswerC = _T("");
	m_AnswerD = _T("");
	m_Totle = 0;
	//}}AFX_DATA_INIT
}


void CAddTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddTest)
	DDX_Text(pDX, IDC_EDIT1, m_Question);
	DDX_Text(pDX, IDC_EDIT2, m_Answer);
	DDX_Text(pDX, IDC_EDIT3, m_AnswerA);
	DDX_Text(pDX, IDC_EDIT4, m_AnswerB);
	DDX_Text(pDX, IDC_EDIT5, m_AnswerC);
	DDX_Text(pDX, IDC_EDIT6, m_AnswerD);
	DDX_Text(pDX, IDC_EDIT7, m_Totle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddTest, CDialog)
	//{{AFX_MSG_MAP(CAddTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddTest message handlers

void CAddTest::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_Question.IsEmpty())
	{
		AfxMessageBox("请输入问题");
		return;
	}
	if(m_Answer.IsEmpty())
	{
		AfxMessageBox("请输入答案");
		return;
	}
	if(m_AnswerA.IsEmpty())
	{
		AfxMessageBox("请输入选项A");
		return;
	}
	if(m_AnswerB.IsEmpty())
	{
		AfxMessageBox("请输入选项B");
		return;
	}
	if(m_AnswerC.IsEmpty())
	{
		AfxMessageBox("请输入选项C");
		return;
	}
	if(m_AnswerD.IsEmpty())
	{
		AfxMessageBox("请输入选项D");
		return;
	}
	if(m_Totle==0)
	{
		AfxMessageBox("分数不能为0");
		return;
	}
	CString sql;
	int testid;
	sql.Format("select * from text where subjectid=%d",subjectid);
	m_AdoConn.OnIniADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)
	{
		testid=1;
		sql.Format("insert into text values(%d,'%s','%s',%d,%d)",testid,m_Question,m_Answer,m_Totle,subjectid);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		sql.Format("insert into textanswer values(%d,'%s','%s','%s','%s',%d)",testid,m_AnswerA,m_AnswerB,m_AnswerC,m_AnswerD,subjectid);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	else
	{
		m_pRs->MoveLast();
		testid = m_pRs->GetCollect("testid").lVal+1;
		sql.Format("insert into text values(%d,'%s','%s',%d,%d)",testid,m_Question,m_Answer,m_Totle,subjectid);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		sql.Format("insert into textanswer values(%d,'%s','%s','%s','%s',%d)",testid,m_AnswerA,m_AnswerB,m_AnswerC,m_AnswerD,subjectid);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}
	m_AdoConn.ExitConn;
	CDialog::OnOK();
}
