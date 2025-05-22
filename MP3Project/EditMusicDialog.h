#pragma once
#include <afxdialogex.h>
#pragma once

#include "afxwin.h"
#include "mp3.hpp"
#include "Music.hpp"
#include <wmp.h>


// Диалоговое окно EditMusicDialog

class EditMusicDialog : public CDialogEx
{
	DECLARE_DYNAMIC(EditMusicDialog)

public:

	// Стандартный конструктор
	EditMusicDialog(CWnd* pParent = nullptr);




	virtual ~EditMusicDialog();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUSICDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()

public:
	bool MusicLoaded = false;
	Music* m_music;

	afx_msg void OnPaint();
	void initMusic(Music *m);

	afx_msg void OnClose();
	

	virtual BOOL OnInitDialog();




	CString ConvertToCString(std::string str);


};





