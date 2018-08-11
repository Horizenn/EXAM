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
	::CoInitialize(NULL);  //��ʼ��OLE/COM��
	try
	{
		m_pCon.CreateInstance("ADODB.Connection");    //����Connection����
		m_pCon->ConnectionTimeout=3;    //����������ʱ
		//���������ַ���
		m_pCon->Open("DSN=MySqlODBC;server=localhost;database=examonline","root"," ",adModeUnknown);
		//AfxMessageBox("�������ݿ�ɹ�");
	}
	catch(_com_error e)   //�����쳣
	{
		AfxMessageBox(e.Description());   //��ʾ������Ϣ
	}
}

void ADOConn::ExitConn()
{
	if(m_pRs!=NULL)   //�жϼ�¼���Ƿ�Ϊ��
			m_pRs->Close();  //��Ϊ�����ȹرռ�¼��
	m_pCon->Close();  //�ر�����
	::CoUninitialize();  //�ͷ�����
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL)    //�ж�Connection�����Ƿ�Ϊ��
			this->OnIniADOConn();  //���Ϊ���������������ݿ�
		m_pRs.CreateInstance("ADODB.Recordset");  //������¼������
		//��ȡ���ݱ��е�����
		m_pRs->Open(bstrSQL,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)  //�����쳣
	{
		AfxMessageBox(e.Description());  //��ʾ������Ϣ
	}
	return m_pRs;  //���ؼ�¼��
}

BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL)  //�ж�Connection�����Ƿ�Ϊ��
			this->OnIniADOConn();  //���Ϊ���������������ݿ�
		m_pCon->Execute(bstrSQL,NULL,adCmdText);  //ִ�����ݿ����
		return true;
	}
	catch(_com_error e)  //�����쳣
	{
		AfxMessageBox(e.Description());  //��ʾ������Ϣ
		return false;
	}
}
