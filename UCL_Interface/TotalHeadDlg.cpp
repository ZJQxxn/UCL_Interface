// TotalHeadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UCL_Interface.h"
#include "TotalHeadDlg.h"
#include "afxdialogex.h"
#include "global.h"


// TotalHeadDlg dialog

IMPLEMENT_DYNAMIC(TotalHeadDlg, CDialogEx)

TotalHeadDlg::TotalHeadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TotalHeadDlg::IDD, pParent)
	, m_decodeRule(_T(""))
	, m_language(_T(""))
	, m_totalLength(0)
	, m_elementNum(0)
{

}

TotalHeadDlg::~TotalHeadDlg()
{
}

void TotalHeadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DECODE_RULE, m_decodeRule);
	DDX_Text(pDX, IDC_EDIT_LANGUAGE, m_language);
	//  DDX_Text(pDX, IDC_EDIT_SET_NUMBER, m_setNumber);
	//  DDX_Text(pDX, IDC_EDIT_TOTAL_LENGTH, m_totalLength);
	DDX_Text(pDX, IDC_EDIT_TOTAL_LENGTH, m_totalLength);
	DDX_Text(pDX, IDC_EDIT_SET_NUMBER, m_elementNum);
}


BEGIN_MESSAGE_MAP(TotalHeadDlg, CDialogEx)
	ON_BN_CLICKED(ID_OK, &TotalHeadDlg::OnClickedOk)
END_MESSAGE_MAP()


// TotalHeadDlg message handlers


BOOL TotalHeadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//展示总头部内容
	m_decodeRule = totalHead->getAnalyseRule().c_str();
	m_language = totalHead->getSetType().c_str();
	m_totalLength = totalHead->getSetLength();
	m_elementNum = totalHead->getElementNum();
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void TotalHeadDlg::OnClickedOk()
{
	OnCancel();
}
