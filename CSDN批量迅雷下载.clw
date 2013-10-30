; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCSDNDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CSDN批量迅雷下载.h"

ClassCount=4
Class1=CCSDNApp
Class2=CCSDNDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CSDN_DIALOG
Class4=CLoginDlg
Resource4=IDD_CSDNLOGIN_DIALOG

[CLS:CCSDNApp]
Type=0
HeaderFile=CSDN批量迅雷下载.h
ImplementationFile=CSDN批量迅雷下载.cpp
Filter=N

[CLS:CCSDNDlg]
Type=0
HeaderFile=CSDN批量迅雷下载Dlg.h
ImplementationFile=CSDN批量迅雷下载Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO_pagepre

[CLS:CAboutDlg]
Type=0
HeaderFile=CSDN批量迅雷下载Dlg.h
ImplementationFile=CSDN批量迅雷下载Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CSDN_DIALOG]
Type=1
Class=?
ControlCount=17
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_search,edit,1350631552
Control3=IDC_BUTTON_gosearch,button,1342242816
Control4=IDC_LIST1,SysListView32,1350631425
Control5=IDC_bt_next,button,1342242816
Control6=IDC_bt_fw,button,1342242816
Control7=IDC_page,static,1350696960
Control8=IDC_CHECK_test,button,1342242819
Control9=IDC_BUTTON_goTD,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CHECK_ALL,button,1342242819
Control12=IDC_COMBO_pagepre,combobox,1344339971
Control13=IDC_BUTTON1,button,1342242816
Control14=IDC_BUTTON2,button,1342242816
Control15=IDC_STATIC_score,static,1350696960
Control16=IDC_BUTTON3,button,1342242816
Control17=IDC_BUTTON_login,button,1342242816

[DLG:IDD_CSDNLOGIN_DIALOG]
Type=1
Class=CLoginDlg
ControlCount=9
Control1=IDC_EDIT_USER,edit,1350631552
Control2=IDC_EDIT_PASSWORD,edit,1350631584
Control3=IDC_EDIT_CODE,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC1,static,1342308352
Control8=IDC_BTN_LOGIN,button,1342242816
Control9=IDC_BTN_EXIT,button,1342242816

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

