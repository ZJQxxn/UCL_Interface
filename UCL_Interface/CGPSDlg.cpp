// CGPSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UCL_Interface.h"
#include "CGPSDlg.h"
#include "afxdialogex.h"
#include "global.h"
#include "YCodec.h"
#include "ElementInfo.h"


// CCGPSDlg dialog

IMPLEMENT_DYNAMIC(CCGPSDlg, CDialogEx)

CCGPSDlg::CCGPSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCGPSDlg::IDD, pParent)
{

}

CCGPSDlg::~CCGPSDlg()
{
}

void CCGPSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST_CGPS, m_List_CGPS);
}


BEGIN_MESSAGE_MAP(CCGPSDlg, CDialogEx)
	//ON_BN_CLICKED(ID_OK, &CCGPSDlg::OnClickedOk)
	//ON_BN_CLICKED(IDC_SHOW_DETAILS_CGPS, &CCGPSDlg::OnClickedShowDetailsCgps)
	//ON_BN_CLICKED(IDC_BUTTON_Signature_of_UCL, &CCGPSDlg::OnBnClickedButtonSignatureofUcl)
	ON_BN_CLICKED(IDC_BUTTON_Provenance, &CCGPSDlg::OnClickedButtonProvenance)
	ON_BN_CLICKED(IDC_BUTTON_Content_ID, &CCGPSDlg::OnClickedButtonContentId)
	ON_BN_CLICKED(IDC_BUTTON_Propagation_Path, &CCGPSDlg::OnClickedButtonPropagationPath)
	ON_BN_CLICKED(IDC_BUTTON_Signature_of_Content, &CCGPSDlg::OnClickedButtonSignatureOfContent)
	ON_BN_CLICKED(IDC_BUTTON_Security_Level, &CCGPSDlg::OnClickedButtonSecurityLevel)
	ON_BN_CLICKED(IDC_BUTTON_Properties, &CCGPSDlg::OnClickedButtonProperties)
	ON_BN_CLICKED(IDC_BUTTON_Signature_of_UCL, &CCGPSDlg::OnClickedButtonSignatureOfUcl)
END_MESSAGE_MAP()


// CCGPSDlg message handlers



BOOL CCGPSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//获得原有风格  
	DWORD dwStyle = ::GetWindowLong(m_List_CGPS.m_hWnd, GWL_STYLE);
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
	//设置扩展风格  
	DWORD styles = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	ListView_SetExtendedListViewStyleEx(m_List_CGPS.m_hWnd, styles, styles);
	
	//对于可选的元素，如果不存在，则按钮不可点击
	int tmp;
	if (element_exist(CGPSSet,3,tmp))
	{
		GetDlgItem(IDC_BUTTON_Provenance)->EnableWindow(FALSE);
	}
	if (element_exist(CGPSSet, 4, tmp))
	{
		GetDlgItem(IDC_BUTTON_Content_ID)->EnableWindow(FALSE);
	}
	if (element_exist(CGPSSet, 15, tmp))
	{
		GetDlgItem(IDC_BUTTON_Signature_of_UCL)->EnableWindow(FALSE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//对于不同属性元素（不同按钮），产生窗口的展示内容也不同。
void CCGPSDlg::OnClickedButtonProvenance()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 3, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("内容出处");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = CGPSSet[index].provenanceForm().c_str();

	ele_info.DoModal();
}


void CCGPSDlg::OnClickedButtonContentId()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 4, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("内容ID");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	//分析内容ID形式
	CString IDForm;
	if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		IDForm = _T("内容ID为URI形式");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		IDForm = _T("内容ID为DOI形式");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0011")
	{
		IDForm = _T("内容ID为ISBN形式");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0100")
	{
		IDForm = _T("内容ID为ISRC形式");
	}
	else 
	{
		IDForm = _T("暂未定义");
	}
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = IDForm;

	ele_info.DoModal();
}


void CCGPSDlg::OnClickedButtonPropagationPath()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 5, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("传播路径");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	roughInfo.Format(_T("传播路径长度为%d"), CGPSSet[index].pathLength());
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCGPSDlg::OnClickedButtonSignatureOfContent()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 12, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("内容数字签名");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	//判断内容数字签名的算法
	CString sigAlg;
	if (CGPSSet[index].getAnalyseRule() == "0000")
	{
		sigAlg = _T("未对内容对象进行数字签名\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		sigAlg = _T("数字签名算法采用RSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		sigAlg = _T("数字签名算法采用ECDSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0011")
	{
		sigAlg = _T("数字签名算法采用DSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0100")
	{
		sigAlg = _T("数字签名算法采用ECC\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0101")
	{
		sigAlg = _T("数字签名算法采用HMAC\n");
	}
	else
	{
		sigAlg = _T("暂未定义\n");
	}
	ele_info.m_parseRule +=sigAlg;
	//判断内容摘要的算法
	CString abstractAlg(_T("数字摘要算法采用："));
	abstractAlg += CGPSSet[index].signatureStandard().c_str();
	CString roughInfo;
	roughInfo = sigAlg + abstractAlg;
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCGPSDlg::OnClickedButtonSecurityLevel()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 13, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("安全能级信息");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();

	//判断认证等级
	CString securityLevel;
	if (CGPSSet[index].getAnalyseRule() == "0000")
	{
		securityLevel = _T("UCL生成时自行标定");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		securityLevel = _T("经过第一级内容提供商认证");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		securityLevel = _T("经过第二级内容提供商认证");
	}
	else if (CGPSSet[index].getAnalyseRule() == "1110")
	{
		securityLevel = _T("经过权威内容中心认证");
	}
	else
	{
		securityLevel = _T("安全能级信息认证等级：保留");
	}
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = securityLevel;

	ele_info.DoModal();
}


void CCGPSDlg::OnClickedButtonProperties()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 5, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("内容责任链");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	roughInfo.Format(_T("责任主体个数为%d"), CGPSSet[index].pathLength());
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCGPSDlg::OnClickedButtonSignatureOfUcl()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CGPSSet, 12, index))
	{
		for (size_t i = 0; i < CGPSSet[index].get_Content().size(); ++i)
		{
			content += CGPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("UCL数字签名");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	//判断内容数字签名的算法
	CString sigAlg;
	if (CGPSSet[index].getAnalyseRule() == "0000")
	{
		sigAlg = _T("未对内容对象进行数字签名\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		sigAlg = _T("数字签名算法采用RSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		sigAlg = _T("数字签名算法采用ECDSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0011")
	{
		sigAlg = _T("数字签名算法采用DSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0100")
	{
		sigAlg = _T("数字签名算法采用ECC\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0101")
	{
		sigAlg = _T("数字签名算法采用HMAC\n");
	}
	else
	{
		sigAlg = _T("暂未定义\n");
	}
	ele_info.m_parseRule += sigAlg;
	//判断内容摘要的算法
	CString abstractAlg(_T("数字摘要算法采用："));
	abstractAlg += CGPSSet[index].signatureStandard().c_str();
	CString roughInfo;
	roughInfo = sigAlg + abstractAlg;
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}
