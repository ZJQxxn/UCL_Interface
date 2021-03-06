
// UCL_InterfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UCL_Interface.h"
#include "UCL_InterfaceDlg.h"
#include "afxdialogex.h"
#include "global.h"
#include "Code_Exp.h"
#include <iterator>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUCL_InterfaceDlg dialog



CUCL_InterfaceDlg::CUCL_InterfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUCL_InterfaceDlg::IDD, pParent)
	, m_filename(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUCL_InterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_FILENAME, m_filename);
	//  DDX_Text(pDX, IDC_FILENAME, m_filename);
	DDX_Text(pDX, IDC_FILENAME, m_filename);
}

BEGIN_MESSAGE_MAP(CUCL_InterfaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &CUCL_InterfaceDlg::OnClickedOpen)
	ON_BN_CLICKED(IDC_RESET, &CUCL_InterfaceDlg::OnClickedReset)
	ON_BN_CLICKED(IDC_VERSION, &CUCL_InterfaceDlg::OnClickedVersion)
	ON_BN_CLICKED(IDC_TYPE_OF_MEDIA, &CUCL_InterfaceDlg::OnClickedTypeOfMedia)
	ON_BN_CLICKED(IDC_FLAG, &CUCL_InterfaceDlg::OnClickedFlag)
	ON_BN_CLICKED(IDC_DECODE_RULE, &CUCL_InterfaceDlg::OnClickedDecodeRule)
	ON_BN_CLICKED(IDC_SOURCE_OF_CONTENT, &CUCL_InterfaceDlg::OnClickedSourceOfContent)
	ON_BN_CLICKED(IDC_CATEGORY, &CUCL_InterfaceDlg::OnClickedCategory)
	ON_BN_CLICKED(IDC_SUBCATEGORY, &CUCL_InterfaceDlg::OnClickedSubcategory)
	ON_BN_CLICKED(IDC_TOPIC, &CUCL_InterfaceDlg::OnClickedTopic)
	ON_BN_CLICKED(IDC_TYPE_OF_CONTENT, &CUCL_InterfaceDlg::OnClickedTypeOfContent)
	ON_BN_CLICKED(IDC_SECURITY_LEVEL, &CUCL_InterfaceDlg::OnClickedSecurityLevel)
	ON_BN_CLICKED(IDC_TIME_STAMP, &CUCL_InterfaceDlg::OnClickedTimeStamp)
	ON_BN_CLICKED(IDC_SERIAL_NUMBER, &CUCL_InterfaceDlg::OnClickedSerialNumber)
	ON_BN_CLICKED(IDC_CHECKSUM, &CUCL_InterfaceDlg::OnClickedChecksum)
	ON_BN_CLICKED(IDC_TOTAL_HEAD, &CUCL_InterfaceDlg::OnClickedTotalHead)
	ON_BN_CLICKED(IDC_CDPS, &CUCL_InterfaceDlg::OnClickedCdps)
	ON_BN_CLICKED(IDC_CGPS, &CUCL_InterfaceDlg::OnClickedCgps)
	ON_BN_CLICKED(IDC_Priority_Policy, &CUCL_InterfaceDlg::OnClickedPriorityPolicy)
	ON_BN_CLICKED(IDC_LANGUAGE, &CUCL_InterfaceDlg::OnClickedLanguage)
	ON_BN_CLICKED(IDC_CONTENT_LENGTH, &CUCL_InterfaceDlg::OnClickedContentLength)
	ON_BN_CLICKED(IDC_MULTIPLEX_BYTES, &CUCL_InterfaceDlg::OnClickedMultiplexBytes)
END_MESSAGE_MAP()


// CUCL_InterfaceDlg message handlers

BOOL CUCL_InterfaceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	m_filename = _T("F:\\ucl展示\\UCL_Interface\\UCL.txt");
	UpdateData(false);

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUCL_InterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUCL_InterfaceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUCL_InterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUCL_InterfaceDlg::OnClickedOpen()
{
	UpdateData(true);
	CFileFind fileFind;
	if (fileFind.FindFile(m_filename))
	{
		ucl = new UCL(wstring_to_string(m_filename.GetBuffer(0)));				//读取UCL包，保存在ucl中
		vector<string>::iterator head_iterator = ucl->getProperties().begin();
		totalHead = new TotalHead(head_iterator);								//划分总头部
		head_iterator = totalHead->get_Content().begin();						
		CDPSHead = new SetHead(head_iterator);
		advance(head_iterator, CDPSHead->getSetLength());
		CGPSHead = new SetHead(head_iterator);

		vector<string>::iterator elem_iterator;
		//划分CDPS集合元素
		elem_iterator = CDPSHead->get_Content().begin();
		for (int elemCount = 0; elemCount < CDPSHead->getElementNum(); ++elemCount)
		{
			Element* newElem = new Element(elem_iterator);

			CDPSSet.push_back(*newElem);
			advance(elem_iterator, newElem->getElementLength());
		}
		//划分CGPS集合元素
		elem_iterator = CGPSHead->get_Content().begin();
		for (int elemCount = 0; elemCount < CGPSHead->getElementNum(); ++elemCount)
		{
			Element* newElem = new Element(elem_iterator);
			CGPSSet.push_back(*newElem);
			advance(elem_iterator, newElem->getElementLength());
		}
		MessageBox(_T("UCL包已打开"), _T("打开"), 0);
	}
	else                                        
	{
		m_filename = _T("F:\\ucl展示\\UCL_Interface\\UCL.txt");
		UpdateData(false);
		AfxMessageBox(_T("文件不存在,回复为默认值"));
	}
}

void CUCL_InterfaceDlg::OnClickedReset()
{
	m_filename = _T("F:\\ucl展示\\UCL_Interface\\UCL.txt");
	UpdateData(false);
	MessageBox(_T("文件名重置为默认值"),_T("重置"),0);
}

void CUCL_InterfaceDlg::OnClickedVersion()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString version(explainVersion(ucl->getCode()).c_str());
		MessageBox(version, _T("版本"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedTypeOfMedia()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString TM(explainTM(ucl->getCode()).c_str());
		MessageBox(TM, _T("媒体类型"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedPriorityPolicy()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString PP(explainPP(ucl->getCode()).c_str());
		MessageBox(PP, _T("优先级与策略"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedFlag()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString flag(explainFlag(ucl->getCode()).c_str());
		MessageBox(flag, _T("标志"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedDecodeRule()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString parseRule(explainParseRule(ucl->getCode()).c_str());
		MessageBox(parseRule, _T("解码规则"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedSourceOfContent()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString SC(explainSC(ucl->getCode()).c_str());
		MessageBox(SC, _T("内容来源"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedCategory()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString category(explainCategory(ucl->getCode()).c_str());
		MessageBox(category, _T("一级类别"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedSubcategory()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString subcategory(explainSubcategory(ucl->getCode()).c_str());
		MessageBox(subcategory, _T("二级类别"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedTopic()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString topic(explainTopic(ucl->getCode()).c_str());
		MessageBox(topic, _T("话题"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedTypeOfContent()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString CT(explainCT(ucl->getCode()).c_str());
		MessageBox(CT, _T("内容版权与类型"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedSecurityLevel()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString SELC(explainSELC(ucl->getCode()).c_str());
		MessageBox(SELC, _T("安全能级码"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedLanguage()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString language(explainLanguage(ucl->getCode()).c_str());
		MessageBox(language, _T("语种"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedContentLength()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString SoC(explainSoC(ucl->getCode()).c_str());
		MessageBox(SoC, _T("内容长度"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedTimeStamp()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString timestamp(explainTimestamp(ucl->getCode()).c_str());
		MessageBox(timestamp, _T("时间戳"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedSerialNumber()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		int tmp=0;
		CString SN(explainSN(ucl->getCode(),tmp).c_str());
		//SN = CString("")
		MessageBox(SN, _T("顺序号"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedMultiplexBytes()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString MB(explainMB(ucl->getCode()).c_str());
		MessageBox(MB, _T("复用字节段"), 0);
	}
}


void CUCL_InterfaceDlg::OnClickedChecksum()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		CString CC(explainCC(ucl->getCode()).c_str());
		MessageBox(CC ,_T("代码校验和"), 0);
	}
}

void CUCL_InterfaceDlg::OnClickedTotalHead()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		totalHeadDlg.DoModal();
	}
}

void CUCL_InterfaceDlg::OnClickedCdps()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		cdpsDlg.DoModal();
	}
	
}

void CUCL_InterfaceDlg::OnClickedCgps()
{
	if (ucl == nullptr)
	{
		AfxMessageBox(_T("未打开ucl包"));
	}
	else
	{
		cgpsDlg.DoModal();
	}
}



