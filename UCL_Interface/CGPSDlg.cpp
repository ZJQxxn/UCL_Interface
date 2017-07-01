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
	//���ԭ�з��  
	DWORD dwStyle = ::GetWindowLong(m_List_CGPS.m_hWnd, GWL_STYLE);
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
	//������չ���  
	DWORD styles = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	ListView_SetExtendedListViewStyleEx(m_List_CGPS.m_hWnd, styles, styles);
	
	//���ڿ�ѡ��Ԫ�أ���������ڣ���ť���ɵ��
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


//���ڲ�ͬ����Ԫ�أ���ͬ��ť�����������ڵ�չʾ����Ҳ��ͬ��
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
	ele_info.m_eleName = _T("���ݳ���");
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
	ele_info.m_eleName = _T("����ID");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	//��������ID��ʽ
	CString IDForm;
	if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		IDForm = _T("����IDΪURI��ʽ");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		IDForm = _T("����IDΪDOI��ʽ");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0011")
	{
		IDForm = _T("����IDΪISBN��ʽ");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0100")
	{
		IDForm = _T("����IDΪISRC��ʽ");
	}
	else 
	{
		IDForm = _T("��δ����");
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
	ele_info.m_eleName = _T("����·��");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	roughInfo.Format(_T("����·������Ϊ%d"), CGPSSet[index].pathLength());
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
	ele_info.m_eleName = _T("��������ǩ��");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	//�ж���������ǩ�����㷨
	CString sigAlg;
	if (CGPSSet[index].getAnalyseRule() == "0000")
	{
		sigAlg = _T("δ�����ݶ����������ǩ��\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		sigAlg = _T("����ǩ���㷨����RSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		sigAlg = _T("����ǩ���㷨����ECDSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0011")
	{
		sigAlg = _T("����ǩ���㷨����DSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0100")
	{
		sigAlg = _T("����ǩ���㷨����ECC\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0101")
	{
		sigAlg = _T("����ǩ���㷨����HMAC\n");
	}
	else
	{
		sigAlg = _T("��δ����\n");
	}
	ele_info.m_parseRule +=sigAlg;
	//�ж�����ժҪ���㷨
	CString abstractAlg(_T("����ժҪ�㷨���ã�"));
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
	ele_info.m_eleName = _T("��ȫ�ܼ���Ϣ");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();

	//�ж���֤�ȼ�
	CString securityLevel;
	if (CGPSSet[index].getAnalyseRule() == "0000")
	{
		securityLevel = _T("UCL����ʱ���б궨");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		securityLevel = _T("������һ�������ṩ����֤");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		securityLevel = _T("�����ڶ��������ṩ����֤");
	}
	else if (CGPSSet[index].getAnalyseRule() == "1110")
	{
		securityLevel = _T("����Ȩ������������֤");
	}
	else
	{
		securityLevel = _T("��ȫ�ܼ���Ϣ��֤�ȼ�������");
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
	ele_info.m_eleName = _T("����������");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	ele_info.m_parseRule = CGPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	roughInfo.Format(_T("�����������Ϊ%d"), CGPSSet[index].pathLength());
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
	ele_info.m_eleName = _T("UCL����ǩ��");
	ele_info.m_eleNum = CGPSSet[index].getNum();
	ele_info.m_eleLength = CGPSSet[index].getElementLength();
	//�ж���������ǩ�����㷨
	CString sigAlg;
	if (CGPSSet[index].getAnalyseRule() == "0000")
	{
		sigAlg = _T("δ�����ݶ����������ǩ��\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0001")
	{
		sigAlg = _T("����ǩ���㷨����RSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0010")
	{
		sigAlg = _T("����ǩ���㷨����ECDSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0011")
	{
		sigAlg = _T("����ǩ���㷨����DSA\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0100")
	{
		sigAlg = _T("����ǩ���㷨����ECC\n");
	}
	else if (CGPSSet[index].getAnalyseRule() == "0101")
	{
		sigAlg = _T("����ǩ���㷨����HMAC\n");
	}
	else
	{
		sigAlg = _T("��δ����\n");
	}
	ele_info.m_parseRule += sigAlg;
	//�ж�����ժҪ���㷨
	CString abstractAlg(_T("����ժҪ�㷨���ã�"));
	abstractAlg += CGPSSet[index].signatureStandard().c_str();
	CString roughInfo;
	roughInfo = sigAlg + abstractAlg;
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}
