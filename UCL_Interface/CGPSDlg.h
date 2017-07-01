#pragma once
#include "afxcmn.h"


// CCGPSDlg dialog

class CCGPSDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCGPSDlg)

public:
	CCGPSDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCGPSDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_CGPS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOk();
	CListCtrl m_List_CGPS;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedShowDetailsCgps();
	afx_msg void OnBnClickedButtonSignatureofUcl();
	afx_msg void OnClickedButtonProvenance();
	afx_msg void OnClickedButtonContentId();
	afx_msg void OnClickedButtonPropagationPath();
	afx_msg void OnClickedButtonSignatureOfContent();
	afx_msg void OnClickedButtonSecurityLevel();
	afx_msg void OnClickedButtonProperties();
	afx_msg void OnClickedButtonSignatureOfUcl();
};
