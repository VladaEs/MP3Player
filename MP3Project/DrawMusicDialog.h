#pragma once

#include "afxwin.h"
#include "mp3.hpp"
#include "Music.hpp"
#include <wmp.h>


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
	bool MusicLoaded =false;
	Music* m_music;




	CImage musicImage;
	CButton m_buttons[4]; // start, stop, pause, edit btns
	CSliderCtrl m_slider;
	


	IWMPPlayer* pPlayer = nullptr;
	IWMPControls* pControls = nullptr;
	IWMPSettings *pSettings = nullptr;

	HRESULT LoadImageFromMemory(const std::vector<char>& imageData, CImage& outImage);

	afx_msg void OnPaint();
	void initMusic(Music *m);
	afx_msg void OnBtnclickedPlay();
	afx_msg void OnBtnclickedPause();
	afx_msg void OnBtnclickedStop();
	afx_msg void OnBtnclickedEdit();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	virtual BOOL OnInitDialog();
	


	
	CString ConvertToCString(std::string str);

	
};
