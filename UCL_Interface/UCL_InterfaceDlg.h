
// UCL_InterfaceDlg.h : header file
//

#pragma once
#include "TotalHeadDlg.h"
#include "CDPSDlg.h"
#include "CGPSDlg.h"

// CUCL_InterfaceDlg dialog
class CUCL_InterfaceDlg : public CDialogEx
{
// Construction
public:
	CUCL_InterfaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_UCL_INTERFACE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOpen();
	afx_msg void OnClickedReset();
	afx_msg void OnClickedVersion();
	afx_msg void OnClickedTypeOfMedia();
	afx_msg void OnClickedPrecedence();
	afx_msg void OnClickedFlag();
	afx_msg void OnClickedDecodeRule();
	afx_msg void OnClickedSourceOfContent();
	afx_msg void OnClickedCategory();
	afx_msg void OnClickedSubcategory();
	afx_msg void OnClickedTopic();
	afx_msg void OnClickedTypeOfContent();
	afx_msg void OnClickedSecurityLevel();
	afx_msg void OnClickedTimeStamp();
	afx_msg void OnClickedSerialNumber();
	afx_msg void OnClickedReservedBytes();
	afx_msg void OnClickedChecksum();
	afx_msg void OnClickedTotalHead();
	afx_msg void OnClickedCdps();
	afx_msg void OnClickedCgps();
	TotalHeadDlg totalHeadDlg;
	CCDPSDlg cdpsDlg;
	CCGPSDlg cgpsDlg;
	CString m_filename;
	afx_msg void OnBnClickedExtension();
	afx_msg void OnClickedPriorityPolicy();
	afx_msg void OnClickedLanguage();
	afx_msg void OnClickedContentLength();
	afx_msg void OnClickedMultiplexBytes();
};
