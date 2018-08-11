// ExamInfo.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "ExamInfo.h"
#include "ADOConn.h"
#include "ExamOnline.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamInfo dialog


CExamInfo::CExamInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CExamInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExamInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExamInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamInfo)
	DDX_Control(pDX, IDC_SUBJECTCOMBO, m_SubjectCombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamInfo, CDialog)
	//{{AFX_MSG_MAP(CExamInfo)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamInfo message handlers

void CExamInfo::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CExamInfo::OnCancel();
}

void CExamInfo::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	if(m_SubjectCombo.GetCurSel()==-1) //判断是否有选择科目
	{
		AfxMessageBox("请选择科目");
		return;
	}
	m_SubjectCombo.GetLBText(m_SubjectCombo.GetCurSel(),str);  //获取选择考试的科目	
	Subject = str;
	CString sql;
	m_AdoConn.OnIniADOConn();
	sql.Format("select subjectid from subject where subjectname='%s'",str);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql); //查询subject表中对应选择科目的信息
	_variant_t vResultValue;
	vResultValue = m_pRs->GetCollect("subjectid");
	subjectid = vResultValue.lVal; //获得对应科目的ID号
	sql.Format("select * from text where subjectid=%d",subjectid);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);  //查询test表中对应科目的信息
	if(m_pRs->adoEOF!=0)  //是否有对应的科目
	{
		AfxMessageBox("没有对应科目的试卷");
		return;
	}
	CString question =(char*)(_bstr_t)m_pRs->GetCollect("question"); 
	CString TestId =(char*)(_bstr_t)m_pRs->GetCollect("testid"); 

	//查询结果表中是否已有此考生此科目的成绩
	sql.Format("select * from result where subject='%s' and studentid=%d",Subject,studentid);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF==0)
	{
		if(MessageBox("你已经考过此科目，是否查看成绩？","提示",MB_YESNO)==IDYES)
		{
			CEXAMRESULT dlg;
			dlg.m_subject = Subject;
			dlg.studentid = studentid;
			dlg.DoModal();
		}
		return;
	}
	//删除考试信息寄存表中的数据
	sql.Format("delete from examminginfo");
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	CTime time;
	time =CTime::GetCurrentTime();  //获取当前系统时间
	CString TimeStr=time.Format("%m月%d日%H:%M");
	sql.Format("insert into result(starttime,subject,studentid)values('%s','%s',%d)",TimeStr,Subject,studentid);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	CExamInfo::OnCancel();
	CExamOnline *a = new CExamOnline();
	a->m_Test = question;
	a->m_TestID.Format("题号:%s",TestId);
	a->studentid = studentid;
	a->Subject = Subject;
	a->subjectid =subjectid;
	//a.m_TestID = TestId;
	//a->PutAnswer();
	a->DoModal();
	m_AdoConn.ExitConn();
}

BOOL CExamInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_AdoConn.OnIniADOConn();   //打开数据库
	CString sql = "select* from subject";   //查询科目表中信息
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);   //获取科目表记录
	while(m_pRs->adoEOF==0)     //判断记录是否为空
	{
		CString subject=(char*)(_bstr_t)m_pRs->GetCollect("subjectname");   //获取科目名称信息
		m_SubjectCombo.AddString(subject);   //将科目名称添加进下拉列表框
		m_pRs->MoveNext();    //下一条记录
	}
	m_AdoConn.ExitConn();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
