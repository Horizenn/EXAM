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
	if(m_SubjectCombo.GetCurSel()==-1) //�ж��Ƿ���ѡ���Ŀ
	{
		AfxMessageBox("��ѡ���Ŀ");
		return;
	}
	m_SubjectCombo.GetLBText(m_SubjectCombo.GetCurSel(),str);  //��ȡѡ���ԵĿ�Ŀ	
	Subject = str;
	CString sql;
	m_AdoConn.OnIniADOConn();
	sql.Format("select subjectid from subject where subjectname='%s'",str);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql); //��ѯsubject���ж�Ӧѡ���Ŀ����Ϣ
	_variant_t vResultValue;
	vResultValue = m_pRs->GetCollect("subjectid");
	subjectid = vResultValue.lVal; //��ö�Ӧ��Ŀ��ID��
	sql.Format("select * from text where subjectid=%d",subjectid);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);  //��ѯtest���ж�Ӧ��Ŀ����Ϣ
	if(m_pRs->adoEOF!=0)  //�Ƿ��ж�Ӧ�Ŀ�Ŀ
	{
		AfxMessageBox("û�ж�Ӧ��Ŀ���Ծ�");
		return;
	}
	CString question =(char*)(_bstr_t)m_pRs->GetCollect("question"); 
	CString TestId =(char*)(_bstr_t)m_pRs->GetCollect("testid"); 

	//��ѯ��������Ƿ����д˿����˿�Ŀ�ĳɼ�
	sql.Format("select * from result where subject='%s' and studentid=%d",Subject,studentid);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF==0)
	{
		if(MessageBox("���Ѿ������˿�Ŀ���Ƿ�鿴�ɼ���","��ʾ",MB_YESNO)==IDYES)
		{
			CEXAMRESULT dlg;
			dlg.m_subject = Subject;
			dlg.studentid = studentid;
			dlg.DoModal();
		}
		return;
	}
	//ɾ��������Ϣ�Ĵ���е�����
	sql.Format("delete from examminginfo");
	m_AdoConn.ExecuteSQL((_bstr_t)sql);

	CTime time;
	time =CTime::GetCurrentTime();  //��ȡ��ǰϵͳʱ��
	CString TimeStr=time.Format("%m��%d��%H:%M");
	sql.Format("insert into result(starttime,subject,studentid)values('%s','%s',%d)",TimeStr,Subject,studentid);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	CExamInfo::OnCancel();
	CExamOnline *a = new CExamOnline();
	a->m_Test = question;
	a->m_TestID.Format("���:%s",TestId);
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
	m_AdoConn.OnIniADOConn();   //�����ݿ�
	CString sql = "select* from subject";   //��ѯ��Ŀ������Ϣ
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);   //��ȡ��Ŀ���¼
	while(m_pRs->adoEOF==0)     //�жϼ�¼�Ƿ�Ϊ��
	{
		CString subject=(char*)(_bstr_t)m_pRs->GetCollect("subjectname");   //��ȡ��Ŀ������Ϣ
		m_SubjectCombo.AddString(subject);   //����Ŀ������ӽ������б��
		m_pRs->MoveNext();    //��һ����¼
	}
	m_AdoConn.ExitConn();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
