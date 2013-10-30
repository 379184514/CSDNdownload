// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IAgent wrapper class

class IAgent : public COleDispatchDriver
{
public:
	IAgent() {}		// Calls COleDispatchDriver default constructor
	IAgent(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAgent(const IAgent& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetInfo(LPCTSTR pInfoName);
	void AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount);
	long CommitTasks();
	void CancelTasks();
	CString GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName);
	void GetInfoStruct(long pInfo);
	void GetTaskInfoStruct(long pTaskInfo);
};
/////////////////////////////////////////////////////////////////////////////
// IAgent2 wrapper class

class IAgent2 : public COleDispatchDriver
{
public:
	IAgent2() {}		// Calls COleDispatchDriver default constructor
	IAgent2(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAgent2(const IAgent2& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetInfo(LPCTSTR pInfoName);
	void AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount);
	long CommitTasks();
	void CancelTasks();
	CString GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName);
	void GetInfoStruct(long pInfo);
	void GetTaskInfoStruct(long pTaskInfo);
	void AddTask2(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie);
	long CommitTasks2(long nIsAsync);
};
/////////////////////////////////////////////////////////////////////////////
// IAgent3 wrapper class

class IAgent3 : public COleDispatchDriver
{
public:
	IAgent3() {}		// Calls COleDispatchDriver default constructor
	IAgent3(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAgent3(const IAgent3& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetInfo(LPCTSTR pInfoName);
	void AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount);
	long CommitTasks();
	void CancelTasks();
	CString GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName);
	void GetInfoStruct(long pInfo);
	void GetTaskInfoStruct(long pTaskInfo);
	void AddTask2(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie);
	long CommitTasks2(long nIsAsync);
	void AddTask3(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie, LPCTSTR pCID);
};
/////////////////////////////////////////////////////////////////////////////
// IAgent4 wrapper class

class IAgent4 : public COleDispatchDriver
{
public:
	IAgent4() {}		// Calls COleDispatchDriver default constructor
	IAgent4(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAgent4(const IAgent4& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetInfo(LPCTSTR pInfoName);
	void AddTask(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount);
	long CommitTasks();
	void CancelTasks();
	CString GetTaskInfo(LPCTSTR pURL, LPCTSTR pInfoName);
	void GetInfoStruct(long pInfo);
	void GetTaskInfoStruct(long pTaskInfo);
	void AddTask2(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie);
	long CommitTasks2(long nIsAsync);
	void AddTask3(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie, LPCTSTR pCID);
	void AddTask4(LPCTSTR pURL, LPCTSTR pFileName, LPCTSTR pPath, LPCTSTR pComments, LPCTSTR pReferURL, long nStartMode, long nOnlyFromOrigin, long nOriginThreadCount, LPCTSTR pCookie, LPCTSTR pCID, LPCTSTR pStatURL);
};
