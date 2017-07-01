#pragma once
#include "afxcmn.h"


// CCDPSDlg dialog

class CCDPSDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCDPSDlg)

public:
	CCDPSDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCDPSDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_CDPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_List_CDPS;
	afx_msg void OnClickedShowDetailsCdps();
	afx_msg void OnBnClickedButtonTitle();
	afx_msg void OnClickedButtonKeyword();
	afx_msg void OnClickedButtonAbstract();
	afx_msg void OnClickedButtonAuthor();
	afx_msg void OnClickedButtonEntity();
	afx_msg void OnClickedButtonFlag();
	afx_msg void OnClickedButtonCopyright();
	afx_msg void OnClickedButtonOriginality();
	afx_msg void OnClickedButtonFileDescription();
	afx_msg void OnClickedButtonRelatedUcl();
	afx_msg void OnClickedButtonContentObject();
};
