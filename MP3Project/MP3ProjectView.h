
// MP3ProjectView.h: интерфейс класса CMP3ProjectView
//

#pragma once
#include "FileSystemHandler.h"
#include <vector>
#include "MP3Controller.h"
#include "DrawMusicDialog.h"


class CMP3ProjectView : public CScrollView{
	

protected: // создать только из сериализации
	CMP3ProjectView() noexcept;
	DECLARE_DYNCREATE(CMP3ProjectView)

// Атрибуты
public:
	CMP3ProjectDoc* GetDocument() const;

// Операции
public:
	
	CString MusicDirectory;
	FileSystemHandler fileSystemHandler;
	MP3Controller mp3Controller;
	//DrawMusicDialog dlg;

public:

	// custom functions
	void CMP3ProjectView::OnIconClicked(UINT nID);
	std::string ConvertToSTDString(CString str);
	CString ConvertToCString(std::string str);




// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar * pScrollBar);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMP3ProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFolderSelectfolder();
};

#ifndef _DEBUG  // версия отладки в MP3ProjectView.cpp
inline CMP3ProjectDoc* CMP3ProjectView::GetDocument() const
   { return reinterpret_cast<CMP3ProjectDoc*>(m_pDocument); }
#endif

