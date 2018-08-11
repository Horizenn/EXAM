// ExamOnline.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "ExamOnline.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExamOnline dialog


CExamOnline::CExamOnline(CWnd* pParent /*=NULL*/)
	: CDialog(CExamOnline::IDD, pParent)
{
	EnableAutomation();
	//{{AFX_DATA_INIT(CExamOnline)
	m_Test = _T("");
	m_TestID = _T("");
	//}}AFX_DATA_INIT
}


void CExamOnline::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CExamOnline::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamOnline)
	DDX_Text(pDX, IDC_STATIC1, m_Test);
	DDX_Text(pDX, IDC_STATIC2, m_TestID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExamOnline, CDialog)
	//{{AFX_MSG_MAP(CExamOnline)
	ON_BN_CLICKED(IDC_RADIO_B, OnAnswerB)
	ON_BN_CLICKED(IDC_RADIO_C, OnAnswerC)
	ON_BN_CLICKED(IDC_RADIO_A, OnAnswerA)
	ON_BN_CLICKED(IDC_RADIO_D, OnAnswerD)
	ON_BN_CLICKED(IDC_BUTTON1, OnLastOne)
	ON_BN_CLICKED(IDC_BUTTON4, OnNextOne)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CExamOnline, CDialog)
	//{{AFX_DISPATCH_MAP(CExamOnline)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IExamOnline to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {BCD61429-9441-4076-A073-73272B7CFF69}
static const IID IID_IExamOnline =
{ 0xbcd61429, 0x9441, 0x4076, { 0xa0, 0x73, 0x73, 0x27, 0x2b, 0x7c, 0xff, 0x69 } };

BEGIN_INTERFACE_MAP(CExamOnline, CDialog)
	INTERFACE_PART(CExamOnline, IID_IExamOnline, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamOnline message handlers

void CExamOnline::OnAnswerA() 
{
	// TODO: Add your control notification handler code here
	Answer = 'A';
}

void CExamOnline::OnAnswerB() 
{
	// TODO: Add your control notification handler code here
	Answer = 'B';
}

void CExamOnline::OnAnswerC() 
{
	// TODO: Add your control notification handler code here
	Answer = 'C';
}

void CExamOnline::OnAnswerD() 
{
	// TODO: Add your control notification handler code here
	Answer = 'D';
}

void CExamOnline::OnLastOne() 
{
	// TODO: Add your control notification handler code here
	UpdateData();   //获取当前对话框最新信息
	//为单选控件添加变量
	CButton* m_checkA=(CButton*)GetDlgItem(IDC_RADIO_A);
	CButton* m_checkB=(CButton*)GetDlgItem(IDC_RADIO_B);
	CButton* m_checkC=(CButton*)GetDlgItem(IDC_RADIO_C);
	CButton* m_checkD=(CButton*)GetDlgItem(IDC_RADIO_D);
	if(testnum==1)   //如果当前题号为1
	{
		AfxMessageBox("这已经是第一题了");   //提示错误信息
		return;
	}
	CString question;
	CString Id;
	CString answer;
	CString sql;
	question = m_Test;
	m_AdoConn.OnIniADOConn();

	sql.Format("select * from examminginfo where testnum=%d",testnum);  
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	//answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");

	if(m_checkA->GetCheck()==BST_CHECKED)
		Answer = 'A';
	if(m_checkB->GetCheck()==BST_CHECKED)
		Answer = 'B';
	if(m_checkC->GetCheck()==BST_CHECKED)
		Answer = 'C';
	if(m_checkD->GetCheck()==BST_CHECKED)
		Answer = 'D';

	if(m_pRs->adoEOF)
	{	
		if(Answer!='e')
			SaveQuestion();
	}
	else
	{
	//修改答题信息暂存表中当前题号的试题答案
	//sql.Format("select * from examminginfo where testnum=%d",testnum);  
	//m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
	answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");  //获取当前题号试题答案
	if(answer!=Answer&&Answer!='e') //如果原有答案与当前答案不同，修改
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}

	testnum--;
	sql.Format("select * from examminginfo where testnum=%d",testnum);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	question=(char*)(_bstr_t)m_pRs->GetCollect("question");
	answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
	m_TestID.Format("题号:%d",testnum);
	m_Test = question;
	GetDlgItem(IDC_STATIC1)->SetWindowText(m_Test);
	GetDlgItem(IDC_STATIC2)->SetWindowText(m_TestID);
	PutAnswer();
	if(answer=='A')
	{
		m_checkA->SetCheck(true);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);
	}
	if(answer=='B')
	{
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(true);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);
	}
	if(answer=='C')
	{
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(true);
		m_checkD->SetCheck(false);
	}
	if(answer=='D')
	{
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(true);
	}	
}

void CExamOnline::OnNextOne() 
{
	// TODO: Add your control notification handler code here
	//SaveQuestion();
	//CheckAnswer();
	UpdateData();
	//为4个单选控件分别添加一个变量
	CButton* m_checkA=(CButton*)GetDlgItem(IDC_RADIO_A);
	CButton* m_checkB=(CButton*)GetDlgItem(IDC_RADIO_B);
	CButton* m_checkC=(CButton*)GetDlgItem(IDC_RADIO_C);
	CButton* m_checkD=(CButton*)GetDlgItem(IDC_RADIO_D);
	CString sql;
	CString question,answer;
	question = m_Test;  //获取当前题目信息
	CString Id;
	Id.Format("题号:%d",testnum+1);
	m_AdoConn.OnIniADOConn();
	sql.Format("select * from text where question='%s'",question);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString testid=(char*)(_bstr_t)m_pRs->GetCollect("testid");
	//获取答题信息表中下一题信息
	sql.Format("select * from examminginfo where testnum=%d",testnum+1);  
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)  //如果下一题信息为空
	{
		sql.Format("select * from examminginfo where question='%s'",question);  
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)  //如果不存在下一题信息
		{
			if(Answer!='A'&&Answer!='B'&&Answer!='C'&&Answer!='D') //如果选项不是A,B,C,D
			{
				AfxMessageBox("请选择一个答案");  //提示错误信息
				return;
			}
			SaveQuestion();  //保存当前试题信息
		}
		//如果答题信息暂存表中存在下一题试题信息
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		//修改答题信息暂存表中当前题号的试题答案

		if(m_checkA->GetCheck()==BST_CHECKED)
			Answer = 'A';
		if(m_checkB->GetCheck()==BST_CHECKED)
			Answer = 'B';
		if(m_checkC->GetCheck()==BST_CHECKED)
			Answer = 'C';
		if(m_checkD->GetCheck()==BST_CHECKED)
			Answer = 'D';

		sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");  //获取当前题号试题答案
		if(answer!=Answer&&Answer!='e')    //如果原有答案与当前答案不同，修改
			m_AdoConn.ExecuteSQL((_bstr_t)sql);

		sql.Format("select * from text where question='%s'",question);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		_variant_t vResultValue;
		vResultValue = m_pRs->GetCollect("testid");
		int tid= vResultValue.lVal;
		int sid= m_pRs->GetCollect("subjectid").lVal;
		//int tid=atoi(testid);
		//查询试题信息表中比当前试题题号大的试题信息
		sql.Format("select * from text where subjectid=%d and testid>%d order by testid",sid,tid);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)  //如果记录为空
		{
			CheckAnswer();   //核对试题答案并分别对各题打分
			if(MessageBox("考试结束，是否交卷？","提示",MB_YESNO)==IDYES)
			{
				AfxMessageBox("交卷成功");
				CTime time;
				time =CTime::GetCurrentTime();  //获取当前系统时间
				CString TimeStr=time.Format("%m月%d日%H:%M");
				sql.Format("select SUM(totle) from examminginfo");
				m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
				int totle = m_pRs->GetCollect(_variant_t((long)0)).lVal;
				sql.Format("update result set closetime='%s',totle=%d where studentid=%d and subject='%s'",TimeStr,totle,studentid,Subject);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
				CExamOnline::OnCancel();
				CEXAMRESULT dlg;
				dlg.m_subject = Subject;
				dlg.studentid = studentid;
				dlg.DoModal();
			}
			else return;
		}
		else
		{
		//将4单选控件全部置初始状态
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);
		Answer='e';  //将Answer值初始化
		question=(char*)(_bstr_t)m_pRs->GetCollect("question");  //获取试题题目信息
		m_TestID = Id;  //修改题目号
		m_Test = question;  //修改试题信息
		GetDlgItem(IDC_STATIC1)->SetWindowText(m_Test);
		GetDlgItem(IDC_STATIC2)->SetWindowText(m_TestID);
		testnum++;
		PutAnswer();  //显示试题选项信息
		}
	}
	else  //如果下一题信息存在
	{
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		//更新答题信息暂存表中试题答案信息
		sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");

		if(m_checkA->GetCheck()==BST_CHECKED)
			Answer = 'A';
		if(m_checkB->GetCheck()==BST_CHECKED)
			Answer = 'B';
		if(m_checkC->GetCheck()==BST_CHECKED)
			Answer = 'C';
		if(m_checkD->GetCheck()==BST_CHECKED)
			Answer = 'D';

		if(answer!=Answer)
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		testnum++;  //试题ID加1
		sql.Format("select * from examminginfo where testnum=%d",testnum);  //查询下一题信息
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		question=(char*)(_bstr_t)m_pRs->GetCollect("question");  //获取试题题目信息
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");   //获取试题答案信息
		m_TestID  = Id;
		m_Test = question; 
		GetDlgItem(IDC_STATIC1)->SetWindowText(m_Test);
		GetDlgItem(IDC_STATIC2)->SetWindowText(m_TestID);
		PutAnswer();
		if(answer=='A')
		{
			m_checkA->SetCheck(true);
			m_checkB->SetCheck(false);
			m_checkC->SetCheck(false);
			m_checkD->SetCheck(false);
		}
		if(answer=='B')
		{
			m_checkA->SetCheck(false);
			m_checkB->SetCheck(true);
			m_checkC->SetCheck(false);
			m_checkD->SetCheck(false);
		}
		if(answer=='C')
		{
			m_checkA->SetCheck(false);
			m_checkB->SetCheck(false);
			m_checkC->SetCheck(true);
			m_checkD->SetCheck(false);
		}
		if(answer=='D')
		{
			m_checkA->SetCheck(false);
			m_checkB->SetCheck(false);
			m_checkC->SetCheck(false);
			m_checkD->SetCheck(true);
		}
	}
}


void CExamOnline::PutAnswer()
{
	UpdateData();   //获取窗体中当前信息
	CString question;
	question = m_Test;   //获取试题信息
	CString sql;
	sql.Format("select * from text where question='%s'",question);   //查询试题表中试题信息
	m_AdoConn.OnIniADOConn();  //打开数据库连接
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);   //获取记录
	_variant_t vResultValue;
	vResultValue = m_pRs->GetCollect("testid");
	testnum= vResultValue.lVal; //获得对应科目的ID号
	CString testid=(char*)(_bstr_t)m_pRs->GetCollect("testid");  //获取该试题的试题编号
	sql.Format("select * from textanswer where testid='%s' and subjectid=%d",testid,subjectid);   //查询选项表中该试题ID
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);  //获取记录
	CString A,B,C,D;
	A=(char*)(_bstr_t)m_pRs->GetCollect("AnswerA");   //获取A选项信息
	B=(char*)(_bstr_t)m_pRs->GetCollect("AnswerB");   //获取B选项信息
	C=(char*)(_bstr_t)m_pRs->GetCollect("AnswerC");   //获取C选项信息
	D=(char*)(_bstr_t)m_pRs->GetCollect("AnswerD");   //获取D选项信息
	GetDlgItem(IDC_RADIO_A)->SetWindowText("A   "+A);   //将A选项信息在单选控件中显示
	GetDlgItem(IDC_RADIO_B)->SetWindowText("B   "+B);   //将B选项信息在单选控件中显示
	GetDlgItem(IDC_RADIO_C)->SetWindowText("C   "+C);   //将C选项信息在单选控件中显示
	GetDlgItem(IDC_RADIO_D)->SetWindowText("D   "+D);	//将D选项信息在单选控件中显示
	m_AdoConn.ExitConn();   //关闭数据库连接
}


BOOL CExamOnline::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CExamOnline::PutAnswer();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExamOnline::SaveQuestion()
{
	UpdateData();
	CString question;
	question = m_Test;
	CString sql;
	sql.Format("insert into examminginfo(testnum,question,answer,studentid)values(%d, '%s', '%s', %d)",testnum,
				question,Answer,studentid);
	m_AdoConn.OnIniADOConn();
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
}

void CExamOnline::CheckAnswer()
{
	CString sql;
	sql.Format("select * from examminginfo");
	m_AdoConn.OnIniADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(m_pRs->adoEOF==0)
	{
		_RecordsetPtr m_prs;
		CString question=(char*)(_bstr_t)m_pRs->GetCollect("question");
		CString answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
		sql.Format("select * from text where question='%s'",question);
		m_prs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		CString rightanswer=(char*)(_bstr_t)m_prs->GetCollect("rightanswer");
		_variant_t vResultValue;
		vResultValue = m_prs->GetCollect("totle");
		int totle = vResultValue.lVal;
		//int totle=atoi((char*)(_bstr_t)m_pRs->GetCollect("totle"));
		if(answer==rightanswer)
		{
			sql.Format("update examminginfo set totle=%d where question='%s'",totle,question);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		}
		else
		{
			sql.Format("update examminginfo set totle=%d where question='%s'",0,question);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
		}
		m_pRs->MoveNext();
	}
}
