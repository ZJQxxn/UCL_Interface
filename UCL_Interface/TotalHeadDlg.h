#pragma once


// TotalHeadDlg dialog

class TotalHeadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TotalHeadDlg)

public:
	TotalHeadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~TotalHeadDlg();

// Dialog Data
	enum { IDD = IDD_TOTAL_HEAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_decodeRule;
	CString m_language;
//	CString m_setNumber;
//	CString m_totalLength;
	afx_msg void OnClickedOk();
	int m_totalLength;
	int m_elementNum;
};
