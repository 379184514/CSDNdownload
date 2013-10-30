// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "thunderagent_007.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IAgent properties

/////////////////////////////////////////////////////////////////////////////
// IAgent operations

CString IAgent::GetInfo(LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pInfoName);
	return result;
}

void IAgent::AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount);
}

long IAgent::CommitTasks()
{
	long result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void IAgent::CancelTasks()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString IAgent::GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pURL, pInfoName);
	return result;
}

void IAgent::GetInfoStruct(long pInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pInfo);
}

void IAgent::GetTaskInfoStruct(long pTaskInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pTaskInfo);
}


/////////////////////////////////////////////////////////////////////////////
// IAgent2 properties

/////////////////////////////////////////////////////////////////////////////
// IAgent2 operations

CString IAgent2::GetInfo(LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pInfoName);
	return result;
}

void IAgent2::AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount);
}

long IAgent2::CommitTasks()
{
	long result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void IAgent2::CancelTasks()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString IAgent2::GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pURL, pInfoName);
	return result;
}

void IAgent2::GetInfoStruct(long pInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pInfo);
}

void IAgent2::GetTaskInfoStruct(long pTaskInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pTaskInfo);
}

void IAgent2::AddTask2(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount, pCookie);
}

long IAgent2::CommitTasks2(long nIsAsync)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		nIsAsync);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// IAgent3 properties

/////////////////////////////////////////////////////////////////////////////
// IAgent3 operations

CString IAgent3::GetInfo(LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pInfoName);
	return result;
}

void IAgent3::AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount);
}

long IAgent3::CommitTasks()
{
	long result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void IAgent3::CancelTasks()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString IAgent3::GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pURL, pInfoName);
	return result;
}

void IAgent3::GetInfoStruct(long pInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pInfo);
}

void IAgent3::GetTaskInfoStruct(long pTaskInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pTaskInfo);
}

void IAgent3::AddTask2(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount, pCookie);
}

long IAgent3::CommitTasks2(long nIsAsync)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		nIsAsync);
	return result;
}

void IAgent3::AddTask3(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie, LPCTSTR pCID)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount, pCookie, pCID);
}


/////////////////////////////////////////////////////////////////////////////
// IAgent4 properties

/////////////////////////////////////////////////////////////////////////////
// IAgent4 operations

CString IAgent4::GetInfo(LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pInfoName);
	return result;
}

void IAgent4::AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount);
}

long IAgent4::CommitTasks()
{
	long result;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void IAgent4::CancelTasks()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString IAgent4::GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		pURL, pInfoName);
	return result;
}

void IAgent4::GetInfoStruct(long pInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pInfo);
}

void IAgent4::GetTaskInfoStruct(long pTaskInfo)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pTaskInfo);
}

void IAgent4::AddTask2(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount, pCookie);
}

long IAgent4::CommitTasks2(long nIsAsync)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		nIsAsync);
	return result;
}

void IAgent4::AddTask3(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie, LPCTSTR pCID)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount, pCookie, pCID);
}

void IAgent4::AddTask4(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie, LPCTSTR pCID, LPCTSTR pStatURL)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pURL, pFileName, pPath, pComments, pReferURL, nStartMode, nOnlyFromOrigin, nOriginThreadCount, pCookie, pCID, pStatURL);
}
