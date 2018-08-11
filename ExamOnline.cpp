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
	UpdateData();   //��ȡ��ǰ�Ի���������Ϣ
	//Ϊ��ѡ�ؼ���ӱ���
	CButton* m_checkA=(CButton*)GetDlgItem(IDC_RADIO_A);
	CButton* m_checkB=(CButton*)GetDlgItem(IDC_RADIO_B);
	CButton* m_checkC=(CButton*)GetDlgItem(IDC_RADIO_C);
	CButton* m_checkD=(CButton*)GetDlgItem(IDC_RADIO_D);
	if(testnum==1)   //�����ǰ���Ϊ1
	{
		AfxMessageBox("���Ѿ��ǵ�һ����");   //��ʾ������Ϣ
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
	//�޸Ĵ�����Ϣ�ݴ���е�ǰ��ŵ������
	//sql.Format("select * from examminginfo where testnum=%d",testnum);  
	//m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
	answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");  //��ȡ��ǰ��������
	if(answer!=Answer&&Answer!='e') //���ԭ�д��뵱ǰ�𰸲�ͬ���޸�
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
	}

	testnum--;
	sql.Format("select * from examminginfo where testnum=%d",testnum);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	question=(char*)(_bstr_t)m_pRs->GetCollect("question");
	answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");
	m_TestID.Format("���:%d",testnum);
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
	//Ϊ4����ѡ�ؼ��ֱ����һ������
	CButton* m_checkA=(CButton*)GetDlgItem(IDC_RADIO_A);
	CButton* m_checkB=(CButton*)GetDlgItem(IDC_RADIO_B);
	CButton* m_checkC=(CButton*)GetDlgItem(IDC_RADIO_C);
	CButton* m_checkD=(CButton*)GetDlgItem(IDC_RADIO_D);
	CString sql;
	CString question,answer;
	question = m_Test;  //��ȡ��ǰ��Ŀ��Ϣ
	CString Id;
	Id.Format("���:%d",testnum+1);
	m_AdoConn.OnIniADOConn();
	sql.Format("select * from text where question='%s'",question);
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	CString testid=(char*)(_bstr_t)m_pRs->GetCollect("testid");
	//��ȡ������Ϣ������һ����Ϣ
	sql.Format("select * from examminginfo where testnum=%d",testnum+1);  
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)  //�����һ����ϢΪ��
	{
		sql.Format("select * from examminginfo where question='%s'",question);  
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)  //�����������һ����Ϣ
		{
			if(Answer!='A'&&Answer!='B'&&Answer!='C'&&Answer!='D') //���ѡ���A,B,C,D
			{
				AfxMessageBox("��ѡ��һ����");  //��ʾ������Ϣ
				return;
			}
			SaveQuestion();  //���浱ǰ������Ϣ
		}
		//���������Ϣ�ݴ���д�����һ��������Ϣ
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		//�޸Ĵ�����Ϣ�ݴ���е�ǰ��ŵ������

		if(m_checkA->GetCheck()==BST_CHECKED)
			Answer = 'A';
		if(m_checkB->GetCheck()==BST_CHECKED)
			Answer = 'B';
		if(m_checkC->GetCheck()==BST_CHECKED)
			Answer = 'C';
		if(m_checkD->GetCheck()==BST_CHECKED)
			Answer = 'D';

		sql.Format("update examminginfo set answer='%s' where testnum=%d",Answer,testnum);
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");  //��ȡ��ǰ��������
		if(answer!=Answer&&Answer!='e')    //���ԭ�д��뵱ǰ�𰸲�ͬ���޸�
			m_AdoConn.ExecuteSQL((_bstr_t)sql);

		sql.Format("select * from text where question='%s'",question);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		_variant_t vResultValue;
		vResultValue = m_pRs->GetCollect("testid");
		int tid= vResultValue.lVal;
		int sid= m_pRs->GetCollect("subjectid").lVal;
		//int tid=atoi(testid);
		//��ѯ������Ϣ���бȵ�ǰ������Ŵ��������Ϣ
		sql.Format("select * from text where subjectid=%d and testid>%d order by testid",sid,tid);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)  //�����¼Ϊ��
		{
			CheckAnswer();   //�˶�����𰸲��ֱ�Ը�����
			if(MessageBox("���Խ������Ƿ񽻾�","��ʾ",MB_YESNO)==IDYES)
			{
				AfxMessageBox("����ɹ�");
				CTime time;
				time =CTime::GetCurrentTime();  //��ȡ��ǰϵͳʱ��
				CString TimeStr=time.Format("%m��%d��%H:%M");
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
		//��4��ѡ�ؼ�ȫ���ó�ʼ״̬
		m_checkA->SetCheck(false);
		m_checkB->SetCheck(false);
		m_checkC->SetCheck(false);
		m_checkD->SetCheck(false);
		Answer='e';  //��Answerֵ��ʼ��
		question=(char*)(_bstr_t)m_pRs->GetCollect("question");  //��ȡ������Ŀ��Ϣ
		m_TestID = Id;  //�޸���Ŀ��
		m_Test = question;  //�޸�������Ϣ
		GetDlgItem(IDC_STATIC1)->SetWindowText(m_Test);
		GetDlgItem(IDC_STATIC2)->SetWindowText(m_TestID);
		testnum++;
		PutAnswer();  //��ʾ����ѡ����Ϣ
		}
	}
	else  //�����һ����Ϣ����
	{
		sql.Format("select * from examminginfo where testnum=%d",testnum);
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		//���´�����Ϣ�ݴ�����������Ϣ
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
		testnum++;  //����ID��1
		sql.Format("select * from examminginfo where testnum=%d",testnum);  //��ѯ��һ����Ϣ
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		question=(char*)(_bstr_t)m_pRs->GetCollect("question");  //��ȡ������Ŀ��Ϣ
		answer=(char*)(_bstr_t)m_pRs->GetCollect("answer");   //��ȡ�������Ϣ
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
	UpdateData();   //��ȡ�����е�ǰ��Ϣ
	CString question;
	question = m_Test;   //��ȡ������Ϣ
	CString sql;
	sql.Format("select * from text where question='%s'",question);   //��ѯ�������������Ϣ
	m_AdoConn.OnIniADOConn();  //�����ݿ�����
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);   //��ȡ��¼
	_variant_t vResultValue;
	vResultValue = m_pRs->GetCollect("testid");
	testnum= vResultValue.lVal; //��ö�Ӧ��Ŀ��ID��
	CString testid=(char*)(_bstr_t)m_pRs->GetCollect("testid");  //��ȡ�������������
	sql.Format("select * from textanswer where testid='%s' and subjectid=%d",testid,subjectid);   //��ѯѡ����и�����ID
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);  //��ȡ��¼
	CString A,B,C,D;
	A=(char*)(_bstr_t)m_pRs->GetCollect("AnswerA");   //��ȡAѡ����Ϣ
	B=(char*)(_bstr_t)m_pRs->GetCollect("AnswerB");   //��ȡBѡ����Ϣ
	C=(char*)(_bstr_t)m_pRs->GetCollect("AnswerC");   //��ȡCѡ����Ϣ
	D=(char*)(_bstr_t)m_pRs->GetCollect("AnswerD");   //��ȡDѡ����Ϣ
	GetDlgItem(IDC_RADIO_A)->SetWindowText("A   "+A);   //��Aѡ����Ϣ�ڵ�ѡ�ؼ�����ʾ
	GetDlgItem(IDC_RADIO_B)->SetWindowText("B   "+B);   //��Bѡ����Ϣ�ڵ�ѡ�ؼ�����ʾ
	GetDlgItem(IDC_RADIO_C)->SetWindowText("C   "+C);   //��Cѡ����Ϣ�ڵ�ѡ�ؼ�����ʾ
	GetDlgItem(IDC_RADIO_D)->SetWindowText("D   "+D);	//��Dѡ����Ϣ�ڵ�ѡ�ؼ�����ʾ
	m_AdoConn.ExitConn();   //�ر����ݿ�����
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
