// CSDN批量迅雷下载.h : main header file for the CSDN批量迅雷下载 application
//

#if !defined(AFX_CSDN_H__4554D250_70B5_4256_B5AB_CB298F1FE6EC__INCLUDED_)
#define AFX_CSDN_H__4554D250_70B5_4256_B5AB_CB298F1FE6EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCSDNApp:
// See CSDN批量迅雷下载.cpp for the implementation of this class
//

class CCSDNApp : public CWinApp
{
public:
	CCSDNApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSDNApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCSDNApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSDN_H__4554D250_70B5_4256_B5AB_CB298F1FE6EC__INCLUDED_)
