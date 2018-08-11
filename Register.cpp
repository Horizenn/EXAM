// Register.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "Register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog


CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialog(CRegister::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegister)
	m_UserName = _T("");
	m_Passwd = _T("");
	m_PasswdRepeat = _T("");
	m_RealName = _T("");
	m_IDcard = _T("");
	m_Age = 0;
	m_Phone = _T("");
	//}}AFX_DATA_INIT
}


void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegister)
	DDX_Control(pDX, IDC_STATIC1, m_Check);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_Passwd);
	DDX_Text(pDX, IDC_EDIT3, m_PasswdRepeat);
	DDX_Text(pDX, IDC_EDIT4, m_RealName);
	DDX_Text(pDX, IDC_EDIT5, m_IDcard);
	DDX_Text(pDX, IDC_EDIT6, m_Age);
	DDX_Text(pDX, IDC_EDIT7, m_Phone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	//{{AFX_MSG_MAP(CRegister)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegister message handlers

void CRegister::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString sql;
	sql.Format("select * from register where username='%s'",m_UserName);
	try
	{
		m_AdoConn.OnIniADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_UserName.IsEmpty())
			AfxMessageBox("�û�������Ϊ��");
		else
		{
			if(m_pRs->adoEOF)
				m_Check.SetWindowText("�û�������ʹ��");
			else
				m_Check.SetWindowText("�û����Ѵ���");
		}
	}
	catch(...)
	{
		AfxMessageBox("����ʧ��");
		return;
	}
	m_AdoConn.ExitConn();
}

void CRegister::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_UserName.IsEmpty())
	{
		AfxMessageBox("�������û���");
		return;
	}
	if(m_Passwd.IsEmpty())
	{
		AfxMessageBox("����������");
		return;
	}
	if(m_Passwd!=m_PasswdRepeat)
	{
		AfxMessageBox("�����������벻һ�£�����������");
		return;
	}
	if(m_RealName.IsEmpty())
	{
		AfxMessageBox("����������");
		return;
	}
	if(m_IDcard.IsEmpty())
	{
		AfxMessageBox("���������֤��");
		return;
	}
	CString sex;
	if(radio==0)
		sex.Format("");
	if(radio==1)
		sex.Format("��");
	if(radio==2)
		sex.Format("Ů");
	int id;
	try
	{
		CString sql;
		sql.Format("select * from register where username='%s'",m_UserName);
		m_AdoConn.OnIniADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(!m_pRs->adoEOF)
		{
			AfxMessageBox("�û����Ѵ���");
			return;
		}
		else
		{
			sql.Format("select studentid from register");
			m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(m_pRs->adoEOF)
				id=1;
			else
			{
				m_pRs->MoveLast();
				id =m_pRs->GetCollect("studentid").lVal;
				id+=1;
			}
			sql.Format("insert into register values(%d,'%s','%s','%s',%d,'%s','%s','ѧ��','%s')",id,m_UserName,m_Passwd,m_RealName,m_Age,sex,m_Phone,m_IDcard);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_AdoConn.ExitConn();
			AfxMessageBox("ע��ɹ�");
			CRegister::OnCancel();
		}
	}
	catch(...)
	{
		AfxMessageBox("����ʧ��");
		return;
	}
}

void CRegister::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CRegister::OnCancel();
}

void CRegister::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	radio = 1;  //ѡ��Ϊ��
}

void CRegister::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	radio = 2;  //ѡ��ΪŮ
}
