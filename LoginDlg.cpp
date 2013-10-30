// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CSDN����Ѹ������.h"
#include "LoginDlg.h"

#include <afxinet.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_strUser = _T("anlin_test");
	m_strPassword = _T("lin379184514");
	m_strCode = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT_USER, m_strUser);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_BTN_LOGIN, OnBtnLogin)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)
	ON_WM_CLOSE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers


/////////////////////////////////////////////////////////////////////////////
// CShowImageDlg message handlers

IStream		* pStream  = NULL;
IPicture	* pPicture = NULL;


void CLoginDlg::DownURLImage()
{
	CInternetSession	session;
	CString		strUrl;
	CFile		*pFile,out; 
	char		buff[512];
	
	// ������λ������������֤��
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
	ShowImage();		// ������ʾ��֤��
	Invalidate();
}


void CLoginDlg::ShowImage()
{
	::CoInitialize(NULL);			// ��ʼ��COM 
	HRESULT	hr; 
	CFile	file;
	CString	strPath;
	CPaintDC dc(this);
	

	file.Open("code.bmp", CFile::modeRead | CFile::shareDenyNone);

	DWORD	dwSize = file.GetLength(); 
	HGLOBAL hMem = ::GlobalAlloc( GMEM_MOVEABLE, dwSize ); 
	LPVOID	lpBuf = ::GlobalLock( hMem ); 

	file.ReadHuge( lpBuf, dwSize ); 
	file.Close(); 
	::GlobalUnlock( hMem ); 
	
	// ��HGLOBAL�õ�IStream������TRUE ��ʾ�ͷ�IStream��ͬʱ���ͷ��ڴ� 
	hr = ::CreateStreamOnHGlobal(hMem,TRUE,&pStream ); 
	ASSERT(SUCCEEDED(hr)); 
	
	hr = ::OleLoadPicture(pStream, dwSize, TRUE, IID_IPicture,(LPVOID *)&pPicture); 
	ASSERT(hr==S_OK); 
	
	long nWidth,nHeight;				// ��� MM_HIMETRICģʽ����λ��0.01���� 
	pPicture->get_Width( &nWidth );		// �� 
	pPicture->get_Height( &nHeight );	// �� 

	CSize sz(nWidth,nHeight);			// ԭ����ʾ
	dc.HIMETRICtoDP(&sz);				// ת��MM_HIMETRICģʽ��λΪMM_TEXT���ص�λ 
	
	hr=pPicture->Render(dc.m_hDC,10,100,sz.cx,sz.cy,0,nHeight,nWidth,-nHeight,NULL); 
	CRect rect(10,100,sz.cx + 10,sz.cy + 100);

	// ��ͼƬ���򱣴棬�Ա����ֻˢ��ͼƬ����
	m_PicRect = rect;
	if(pPicture)						// �ͷ�IPictureָ��
		pPicture->Release();
	if(pStream)							// �ͷ�IStreamָ�룬ͬʱ�ͷ�hMem
		pStream->Release();
	::CoUninitialize();
}



void CLoginDlg::OnBtnLogin() 
{
	// TODO: Add your control notification handler code here
	CString m_strCookies;
	CString m_strClientKey;

    UpdateData(TRUE);   
    if(m_strUser.IsEmpty())   
    {   
        MessageBox("�û�������Ϊ�գ�","��ʾ",MB_ICONERROR | MB_OK);   
        (CEdit*)GetDlgItem(IDC_EDIT_USER)->SetFocus();    
        return;   
    }   
    if( m_strPassword.IsEmpty())   
    {   
        MessageBox("���벻��Ϊ�գ�","��ʾ",MB_ICONERROR | MB_OK);   
        (CEdit*)GetDlgItem(IDC_EDIT_PASSWORD)->SetFocus();    
        return;   
    }   
    CString str;   
    try  
    {   
        CInternetSession Session ;    
        CHttpConnection *pHttpConnect = Session.GetHttpConnection("passport.csdn.net") ;   
        if( pHttpConnect )   
        {   
            CHttpFile* pFile = pHttpConnect->OpenRequest( CHttpConnection::HTTP_VERB_GET,    
                _T("/UserLogin.aspx"),   
                NULL,   
                1,   
                NULL,   
                NULL,   
                INTERNET_FLAG_NO_COOKIES );   
            // ��ȡCOOKIE ClientKeyֵ   
            CInternetSession    Session;   
            Session.OpenURL("http://passport.csdn.net/UserLogin.aspx");   
            if(!Session.GetCookie("http://passport.csdn.net/UserLogin.aspx",
				_T("ClientKey"),m_strCookies))   
            {   
                MessageBox("��ȡCookiesʱ����");   
                return;   
            }   
            CString strKey  = m_strCookies;   
            int     result  = strKey.Find("ClientKey=",0);   
            m_strClientKey  = strKey.Mid(result+10,36);   
  AfxMessageBox(m_strClientKey);//return;
            UpdateData(TRUE);   
			pFile = pHttpConnect->OpenRequest( CHttpConnection::HTTP_VERB_POST,    
                _T("/UserLogin.aspx")); 
            CString szFormData = "__EVENTTARGET=\
&__EVENTARGUMENT=\
&__VIEWSTATE=%2FwEPDwULLTE3NDM5MjY5MDAPZBYCZg9kFgQCAQ8WAh4EVGV4dAUM55So5oi355m75b2VZAICD2QWAgIDD2QWAgIBDxYCHgdWaXNpYmxlaGQYAQUeX19Db250cm9sc1JlcXVpcmVQb3N0QmFja0tleV9fFgIFHmN0bDAwJENQSF9Db250ZW50JGNiX1NhdmVTdGF0ZQUdY3RsMDAkQ1BIX0NvbnRlbnQkSW1hZ2VfTG9naW5UU%2BFNyJLPa6ulSvPQKhs%2Fg%2BB2DQ%3D%3D\
&ctl00%24CPH_Content%24tb_LoginNameOrLoginEmail="
+m_strUser
+"&ctl00%24CPH_Content%24tb_Password="
+m_strPassword
+"&ctl00%24CPH_Content%24tb_ExPwd="
+m_strCode
+"&ClientKey="
+m_strClientKey
+"&from=http%3A%2F%2Fhi.csdn.net%2F\
&PrePage=http%3A%2F%2Fcsdn.net\
&MailParameters=\
&ctl00%24CPH_Content%24Image_Login.x=39\
&ctl00%24CPH_Content%24Image_Login.y=7";
            if (pFile)   
            {      
//                pFile->AddRequestHeaders("Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, */*\r\n");   
//                pFile->AddRequestHeaders("Referer: http://passport.csdn.net/UserLogin.aspx\r\n");   
//                pFile->AddRequestHeaders("Accept-Language: zh-cn\r\n");   
//                pFile->AddRequestHeaders("Content-Type: application/x-www-form-urlencoded\r\n");   
//                pFile->AddRequestHeaders("User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1)\r\n");   
//                pFile->AddRequestHeaders("Host: passport.csdn.net\r\n");   
//                pFile->AddRequestHeaders("Connection: Keep-Alive\r\n"); 
//				pFile->AddRequestHeaders("Pragma: no-cache\r\n"); 

                pFile->AddRequestHeaders("Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, */*\r\nReferer: http://passport.csdn.net/UserLogin.aspx\r\nAccept-Language: zh-cn\r\nContent-Type: application/x-www-form-urlencoded\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1)\r\nHost: passport.csdn.net\r\nConnection: Keep-Alive\r\nPragma: no-cache\r\n"); 
				pFile->SendRequestEx(szFormData.GetLength());
AfxMessageBox(szFormData);
                pFile->WriteString(szFormData);   
                pFile->SendRequest();   
                   
                // ���ص�HTML   
                CString s ;   
                while (pFile->ReadString(s))   
                    str += s ;   
                //MessageBox(str);   
                   
                pFile->Close();   
                delete pFile ;   
            }   
            CFile file;   
            file.Open("Test.htm",CFile::modeCreate | CFile::modeWrite,NULL);   
            file.Write(str,str.GetLength());   
            file.Flush();   
            file.Close();   
  
            pHttpConnect->Close() ;   
            delete pHttpConnect ;   
        }   
        wchar_t*    pWChar = NULL;   
        DWORD       nLen1;   
           
        // ����ҳUTF-8��ʽ����ת����Unicode   
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
           
        // ���ҵ�¼ʱ������ʱ���ص���Ϣ   
        str.Format("%s",pChar);   
        MessageBox(str);   
    }   
    catch( CInternetException *e )   
    {   
        e->Delete();       
    }	
}


BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_STATIC1)->GetWindowRect(&m_pRectLink);
	ScreenToClient(&m_pRectLink);
	DownURLImage();		// ������֤��

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnPaint() 
{
	ShowImage();		// ������ʾ��֤��
}

void CLoginDlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here
	SendMessage(WM_CLOSE);
}

void CLoginDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DeleteFile("code.bmp"); // ɾ����֤�����ʱ�ļ�
	CDialog::OnClose();
}

void CLoginDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (point.x>m_pRectLink.left&&point.x<m_pRectLink.right&&point.y>m_pRectLink.top&&point.y<m_pRectLink.bottom)
	{
		if (nFlags==MK_LBUTTON)	// �����̬����,������֤��
		{
			DownURLImage();		

		}
	}
	if (point.x>m_PicRect.left&&point.x<m_PicRect.right&&point.y>m_PicRect.top&&point.y<m_PicRect.bottom)
	{
		if (nFlags==MK_LBUTTON)	// ���ͼƬ,������֤��
		{
			DownURLImage();		

		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}
