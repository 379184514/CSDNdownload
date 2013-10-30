#if !defined(AFX_LOGINDLG_H__F99BEF2A_5776_43E6_B893_A73FF867CDC7__INCLUDED_)
#define AFX_LOGINDLG_H__F99BEF2A_5776_43E6_B893_A73FF867CDC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	void	DownURLImage();
	void	ShowImage();

	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_CSDNLOGIN_DIALOG };
	CString	m_strUser;
	CString	m_strPassword;
	CString	m_strCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	RECT	m_pRectLink;		// 用于保存静态文本框的矩形区域
	RECT	m_PicRect;			// 保存图片验证码矩形区域

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	afx_msg void OnBtnLogin();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBtnExit();
	afx_msg void OnClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__F99BEF2A_5776_43E6_B893_A73FF867CDC7__INCLUDED_)
