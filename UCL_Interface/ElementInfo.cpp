// ElementInfo.cpp : implementation file
//

#include "stdafx.h"
#include "UCL_Interface.h"
#include "ElementInfo.h"
#include "afxdialogex.h"


// ElementInfo dialog

IMPLEMENT_DYNAMIC(ElementInfo, CDialogEx)

ElementInfo::ElementInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(ElementInfo::IDD, pParent)
	, m_concrete_info(_T(""))
	, m_eleLength(0)
	, m_eleName(_T(""))
	, m_eleNum(0)
	, m_parseRule(_T(""))
	, m_roughInfo(_T(""))
{

}

ElementInfo::~ElementInfo()
{
}

void ElementInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Concrete_Info, m_concrete_info);
	DDX_Text(pDX, IDC_EDIT_EleLength, m_eleLength);
	DDX_Text(pDX, IDC_EDIT_EleName, m_eleName);
	DDX_Text(pDX, IDC_EDIT_EleNum, m_eleNum);
	DDX_Text(pDX, IDC_EDIT_ParseRule, m_parseRule);
	DDX_Text(pDX, IDC_EDIT_RoughInfo, m_roughInfo);
}


BEGIN_MESSAGE_MAP(ElementInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Detail, &ElementInfo::OnClickedButtonDetail)
END_MESSAGE_MAP()


// ElementInfo message handlers


BOOL ElementInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	smallRect = new CRect;
	largeRect = new CRect;
	CRect rectSeparator;
	GetWindowRect(largeRect);
	GetDlgItem(IDC_STATIC_Seperator)->GetWindowRect(&rectSeparator);
	
	smallRect->left = largeRect->left;
	smallRect->right = largeRect->right;
	smallRect->top = largeRect->top;
	smallRect->bottom = rectSeparator.bottom;

	SetWindowPos(NULL, 0, 0, smallRect->Width(), smallRect->Height(),SWP_NOMOVE);		//设置窗口位置
	isSmall = true;

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void ElementInfo::OnClickedButtonDetail()
{
	if (isSmall)
	{
		SetWindowPos(NULL, 0, 0, largeRect->Width(), largeRect->Height(), SWP_NOMOVE);
		isSmall = false;
		GetDlgItem(IDC_BUTTON_Detail)->SetWindowTextW(_T("收起"));
	}
	else if (!isSmall)
	{
		SetWindowPos(NULL, 0, 0, smallRect->Width(), smallRect->Height(), SWP_NOMOVE);
		isSmall = true;
		GetDlgItem(IDC_BUTTON_Detail)->SetWindowTextW(_T("展开"));
	}
	
}
