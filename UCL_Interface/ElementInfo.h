#pragma once


// ElementInfo dialog

class ElementInfo : public CDialogEx
{
	DECLARE_DYNAMIC(ElementInfo)

public:
	ElementInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~ElementInfo();

// Dialog Data
	enum { IDD = IDD_DIALOG_ELEMENT_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CRect *smallRect;
	CRect *largeRect;
	CString m_concrete_info;
	int m_eleLength;
	CString m_eleName;
	int m_eleNum;
	CString m_parseRule;
	CString m_roughInfo;
	bool isSmall;	//Indicate whether this window is small or large
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonDetail();

};
