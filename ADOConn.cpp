// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EXAM.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnIniADOConn()
{
	::CoInitialize(NULL);  //初始化OLE/COM库
	try
	{
		m_pCon.CreateInstance("ADODB.Connection");    //创建Connection对象
		m_pCon->ConnectionTimeout=3;    //设置连接延时
		//设置连接字符串
		m_pCon->Open("DSN=MySqlODBC;server=localhost;database=examonline","root"," ",adModeUnknown);
		//AfxMessageBox("连接数据库成功");
	}
	catch(_com_error e)   //捕获异常
	{
		AfxMessageBox(e.Description());   //显示错误信息
	}
}

void ADOConn::ExitConn()
{
	if(m_pRs!=NULL)   //判断记录集是否为空
			m_pRs->Close();  //不为空则先关闭记录集
	m_pCon->Close();  //关闭连接
	::CoUninitialize();  //释放连接
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL)    //判断Connection对象是否为空
			this->OnIniADOConn();  //如果为空则重新连接数据库
		m_pRs.CreateInstance("ADODB.Recordset");  //创建记录集对象
		//获取数据表中的数据
		m_pRs->Open(bstrSQL,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)  //捕获异常
	{
		AfxMessageBox(e.Description());  //显示错误信息
	}
	return m_pRs;  //返回记录集
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL)  //判断Connection对象是否为空
			this->OnIniADOConn();  //如果为空则重新连接数据库
		m_pCon->Execute(bstrSQL,NULL,adCmdText);  //执行数据库语句
		return true;
	}
	catch(_com_error e)  //捕获异常
	{
		AfxMessageBox(e.Description());  //显示错误信息
		return false;
	}
}
