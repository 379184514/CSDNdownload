// CSDNÅúÁ¿Ñ¸À×ÏÂÔØDlg.h : header file
//

#if !defined(AFX_CSDNDLG_H__9B31D141_BD68_4159_8306_4B6DE0573523__INCLUDED_)
#define AFX_CSDNDLG_H__9B31D141_BD68_4159_8306_4B6DE0573523__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSDNDlg dialog

class CCSDNDlg : public CDialog
{
// Construction
public:
	int httppost(CString theUrl,CString theData);
	CCSDNDlg(CWnd* pParent = NULL);	// standard constructor

	
	CToolTipCtrl m_tooltip;
	int curpage;
	int totalpage;
	int pici;
	int pagecount;
	int curlistitem;
	int pagepreint;
	CMemFile bufMemFile;
	CString keywordEncode;
	GetSourceTextFile(CString theUrl) ;
	int GetData();
	int GetData2();
	int addlist();
	int AddTD(CString TDurl);
// Dialog Data
	//{{AFX_DATA(CCSDNDlg)
	enum { IDD = IDD_CSDN_DIALOG };
	CComboBox	m_combo_ctrl;
	CListCtrl	m_mylist;
	CString	m_keyword;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSDNDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCSDNDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Ongosearch();
	afx_msg void Onbtfw();
	afx_msg void Onbtnext();
	afx_msg void OnBUTTONgoTD();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnGetScore();
	afx_msg void OnButton4();
	afx_msg void OnSelchangeCOMBOpagepre();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSDNDLG_H__9B31D141_BD68_4159_8306_4B6DE0573523__INCLUDED_)
