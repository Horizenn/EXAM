// TestChange.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "TestChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestChange dialog


CTestChange::CTestChange(CWnd* pParent /*=NULL*/)
	: CDialog(CTestChange::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestChange)
	m_Question = _T("");
	m_Answer = _T("");
	m_AnswerA = _T("");
	m_AnswerB = _T("");
	m_AnswerC = _T("");
	m_AnswerD = _T("");
	//}}AFX_DATA_INIT
}


void CTestChange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestChange)
	DDX_Text(pDX, IDC_EDIT1, m_Question);
	DDX_Text(pDX, IDC_EDIT2, m_Answer);
	DDX_Text(pDX, IDC_EDIT3, m_AnswerA);
	DDX_Text(pDX, IDC_EDIT4, m_AnswerB);
	DDX_Text(pDX, IDC_EDIT5, m_AnswerC);
	DDX_Text(pDX, IDC_EDIT6, m_AnswerD);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestChange, CDialog)
	//{{AFX_MSG_MAP(CTestChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestChange message handlers

void CTestChange::OnOK() 
{
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
	// TODO: Add extra validation here
	CString sql;
	m_AdoConn.OnIniADOConn();
	sql.Format("update text set question='%s',rightanswer='%s' where testid=%d and subjectid=%d",m_Question,m_Answer,testid,subjectid);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	sql.Format("update textanswer set AnswerA='%s',AnswerB='%s',AnswerC='%s',AnswerD='%s' where testid=%d and subjectid=%d",m_AnswerA,m_AnswerB,m_AnswerC,m_AnswerD,testid,subjectid);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	CDialog::OnOK();
}
