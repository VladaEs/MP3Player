#pragma once

#include "afxwin.h"
#include "mp3.hpp"
#include "Music.hpp"
// Диалоговое окно DrawMusicDialog

class DrawMusicDialog : public CDialogEx
{
	DECLARE_DYNAMIC(DrawMusicDialog)

public:
	
	// Стандартный конструктор
	DrawMusicDialog(CWnd* pParent = nullptr);


	

	virtual ~DrawMusicDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUSICDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()

public: 
	Music* m_music;




	afx_msg void OnPaint();
	void initMusic(Music *m);
	void ReadMusic();
	CString ConvertToCString(std::string str);

	
};
