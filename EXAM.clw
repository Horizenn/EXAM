; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTextGrade
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EXAM.h"

ClassCount=12
Class1=CEXAMApp
Class2=CEXAMDlg
Class3=CAboutDlg

ResourceCount=12
Resource1=IDD_EXAMRESULT
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CExamOnline
Resource4=IDD_ADDTEST_DIALOG
Class5=CExamInfo
Resource5=IDD_TEXTMANAGE
Class6=CEXAMRESULT
Resource6=IDD_LOGIN
Class7=CRegister
Resource7=IDD_EXAMINFO
Class8=CTextManage
Resource8=IDD_EXAMONLINE
Class9=CAddTest
Resource9=IDD_ADDSUBJECT_DIALOG
Class10=CAddSubject
Resource10=IDD_TESTCHANGE_DIALOG
Class11=CTestChange
Resource11=IDD_REGISTER
Class12=CTextGrade
Resource12=IDD_TEXTGRADE_DIALOG

[CLS:CEXAMApp]
Type=0
HeaderFile=EXAM.h
ImplementationFile=EXAM.cpp
Filter=N

[CLS:CEXAMDlg]
Type=0
HeaderFile=EXAMDlg.h
ImplementationFile=EXAMDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CEXAMDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=EXAMDlg.h
ImplementationFile=EXAMDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LOGIN]
Type=1
Class=CEXAMDlg
ControlCount=9
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_BUTTON3,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO1,combobox,1344340226
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631584

[DLG:IDD_EXAMONLINE]
Type=1
Class=CExamOnline
ControlCount=10
Control1=IDC_STATIC,button,1342178055
Control2=IDC_STATIC2,static,1342308865
Control3=IDC_STATIC1,static,1350697473
Control4=IDC_STATIC,button,1342178055
Control5=IDC_RADIO_A,button,1342185225
Control6=IDC_RADIO_B,button,1342185225
Control7=IDC_RADIO_C,button,1342185225
Control8=IDC_RADIO_D,button,1342185225
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_BUTTON4,button,1342242816

[CLS:CExamOnline]
Type=0
HeaderFile=ExamOnline.h
ImplementationFile=ExamOnline.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CExamOnline

[CLS:CExamInfo]
Type=0
HeaderFile=ExamInfo.h
ImplementationFile=ExamInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SUBJECTCOMBO

[DLG:IDD_EXAMINFO]
Type=1
Class=CExamInfo
ControlCount=5
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_SUBJECTCOMBO,combobox,1344340227
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_BUTTON2,button,1342242816

[CLS:CEXAMRESULT]
Type=0
HeaderFile=EXAMRESULT.h
ImplementationFile=EXAMRESULT.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEXAMRESULT

[DLG:IDD_EXAMRESULT]
Type=1
Class=CEXAMRESULT
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_STATIC1,static,1342308865
Control3=IDC_STATIC2,static,1342308865
Control4=IDC_STATIC3,static,1342308865
Control5=IDC_STATIC4,static,1342308865
Control6=IDC_STATIC5,static,1342308865

[DLG:IDD_REGISTER]
Type=1
Class=CRegister
ControlCount=25
Control1=IDC_STATIC,static,1342308353
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631584
Control10=IDC_EDIT3,edit,1350631584
Control11=IDC_EDIT4,edit,1350631552
Control12=IDC_EDIT5,edit,1350631552
Control13=IDC_BUTTON1,button,1342242816
Control14=IDC_STATIC1,static,1342308352
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT6,edit,1350631552
Control20=IDC_EDIT7,edit,1350631552
Control21=IDC_RADIO1,button,1342177289
Control22=IDC_RADIO2,button,1342177289
Control23=IDC_BUTTON2,button,1342242816
Control24=IDC_BUTTON3,button,1342242816
Control25=IDC_STATIC,static,1342308865

[CLS:CRegister]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STATIC1

[DLG:IDD_TEXTMANAGE]
Type=1
Class=CTextManage
ControlCount=7
Control1=IDC_TREE1,SysTreeView32,1350631431
Control2=IDC_LIST1,SysListView32,1350631425
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON5,button,1342242816

[CLS:CTextManage]
Type=0
HeaderFile=TextManage.h
ImplementationFile=TextManage.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TREE1

[DLG:IDD_ADDTEST_DIALOG]
Type=1
Class=CAddTest
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=IDC_STATIC,static,1342308865
Control9=IDC_EDIT1,edit,1350631552
Control10=IDC_EDIT2,edit,1350631552
Control11=IDC_EDIT3,edit,1350631552
Control12=IDC_EDIT4,edit,1350631552
Control13=IDC_EDIT5,edit,1350631552
Control14=IDC_EDIT6,edit,1350631552
Control15=IDC_STATIC,static,1342308865
Control16=IDC_EDIT7,edit,1350631552

[CLS:CAddTest]
Type=0
HeaderFile=AddTest.h
ImplementationFile=AddTest.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_ADDSUBJECT_DIALOG]
Type=1
Class=CAddSubject
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308353
Control3=IDOK,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[CLS:CAddSubject]
Type=0
HeaderFile=AddSubject.h
ImplementationFile=AddSubject.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_TESTCHANGE_DIALOG]
Type=1
Class=CTestChange
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=IDC_STATIC,static,1342308865
Control9=IDC_EDIT1,edit,1350631552
Control10=IDC_EDIT2,edit,1350631552
Control11=IDC_EDIT3,edit,1350631552
Control12=IDC_EDIT4,edit,1350631552
Control13=IDC_EDIT5,edit,1350631552
Control14=IDC_EDIT6,edit,1350631552

[CLS:CTestChange]
Type=0
HeaderFile=TestChange.h
ImplementationFile=TestChange.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_TEXTGRADE_DIALOG]
Type=1
Class=CTextGrade
ControlCount=6
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816

[CLS:CTextGrade]
Type=0
HeaderFile=TextGrade.h
ImplementationFile=TextGrade.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

