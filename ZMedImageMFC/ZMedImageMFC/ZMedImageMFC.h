
// ZMedImageMFC.h : main header file for the ZMedImageMFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CZMedImageMFCApp:
// See ZMedImageMFC.cpp for the implementation of this class
//

class CZMedImageMFCApp : public CWinApp
{
public:
	CZMedImageMFCApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZMedImageMFCApp theApp;
