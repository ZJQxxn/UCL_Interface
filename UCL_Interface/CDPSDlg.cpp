// CDPSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UCL_Interface.h"
#include "CDPSDlg.h"
#include "afxdialogex.h"
#include "global.h"
#include "YCodec.h"
#include "ElementInfo.h"


// CCDPSDlg dialog

IMPLEMENT_DYNAMIC(CCDPSDlg, CDialogEx)

CCDPSDlg::CCDPSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCDPSDlg::IDD, pParent)
{

}

CCDPSDlg::~CCDPSDlg()
{
}

void CCDPSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST_CDPS, m_List_CDPS);
}


BEGIN_MESSAGE_MAP(CCDPSDlg, CDialogEx)
	//ON_BN_CLICKED(ID_OK, &CCDPSDlg::OnClickedOk)
	//ON_BN_CLICKED(IDC_SHOW_DETAILS_CDPS, &CCDPSDlg::OnClickedShowDetailsCdps)
	ON_BN_CLICKED(IDC_BUTTON_Title, &CCDPSDlg::OnBnClickedButtonTitle)
	ON_BN_CLICKED(IDC_BUTTON_KeyWord, &CCDPSDlg::OnClickedButtonKeyword)
	ON_BN_CLICKED(IDC_BUTTON_Abstract, &CCDPSDlg::OnClickedButtonAbstract)
	ON_BN_CLICKED(IDC_BUTTON_Author, &CCDPSDlg::OnClickedButtonAuthor)
	ON_BN_CLICKED(IDC_BUTTON_Entity, &CCDPSDlg::OnClickedButtonEntity)
	ON_BN_CLICKED(IDC_BUTTON_Flag, &CCDPSDlg::OnClickedButtonFlag)
	ON_BN_CLICKED(IDC_BUTTON_Copyright, &CCDPSDlg::OnClickedButtonCopyright)
	ON_BN_CLICKED(IDC_BUTTON_Originality, &CCDPSDlg::OnClickedButtonOriginality)
	ON_BN_CLICKED(IDC_BUTTON_File_Description, &CCDPSDlg::OnClickedButtonFileDescription)
	ON_BN_CLICKED(IDC_BUTTON_Related_UCL, &CCDPSDlg::OnClickedButtonRelatedUcl)
	ON_BN_CLICKED(IDC_BUTTON_Content_Object, &CCDPSDlg::OnClickedButtonContentObject)
END_MESSAGE_MAP()


// CCDPSDlg message handlers


void CCDPSDlg::OnClickedOk()
{
	OnCancel();
}


BOOL CCDPSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//���ԭ�з��  
	DWORD dwStyle = ::GetWindowLong(m_List_CDPS.m_hWnd, GWL_STYLE);
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
	//������չ���  
	DWORD styles = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;
	ListView_SetExtendedListViewStyleEx(m_List_CDPS.m_hWnd, styles, styles);


	//���ڿ�ѡ��Ԫ�أ���������ڣ���ť���ɵ��
	int tmp;
	if (!element_exist(CDPSSet, 2, tmp))
	{
		GetDlgItem(IDC_BUTTON_KeyWord)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 4, tmp))
	{
		GetDlgItem(IDC_BUTTON_Author)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 6, tmp))
	{
		GetDlgItem(IDC_BUTTON_Flag)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 7, tmp))
	{
		GetDlgItem(IDC_BUTTON_Copyright)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 8, tmp))
	{
		GetDlgItem(IDC_BUTTON_Originality)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 9, tmp))
	{
		GetDlgItem(IDC_BUTTON_File_Description)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 14, tmp))
	{
		GetDlgItem(IDC_BUTTON_Related_UCL)->EnableWindow(FALSE);
	}
	if (!element_exist(CDPSSet, 15, tmp))
	{
		GetDlgItem(IDC_BUTTON_Content_Object)->EnableWindow(FALSE);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


//���ڲ�ͬ����Ԫ�أ���ͬ��ť�����������ڵ�չʾ����Ҳ��ͬ��
void CCDPSDlg::OnBnClickedButtonTitle()
{
	ElementInfo ele_info;
	
	CString content;
	int index;
	if (element_exist(CDPSSet, 1, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("���ݱ���");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = ele_info.m_concrete_info;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonKeyword()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 2, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("���ݹؼ���");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	
	CString roughInfo;
	roughInfo.Format(_T("%d�����ݹؼ���"), CDPSSet[index].keywordsNum());		
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonAbstract()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 3, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("����ժҪ");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = ele_info.m_concrete_info;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonAuthor()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 4, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("��������");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	CString authorNum;
	if (CDPSSet[index].authorNum() < 7)
	{
		authorNum.Format(_T("%d"), CDPSSet[index].authorNum());
	}
	else
	{
		authorNum = _T("����6");
	}
	CString authorCopNum;
	if (CDPSSet[index].authorCopNum() < 7)
	{
		authorCopNum.Format(_T("%d"), CDPSSet[index].authorCopNum());
	}
	else
	{
		authorCopNum = _T("����6");
	}
	roughInfo.Format(authorNum + _T("�����ߣ�") + authorCopNum + _T("�����ߵ�λ"));
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonEntity()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 5, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("����ʵ��");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	CString entityArray[6] = { _T("who"), _T("when"), _T("where"), _T("what"), _T("why") ,_T("����")};
	vector <int> entity = CDPSSet[index].entity();
	for (int i = 0; i < entity.size(); ++i)
	{
		roughInfo = roughInfo + entityArray[entity[i]] + '\t';
	}
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonFlag()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 6, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("���ݱ��");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	CString flagNum;
	if (CDPSSet[index].flagNum() < 7)
	{
		flagNum.Format(_T("%d"), CDPSSet[index].flagNum());
	}
	else
	{
		flagNum = "����7";
	}
	CString roughInfo;
	roughInfo = _T("��") + flagNum + _T("�����ݱ��");
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonCopyright()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 7, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("��Ȩ��Ϣ");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = ele_info.m_concrete_info;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonOriginality()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 8, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("ԭ������");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = ele_info.m_concrete_info;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonFileDescription()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 9, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("�ļ���Ϣ");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = ele_info.m_concrete_info;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonRelatedUcl()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 14, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = content;
	ele_info.m_eleName = _T("����UCL");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();

	CString roughInfo;
	roughInfo.Format(_T("����%d��UCL"), CDPSSet[index].relatedUCLNum());
	ele_info.m_roughInfo = roughInfo;

	ele_info.DoModal();
}


void CCDPSDlg::OnClickedButtonContentObject()
{
	ElementInfo ele_info;

	CString content;
	int index;
	if (element_exist(CDPSSet, 15, index))
	{
		for (size_t i = 0; i < CDPSSet[index].get_Content().size(); ++i)
		{
			content += CDPSSet[index].get_Content()[i].c_str();
		}
	}

	ele_info.m_concrete_info = text_change(content);
	ele_info.m_eleName = _T("���ݶ���");
	ele_info.m_eleNum = CDPSSet[index].getNum();
	ele_info.m_eleLength = CDPSSet[index].getElementLength();
	ele_info.m_parseRule = CDPSSet[index].getAnalyseRule().c_str();
	ele_info.m_roughInfo = ele_info.m_concrete_info;

	ele_info.DoModal();
}
