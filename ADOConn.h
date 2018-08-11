// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__93232652_A101_4018_9716_C49EB022E65A__INCLUDED_)
#define AFX_ADOCONN_H__93232652_A101_4018_9716_C49EB022E65A__INCLUDED_
#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"no_namespace rename("EOF","adoEOF")
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	ADOConn();
	virtual ~ADOConn();
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void ExitConn();
	void OnIniADOConn();
	_ConnectionPtr m_pCon;
	_RecordsetPtr m_pRs;

};

#endif // !defined(AFX_ADOCONN_H__93232652_A101_4018_9716_C49EB022E65A__INCLUDED_)
