// EXAMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EXAM.h"
#include "EXAMDlg.h"
#include "ADOConn.h"
#include "ExamInfo.h"
#include "Register.h"
#include "TextManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEXAMDlg dialog

CEXAMDlg::CEXAMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEXAMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEXAMDlg)
	m_UserName = _T("");
	m_UserPasswd = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEXAMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEXAMDlg)
	DDX_Control(pDX, IDC_COMBO1, m_TypeList);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_UserPasswd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEXAMDlg, CDialog)
	//{{AFX_MSG_MAP(CEXAMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEXAMDlg message handlers

BOOL CEXAMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	m_TypeList.AddString("学生");
	m_TypeList.AddString("教职工");
	m_TypeList.SetCurSel(1);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEXAMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEXAMDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEXAMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEXAMDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString str;
	m_TypeList.GetLBText(m_TypeList.GetCurSel(),str);  //获取下拉列表信息
	if(m_UserName.IsEmpty())  //判断用户名是否为空
	{
		AfxMessageBox("用户名不能为空");
		return;
	}
	if(m_UserPasswd.IsEmpty())
	{
		AfxMessageBox("密码不能为空");
		return;
	}
	CString sql;
	//查询是否账号密码权限正确
	sql.Format("select * from register where username='%s' and password='%s' and power='%s'",m_UserName,m_UserPasswd,str); 
	try
	{
		_RecordsetPtr m_pRs;
		ADOConn m_AdoConn;
		m_AdoConn.OnIniADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)
			AfxMessageBox("用户名密码或权限错误");
		else
		{
			AfxMessageBox("登录成功");
			if(str == "学生")
			{
				_variant_t vResultValue;
				vResultValue = m_pRs->GetCollect("studentid");
				studentid = vResultValue.lVal;		
				m_AdoConn.ExitConn();
				CEXAMDlg::OnCancel();  //关闭窗口
				CExamInfo a;
				a.studentid=studentid;
				a.DoModal();  //打开科目选择窗口
				//a.Create(IDD_EXAMINFO);
				//a.ShowWindow(IDD_EXAMINFO);
			}
			else
			{
				m_AdoConn.ExitConn();
				CEXAMDlg::OnCancel();  //关闭窗口
				CTextManage dlg;
				dlg.DoModal();
			}
		}

	}
	catch(...)
	{
		AfxMessageBox("操作失败");
		return;
	}

	//ADOConn ado;
	//ado.OnIniADOConn();
}

void CEXAMDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	DestroyWindow();
	
}

void CEXAMDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
		CRegister dlg;
		dlg.DoModal();
	
}


