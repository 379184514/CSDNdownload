// CSDN批量迅雷下载Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CSDN批量迅雷下载.h"
#include "CSDN批量迅雷下载Dlg.h"
#include "LoginDlg.h"

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
	virtual void OnOK();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSDNDlg dialog

CCSDNDlg::CCSDNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCSDNDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCSDNDlg)
	m_keyword = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCSDNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCSDNDlg)
	DDX_Control(pDX, IDC_COMBO_pagepre, m_combo_ctrl);
	DDX_Control(pDX, IDC_LIST1, m_mylist);
	DDX_Text(pDX, IDC_EDIT_search, m_keyword);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCSDNDlg, CDialog)
	//{{AFX_MSG_MAP(CCSDNDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_gosearch, Ongosearch)
	ON_BN_CLICKED(IDC_bt_fw, Onbtfw)
	ON_BN_CLICKED(IDC_bt_next, Onbtnext)
	ON_BN_CLICKED(IDC_BUTTON_goTD, OnBUTTONgoTD)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnGetScore)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_CBN_SELCHANGE(IDC_COMBO_pagepre, OnSelchangeCOMBOpagepre)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSDNDlg message handlers

BOOL CCSDNDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

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
//	m_tooltip.Create(this);
//	m_tooltip.Activate(TRUE);
//	m_tooltip.AddTool(GetDlgItem(IDC_LIST1), "双击显示商家报价");
		
	m_mylist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);
	m_mylist.InsertColumn(0,"地址ID",LVCFMT_LEFT,90);
	m_mylist.InsertColumn(1,"名称",LVCFMT_LEFT,90);
	m_mylist.InsertColumn(2,"发布人",LVCFMT_LEFT,90);
	m_mylist.InsertColumn(3,"软件说明",LVCFMT_LEFT,290);
//	.SetCurSel(0);
	m_combo_ctrl.SetCurSel(0);	

//	startpage=0;
	pici=0;
	curpage=1;
	curlistitem=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCSDNDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCSDNDlg::OnPaint() 
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
HCURSOR CCSDNDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#include <afxinet.h>
int CCSDNDlg::GetSourceTextFile(CString theUrl) 
{
	bufMemFile.SetLength(0);
	CInternetSession session;
	CInternetFile* file = NULL;
	try
	{
		// 试着连接到指定URL
		file = (CInternetFile*) session.OpenURL(theUrl); 
	}
	catch (CInternetException* m_pException)
	{
		// 如果有错误的话，置文件为空
		file = NULL; 
		m_pException->Delete();
		return FALSE;
	}
	
	// 用dataStore来保存读取的文件

	if (file)
	{
		CString somecode;                            //也可采用LPTSTR类型，将不会删除文本中的\n回车符

		// 读写文件，直到为空
		while (file->ReadString(somecode) != NULL) //如果采用LPTSTR类型，读取最大个数nMax置0，使它遇空字符时结束
		{
			bufMemFile.Write(somecode.GetBuffer(0),somecode.GetLength());
			bufMemFile.Write("\n",1);           //如果somecode采用LPTSTR类型,可不用此句
		}
		
		file->Close();
		delete file;
	}
	else
	{
		return FALSE;
	}
	
	return 1;
}


int URLEncode(LPCTSTR pszUrl, LPTSTR pszEncode, int nEncodeLen)   
{   
    if( pszUrl == NULL )  return 0;   
    if( pszEncode == NULL || nEncodeLen == 0 ) return 0;   
  
    //定义变量   
    int nLength = 0;   
    WCHAR* pWString = NULL;   
    TCHAR* pString = NULL;   

    nLength = MultiByteToWideChar(CP_ACP, 0, pszUrl, -1, NULL, 0);   //先将字符串由多字节转换成UTF-8编码  
    pWString = new WCHAR[nLength];  //分配Unicode空间   
    MultiByteToWideChar(CP_ACP, 0, pszUrl, -1, pWString, nLength); //先转换成Unicode     
    nLength = WideCharToMultiByte(CP_UTF8, 0, pWString, -1, NULL, 0, NULL, NULL); //分配UTF-8空间   
    pString = new TCHAR[nLength];   
    nLength = WideCharToMultiByte(CP_UTF8, 0, pWString, -1, pString, nLength, NULL, NULL);  //Unicode转到UTF-8    
    static char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};   
    memset(pszEncode, 0, nEncodeLen/sizeof(TCHAR));   
  
    for( int i = 0; i < nLength-1; i++ )   
    {   
        unsigned char c = pString[i];   
        if( c > 0x20 && c < 0x7f )    // 数字或字母   
        {   
            *pszEncode++ = c;   
        }   
        else if( c == 0x20 )        // 包含空格   
        {   
            *pszEncode++ = '+';   
        }   
        else                        // 进行编码   
        {   
            *pszEncode++ = '%';   
            *pszEncode++ = hex[c / 16];   
            *pszEncode++ = hex[c % 16];   
        }   
    }   
  
    //删除内存   
    delete pWString;   
    delete pString;   
  
    return nLength;   
} 


void CCSDNDlg::Ongosearch() 
{
	// TODO: Add your control notification handler code here
	m_mylist.DeleteAllItems();
	UpdateData();
	if(m_keyword=="") 
	{
		AfxMessageBox("请输入关键字！");
		return;
	}
	TCHAR szEncode[255]={0};
	URLEncode(m_keyword, szEncode, m_keyword.GetLength()*3/2);
	//	AfxMessageBox(szEncode);
	keywordEncode=szEncode;
	CString pageprestr;
	UpdateData();
	GetDlgItemText(IDC_COMBO_pagepre,pageprestr);//每批页数
	AfxMessageBox(pageprestr);
	pagepreint=atoi(pageprestr);

	pici=0;
	curpage=1;
	//curlistitem=0;
	//GetDlgItem(IDC_COMBO_pagepre)->EnableWindow(FALSE);
	addlist();

}
int CCSDNDlg::addlist() 
{
	CString strurl;
	strurl.Format("http://search.download.csdn.net/search/%s^field=*/%d",
		keywordEncode,pici*pagepreint+curpage);
	BOOL re=GetSourceTextFile(strurl);
	if(!re)return 0;
	GetData();

	if (curpage<pagepreint)
	{
		curpage++;
		addlist();
	}
	else return 0;
	return 1;
}

int CCSDNDlg::GetData()
{
//	m_mylist.DeleteAllItems();

	bufMemFile.SeekToBegin();
	int buflen=bufMemFile.GetLength();
	if(!buflen)return 0;
	char*szU8=new char[buflen+1];
	bufMemFile.ReadHuge(szU8,buflen);
	szU8[buflen]=0;

	//CFile mFile2("m_txt", CFile::modeWrite|CFile::modeCreate); 
	//mFile2.Write(szU8,buflen);
	//mFile2.Close();
	//char*p=szU8;
	//char*p2=szU8;
	//p2=strstr(p,"DOCTYPE");
	//AfxMessageBox(p2);
	
	//UTF8 to Unicode 
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0); //预转换，得到所需空间的大小 
    wchar_t* wszString = new wchar_t[wcsLen + 1]; //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间 
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen); //转换 
    wszString[wcsLen] = '\0'; //最后加上'\0' 
	//   ::MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK); //unicode版的MessageBox API 
	
    // unicode to ansi 
    int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL); 
    
    char* szAnsi = new char[ansiLen + 1]; //同上，分配空间要给'\0'留个空间 
    //转换 //unicode版对应的strlen是wcslen 
    ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL); 
    szAnsi[ansiLen] = '\0'; //最后加上'\0' 
	//    ::MessageBoxA(GetSafeHwnd(), szAnsi, szAnsi, MB_OK); 	//Ansi版的MessageBox API 
	
	char* p=szAnsi;
	char* p2=szAnsi;
	char* p3=szAnsi;
	char* url=NULL;
	char* name=NULL;
	char* owner=NULL;
	char* description=NULL;	
	int i=0;//curlistitem;
	
	while(p)
	{
		p2=strstr(p,"<h3><a href=\"http://download.csdn.net/source/");
		//AfxMessageBox(p2);
		if(!p2)break;
		p2+=lstrlen("<h3><a href=\"http://download.csdn.net/source/");
		p3=strstr(p2,"\">");
		if(!p3)break;
		url=new char[p3-p2+1];
		strncpy(url,p2,p3-p2);
		url[p3-p2]=0;
		//		::MessageBoxA(GetSafeHwnd(), url, url, MB_OK); 
		
		p2=p3+lstrlen("\">");
		p3=strstr(p2,"</a>");
		if(!p3)break;
		name=new char[p3-p2+1];
		strncpy(name,p2,p3-p2);
		name[p3-p2]=0;
		//		::MessageBoxA(GetSafeHwnd(), name, name, MB_OK); 
		
		p2=strstr(p3,"<p>");
		if(!p2)break;
		p2+=lstrlen("<p>");
		p3=strstr(p2,"</p>");
		if(!p3)break;
		description=new char[p3-p2+1];
		strncpy(description,p2,p3-p2);
		description[p3-p2]=0;
		//		::MessageBoxA(GetSafeHwnd(), description,shuoming, MB_OK); 
		
		p2=strstr(p3,"<em>用户：</em>");
		if(!p2)break;
		p2+=lstrlen("<em>用户：</em>");
		p2=strstr(p2,">");
		if(!p2)break;
		p2+=lstrlen(">");
		p3=strstr(p2,"</a>");
		if(!p3)break;
		owner=new char[p3-p2+1];
		strncpy(owner,p2,p3-p2);
		owner[p3-p2]=0;		
		//		::MessageBoxA(GetSafeHwnd(), owner, owner, MB_OK);
		
		m_mylist.InsertItem(i,url,0);
		m_mylist.SetItemText(i,1,name);
		m_mylist.SetItemText(i,2,owner);
		m_mylist.SetItemText(i,3,description);
		m_mylist.SetCheck(i);
		
		if(!p3)break;
		p=p2;
		i++;
		delete url;
		delete name;
		delete description;
		delete owner;
	}
	p2=p3=strstr(p,"\">末页</a>");
//	AfxMessageBox(p3);
	while(*(p2-1)!='/') p2-=1;
//	AfxMessageBox(p2);
	char* totalpages=new char[p3-p2+1];
	strncpy(totalpages,p2,p3-p2);
	totalpages[p3-p2]=0;
//	AfxMessageBox(totalpages);
	CString curpageall;
	curpageall.Format("页数：%d/%s",curpage+pici*pagepreint,totalpages);
	::SetDlgItemText(m_hWnd,IDC_page,curpageall);
	totalpage=atoi(totalpages);
	delete totalpages;
	//curlistitem=i;
	
//CString ss=(CString)"safsa"+totalpages;
//CString ss="safsa"+CString(totalpages);
//AfxMessageBox(ss);

/*
//unicode版
	WCHAR*p=wszString;
	WCHAR*p2=wszString;	
	WCHAR* url=NULL;
	WCHAR* name=NULL;
	WCHAR* owner=NULL;
	WCHAR* shuoming=NULL;
	int i=0;

	while(p)
	{
		p2=wcsstr(p,L"<h3><a href=\"http://download.csdn.net/source/");
		if(!p2)break;
		p2+=lstrlen("<h3><a href=\"");
		WCHAR*p3=wcsstr(p2,L"\">");
		if(!p3)break;
		url=new WCHAR[p3-p2];
		wcsncpy(url,p2,p3-p2);
		url[p3-p2]=0;
		//name.GetBuffer(0)[p3-p2-1]=0;
//		MessageBoxW(0,url,0,0);

		p2=p3+lstrlen("\">");
//		MessageBoxW(0,p3,0,0);
		p3=wcsstr(p2,L"</a>");
		if(!p3)break;
		name=new WCHAR[p3-p2];
		wcsncpy(name,p2,p3-p2);
		name[p3-p2]=0;
//		MessageBoxW(0,name,0,0);
		
		p2=wcsstr(p3,L"<p>");
		if(!p2)break;
		p2+=lstrlen("<p>");
		p3=wcsstr(p2,L"</p>");
		if(!p3)break;
		shuoming=new WCHAR[p3-p2];
		wcsncpy(shuoming,p2,p3-p2);
		shuoming[p3-p2]=0;
//		MessageBoxW(0,shuoming,0,0);

		p2=wcsstr(p3,L"<em>用户：</em>");
		if(!p2)break;
		p2+=lstrlen("<em>用户：</em>");
		p2=wcsstr(p2,L">");
		if(!p2)break;
		p2+=lstrlen(">");
		p3=wcsstr(p2,L"</a>");
		if(!p3)break;
		owner=new WCHAR[p3-p2];
		wcsncpy(owner,p2,p3-p2);
		owner[p3-p2]=0;
		MessageBoxW(0,owner,0,0);		

		m_list.InsertItem(i,"sfasf",0);
		m_list.SetItemText(0,1,"aaa");

		if(!p3)break;
		p=p2;
		i++;
	}
*/	

	return 1;
}

void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here

//	CDialog::OnOK();
}

void CCSDNDlg::Onbtfw() 
{
	// TODO: Add your control notification handler code here
	m_mylist.DeleteAllItems();
	curpage=1;
	if(pici--)
	{
		if (pici==0)
		{
			GetDlgItem(IDC_COMBO_pagepre)->EnableWindow(true);
		}
		addlist();
	}
	else
	{
		pici=0;
//		GetDlgItem(IDC_COMBO_pagepre)->EnableWindow(true);
		addlist();
	}
}

void CCSDNDlg::Onbtnext() 
{
	// TODO: Add your control notification handler code here
	m_mylist.DeleteAllItems();
	curpage=1;
	GetDlgItem(IDC_COMBO_pagepre)->EnableWindow(false);
//	if (pici*pagepreint)
//	{
//	}
	if ((pici+1)*pagepreint<totalpage)
	{
		pici++;
		addlist();
	}

}


int CCSDNDlg::GetData2()
{
	bufMemFile.SeekToBegin();
	int buflen=bufMemFile.GetLength();
	if(!buflen)return 0;
	char*szU8=new char[buflen+1];
	bufMemFile.ReadHuge(szU8,buflen);
	szU8[buflen]=0;

	//UTF8 to Unicode 
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0); //预转换，得到所需空间的大小 
    wchar_t* wszString = new wchar_t[wcsLen + 1]; //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间 
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen); //转换 
    wszString[wcsLen] = '\0'; //最后加上'\0' 
	//   ::MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK); //unicode版的MessageBox API 
	
    // unicode to ansi 
    int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL); 
    
    char* szAnsi = new char[ansiLen + 1]; //同上，分配空间要给'\0'留个空间 
    //转换 //unicode版对应的strlen是wcslen 
    ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL); 
    szAnsi[ansiLen] = '\0'; //最后加上'\0' 
	//    ::MessageBoxA(GetSafeHwnd(), szAnsi, szAnsi, MB_OK); 	//Ansi版的MessageBox API 
	
	char* p=szAnsi;
	char* p2=szAnsi;
	char* p3=szAnsi;
	char* TDurl=NULL;
	int i=0;//curlistitem;
	
	if(p)
	{
		p2=strstr(p,"<form name=\"downLoad_wt\" id=\"downLoad\" method=\"post\" action=\"");
		//AfxMessageBox(p2);
		if(!p2)return 0;
		p2+=lstrlen("<form name=\"downLoad_wt\" id=\"downLoad\" method=\"post\" action=\"");
		p3=strstr(p2,"\" target=\"iframe_data\">");
		if(!p3)return 0;
		TDurl=new char[p3-p2+1];
		strncpy(TDurl,p2,p3-p2);
		TDurl[p3-p2]=0;
		//::MessageBoxA(GetSafeHwnd(), TDurl, "下载地址", MB_OK); 
//		AfxMessageBox(TDurl);
//		GetSourceTextFile(TDurl);
//		AddTD(TDurl);
		CString sTDurl=TDurl;
		CString httpurl= sTDurl.Mid(lstrlen("http://d.download.csdn.net"));
		AfxMessageBox(httpurl);
		httppost(httpurl,"ds=wt");
	}
	return 1;
}


//-------------------------------------------------------//
//#import "C:\\td\\ComDlls\\ThunderAgent_007.dll" //或者叫ThunderAgent_now.dll
//using namespace THUNDERAGENTLib;  //从ThunderAgent_007.tlh里知道THUNDERAGENTLib
									//ThunderAgent_007.tlh是编译以后在debug目录出现
//-------------------------------------------------------//

#include "thunderagent_007.h"
int CCSDNDlg::AddTD(CString TDurl) 
{
	// TODO: Add your control notification handler code here
	CoInitialize(0);
	IAgent2 ThunderEng;
	ThunderEng.CreateDispatch(_T("THUNDERAGENT.Agent"));
	ThunderEng.m_bAutoRelease = true;
	ThunderEng.AddTask(TDurl,"","","","",1,0,5);//添加下载任务
	ThunderEng.CommitTasks2(1);//提交下载任务
	return 1;
}
CString refurl;
void CCSDNDlg::OnBUTTONgoTD() 
{
	// TODO: Add your control notification handler code here
	CString strurl;
	//strurl.Format("%d",m_mylist.GetItemCount());
	//AfxMessageBox(strurl);
	
	for(int i=0;i<m_mylist.GetItemCount();i++)
	{
		if (m_mylist.GetCheck(i))
		{
			strurl.Format("http://d.download.csdn.net/down/%s/%s",
				m_mylist.GetItemText(i,0),m_mylist.GetItemText(i,2));
		//	AfxMessageBox(strurl);
			refurl=strurl;
			BOOL re=GetSourceTextFile(strurl);
			if (re)
			{
				GetData2();
			}
		}
		
	}
}

void CCSDNDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
		CString strurl;
	//strurl.Format("%d",m_mylist.GetItemCount());
	//AfxMessageBox(strurl);
	
	for(int i=0;i<m_mylist.GetItemCount();i++)
	{
		if (m_mylist.GetCheck(i))
		{
			strurl.Format("http://download.csdn.net/index.php/rest/users/addscoreByratings/%s&jsoncallback=?",
				m_mylist.GetItemText(i,0));
		//	AfxMessageBox(strurl);
			BOOL re=GetSourceTextFile(strurl);
			if (re)
			{
				//GetData2();
				AfxMessageBox(m_mylist.GetItemText(i,0));
			}
		}
		
	}
}

void CCSDNDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_mylist.DeleteAllItems();
}

void CCSDNDlg::OnGetScore() 
{
	// TODO: Add your control notification handler code here
	CString codeurl;
	codeurl.Format("http://download.csdn.net/index.php/rest/users/getcurruserinfo?jsoncallback=?%d",rand()%200000+10000);
	BOOL re=GetSourceTextFile(codeurl);
	if (!re)return;
	
	bufMemFile.SeekToBegin();
	int buflen=bufMemFile.GetLength();
	if(!buflen)return;
	char*szU8=new char[buflen+1];
	bufMemFile.ReadHuge(szU8,buflen);
	szU8[buflen]=0;

	//UTF8 to Unicode 
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0); //预转换，得到所需空间的大小 
    wchar_t* wszString = new wchar_t[wcsLen + 1]; //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间 
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen); //转换 
    wszString[wcsLen] = '\0'; //最后加上'\0' 
	//   ::MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK); //unicode版的MessageBox API 
	
    // unicode to ansi 
    int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL); 
    
    char* szAnsi = new char[ansiLen + 1]; //同上，分配空间要给'\0'留个空间 
    //转换 //unicode版对应的strlen是wcslen 
    ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL); 
    szAnsi[ansiLen] = '\0'; //最后加上'\0' 
	//    ::MessageBoxA(GetSafeHwnd(), szAnsi, szAnsi, MB_OK); 	//Ansi版的MessageBox API 
	
	char* p=szAnsi;
	char* p2=szAnsi;
	char* p3=szAnsi;
	char* TDurl=NULL;
	int i=0;//curlistitem;
	
	if(p)
	{
		if (strstr(p,"username\":\"\"")) AfxMessageBox("请重新登录！");
		p2=strstr(p,"username\":\"");
//		AfxMessageBox(p2);
		if(!p2)return;
		p2+=lstrlen("username\":\"");
		p3=strstr(p2,"\",\"add_money");
		if(!p3)return;
		char* username=new char[p3-p2+1];
		strncpy(username,p2,p3-p2);
		username[p3-p2]=0;
//		AfxMessageBox(username); 
		
		p2=strstr(p3,"\"score\":");
		if(!p2)return;
//		AfxMessageBox(p2);
		p2+=lstrlen("\"score\":");
//		AfxMessageBox(p2);
		p3=strstr(p2,",");
//		AfxMessageBox(p3);
		if(!p3)return;
		char* score=new char[p3-p2+1];
		strncpy(score,p2,p3-p2);
		score[p3-p2]=0;
//		AfxMessageBox(score);
		::SetDlgItemText(m_hWnd,IDC_STATIC_score,"登录用户："+CString(username)+"\t积分："+CString(score));
	}

}

void CCSDNDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CLoginDlg logindlg;
	logindlg.DoModal();
}

void CCSDNDlg::OnSelchangeCOMBOpagepre() 
{
	// TODO: Add your control notification handler code here
	CString pageprestr;
	UpdateData();
	GetDlgItemText(IDC_COMBO_pagepre,pageprestr);//每批页数
	AfxMessageBox(pageprestr);
	pagepreint=atoi(pageprestr);
	if(m_keyword=="") return;
	addlist();
}

int CCSDNDlg::httppost(CString theUrl,CString theData)
{
	CString str;
//	CString theUrl2="/index.php/new/download/dodownload/2058487/lin379184514/9e30e1c76d111c62969aa3f86a3e5f80";
    try  
    {   
        CInternetSession Session ;    
        CHttpConnection *pHttpConnect = Session.GetHttpConnection("d.download.csdn.net") ;   
        if( pHttpConnect )   
        {   
            CHttpFile* 	pFile = pHttpConnect->OpenRequest( CHttpConnection::HTTP_VERB_POST,    
                theUrl,NULL,1,NULL,NULL,INTERNET_FLAG_NO_AUTO_REDIRECT);  
            CFile file;  
				char		buff[512];
            file.Open("Test33.htm",CFile::modeCreate | CFile::modeWrite,NULL); 
            if (pFile)   
            {      
                pFile->AddRequestHeaders("Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, */*\r\nReferer: "+refurl+"\r\nAccept-Language: zh-cn\r\nContent-Type: application/x-www-form-urlencoded\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1)\r\nHost: d.download.csdn.net\r\nContent-Length: 5\r\nConnection: Keep-Alive\r\nPragma: no-cache\r\n"); 
				pFile->SendRequestEx(theData.GetLength());

                pFile->WriteString(theData);   
                pFile->SendRequest();   
				CString szTemp;
pFile->QueryInfo(HTTP_QUERY_LOCATION,   szTemp);       
AfxMessageBox(szTemp);              
                // 返回的HTML   
                CString s ;   
                while (pFile->Read(buff,512))   
                 //   str += s ;   
				file.Write(buff,512); 
                //MessageBox(str);   
               	file.Flush();
	file.Close();     
                pFile->Close();   
                delete pFile ;   
            }   
/*

	CFile		*pFile,out; 
	char		buff[512];
	
	// 产生八位随机数数组成验证码
	int			nRand1 = rand()%100000+10000;
	int			nRand2 = rand()%200000+10000;

	strUrl.Format("http://passport.csdn.net/ShowExPwd.aspx?temp=%d%d",nRand1,nRand2);

	pFile = session.OpenURL(strUrl); 
	out.Open("code.bmp", CFile::modeCreate | CFile::modeWrite); 
	while(pFile->Read(buff,512))
	{ 
		out.Write(buff,512); 
	} 
	out.Flush();
	out.Close(); 
	
*/
              
            file.Flush();   
            file.Close();   
  
            pHttpConnect->Close() ;   
            delete pHttpConnect ;   
        } 
		/*
        wchar_t*    pWChar = NULL;   
        DWORD       nLen1;   
           
        // 将网页UTF-8格式编码转换成Unicode   
        nLen1   = MultiByteToWideChar(CP_UTF8,0,str,str.GetLength(),pWChar,0);   
        pWChar  = new wchar_t[nLen1 + 1];   
        memset(pWChar,0,(nLen1 + 1 ) * sizeof(wchar_t));   
        MultiByteToWideChar(CP_UTF8,0,str,str.GetLength(),pWChar,nLen1);   
           
        char*   pChar = NULL;   
        DWORD   nLen2;   
           
        nLen2 = WideCharToMultiByte(CP_ACP,0,pWChar,nLen1,pChar,0,NULL,NULL);    
        pChar = new char[nLen2 + 1];   
        memset(pChar,0, nLen2 + 1);   
        WideCharToMultiByte(CP_ACP,0,pWChar,nLen1,pChar,nLen2,NULL,NULL);   
           
        // 查找登录时服务器时返回的信息   
        str.Format("%s",pChar);   
        MessageBox(str);   
		*/
	}
    catch( CInternetException *e )   
    {   
        e->Delete();       
    }	
	return 1;
}
