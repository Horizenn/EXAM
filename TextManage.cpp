// TextManage.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "TextManage.h"
#include "AddSubject.h"
#include "TestChange.h"
#include "AddTest.h"
#include "TextGrade.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextManage dialog


CTextManage::CTextManage(CWnd* pParent /*=NULL*/)
	: CDialog(CTextManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTextManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTextManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTextManage)
	DDX_Control(pDX, IDC_TREE1, m_TextTree);
	DDX_Control(pDX, IDC_LIST1, m_TextList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTextManage, CDialog)
	//{{AFX_MSG_MAP(CTextManage)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextManage message handlers

void CTextManage::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CAddSubject dlg;
	if(dlg.DoModal()==IDOK)
	{
		CString Name;
		Name = dlg.m_SubjectName;
		try
		{
			int subjectid;
			CString sql = "select * from subject";
			m_AdoConn.OnIniADOConn();
			m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
			if(m_pRs->adoEOF)
			{
				subjectid=1;
				sql.Format("insert into subject(subjectid,subjectname)values(%d,'%s')",subjectid,Name);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
			}
			else
			{
				m_pRs->MoveLast();
				subjectid=m_pRs->GetCollect("subjectid").lVal+1;
				sql.Format("insert into subject(subjectid,subjectname)values(%d,'%s')",subjectid,Name);
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
			}
			m_AdoConn.ExitConn();
			m_TextTree.DeleteAllItems();
			AddToTree();
		}
		catch(...)
		{
			AfxMessageBox("操作失败");
			return;
		}
	}
}

void CTextManage::OnButton2() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM CurrentItem = m_TextTree.GetSelectedItem();
	CString str = m_TextTree.GetItemText(CurrentItem);
	if(str=="试题科目")
	{
		AfxMessageBox("请选择科目");
		return;
	}
	else
	{	
		CString sql;
		sql.Format("select * from subject where subjectname='%s'",str);
		m_AdoConn.OnIniADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		int i = m_pRs->GetCollect("subjectid").lVal;
		CAddTest dlg;
		dlg.subjectid = i;
		if(dlg.DoModal()==IDOK)
		{
			m_TextList.DeleteAllItems();
			AddToList(i);
		}
	}
}

void CTextManage::OnButton3() 
{
	// TODO: Add your control notification handler code here
	int i = m_TextList.GetSelectionMark();
	if(i==-1)
	{
		AfxMessageBox("请选择一个试题");
		return;
	}
	else
	{
		CTestChange dlg;
		dlg.m_Question = m_TextList.GetItemText(i,0);
		dlg.m_Answer = m_TextList.GetItemText(i,1);
		CString sql;
		sql.Format("select * from text where question='%s'",dlg.m_Question);
		m_AdoConn.OnIniADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		int testid = m_pRs->GetCollect("testid").lVal;
		int subjectid = m_pRs->GetCollect("subjectid").lVal;
		dlg.testid = testid;
		dlg.subjectid = subjectid;
		sql.Format("select * from textanswer where testid=%d and subjectid=%d",testid,subjectid);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		dlg.m_AnswerA = (char*)(_bstr_t)m_pRs->GetCollect("AnswerA");
		dlg.m_AnswerB = (char*)(_bstr_t)m_pRs->GetCollect("AnswerB");
		dlg.m_AnswerC = (char*)(_bstr_t)m_pRs->GetCollect("AnswerC");
		dlg.m_AnswerD = (char*)(_bstr_t)m_pRs->GetCollect("AnswerD");
		if(dlg.DoModal()==IDOK)
		{
			m_TextList.DeleteAllItems();
			AddToList(subjectid);

		}
	}
}

void CTextManage::OnButton4() 
{
	// TODO: Add your control notification handler code here
	int i = m_TextList.GetSelectionMark();
	CString str = m_TextList.GetItemText(i,0);
	int testidold,testidnew;
	if(i==-1)
	{
		AfxMessageBox("请选择一个试题");
		return;
	}
	try
	{
		CString sql;
		sql.Format("select * from text where question='%s'",str);
		m_AdoConn.OnIniADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		int subjectid = m_pRs->GetCollect("subjectid").lVal;
		testidold = m_pRs->GetCollect("testid").lVal;
		sql.Format("delete from text where question='%s'",str);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		sql.Format("delete from textanswer where testid=%d and subjectid=%d",testidold,subjectid);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		sql.Format("select * from text where testid>%d and subjectid=%d",testidold,subjectid);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		while(m_pRs->adoEOF==0)
		{
			testidold = m_pRs->GetCollect("testid").lVal;
			testidnew = testidold-1;
			sql.Format("update text set testid=%d where testid=%d and subjectid=%d",testidnew,testidold,subjectid);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			sql.Format("update textanswer set testid=%d where testid=%d and subjectid=%d",testidnew,testidold,subjectid);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_pRs->MoveNext();
		}
		m_AdoConn.ExitConn();
		m_TextList.DeleteItem(i);
	}
	catch(...)
	{
		AfxMessageBox("操作错误");
		return;
	}
}

void CTextManage::AddToTree()
{
	HTREEITEM h_root;
	h_root = m_TextTree.InsertItem("试题科目",0,1);
	CString sql="select * from subject";
	_RecordsetPtr m_prs;
	try
	{
		m_AdoConn.OnIniADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
		while(!m_pRs->adoEOF)
		{
			CString str = (char*)(_bstr_t)m_pRs->GetCollect("subjectname");
			m_TextTree.InsertItem(str,0,1,h_root);
			m_pRs->MoveNext();
		}
		m_AdoConn.ExitConn();
	}
	catch(...)
	{
		AfxMessageBox("读取数据失败");
		return;
	}
}

BOOL CTextManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	AddToTree();
	m_TextList.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_TextList.InsertColumn(0,"题目",LVCFMT_LEFT,250,0);
	m_TextList.InsertColumn(1,"答案",LVCFMT_LEFT,100,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTextManage::AddToList(int Sid)
{
	CString sql;
	sql.Format("select * from text where subjectid=%d",Sid);
	m_AdoConn.OnIniADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	while(!m_pRs->adoEOF)
	{
		CString Question = (char*)(_bstr_t)m_pRs->GetCollect("question");
		CString Answer = (char*)(_bstr_t)m_pRs->GetCollect("rightanswer");
		m_TextList.InsertItem(0,"");
		m_TextList.SetItemText(0,0,Question);
		m_TextList.SetItemText(0,1,Answer);
		m_pRs->MoveNext();
	}
	m_AdoConn.ExitConn();
}

void CTextManage::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM select = m_TextTree.GetSelectedItem();
	if(select!=m_TextTree.GetRootItem())
	{
		CString TreeText = m_TextTree.GetItemText(select);
		m_TextList.DeleteAllItems();
		try
		{
			CString sql;
			sql.Format("select * from subject where subjectname='%s'",TreeText);
			m_AdoConn.OnIniADOConn();
			m_pRs = m_AdoConn.GetRecordSet((_bstr_t)sql);
			int Sid = m_pRs->GetCollect("subjectid").lVal;
			AddToList(Sid);
			//m_AdoConn.ExitConn();
		}
		catch(...)
		{
			AfxMessageBox("操作失败");
			return;
		}
	}

	*pResult = 0;
}

void CTextManage::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CTextGrade dlg;
	dlg.DoModal();
}
