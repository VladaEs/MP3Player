
// MP3Project.h: основной файл заголовка для приложения MP3Project
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // основные символы


// CMP3ProjectApp:
// Сведения о реализации этого класса: MP3Project.cpp
//

class CMP3ProjectApp : public CWinApp
{
public:
	CMP3ProjectApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMP3ProjectApp theApp;
