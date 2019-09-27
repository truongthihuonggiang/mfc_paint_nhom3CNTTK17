
// public1.h : main header file for the public1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cpublic1App:
// See public1.cpp for the implementation of this class
//

class Cpublic1App : public CWinApp
{
public:
	Cpublic1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cpublic1App theApp;
