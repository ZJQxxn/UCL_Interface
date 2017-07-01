
// UCL_Interface.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CUCL_InterfaceApp:
// See UCL_Interface.cpp for the implementation of this class
//

class CUCL_InterfaceApp : public CWinApp
{
public:
	CUCL_InterfaceApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CUCL_InterfaceApp theApp;