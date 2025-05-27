
// MP3ProjectView.cpp: реализация класса CMP3ProjectView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MP3Project.h"
#include "Music.hpp"

#endif

#include "MP3ProjectDoc.h"
#include "MP3ProjectView.h"
#include <iostream>
#include "mp3.hpp"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMP3ProjectView

IMPLEMENT_DYNCREATE(CMP3ProjectView, CScrollView)

BEGIN_MESSAGE_MAP(CMP3ProjectView, CScrollView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_FOLDER_SELECTFOLDER, &CMP3ProjectView::OnFolderSelectfolder)

	ON_COMMAND_RANGE(1000, 2000, &CMP3ProjectView::OnIconClicked)

END_MESSAGE_MAP()

// Создание или уничтожение CMP3ProjectView

CMP3ProjectView::CMP3ProjectView() noexcept
{
	// TODO: добавьте код создания

}

CMP3ProjectView::~CMP3ProjectView()
{
}

BOOL CMP3ProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs
	
	return CScrollView::PreCreateWindow(cs);
}

// Рисование CMP3ProjectView





void CMP3ProjectView::OnDraw(CDC* pDC)
{
	CMP3ProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
		
	CPoint scrollPos = GetScrollPosition();
	mp3Controller.drawPlayer(this, scrollPos);
	



	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CMP3ProjectView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);

	// Принудительно перерисовать весь клиент
	Invalidate();  // или InvalidateRect(NULL)
	OnInitialUpdate();
}


void CMP3ProjectView::OnInitialUpdate()
{

	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	SetScrollSizes(MM_TEXT, CSize(mp3Controller.getContentWidth(), mp3Controller.getContentHeight()));
	
	//createButtons
	CPoint scrollPos = GetScrollPosition();
	mp3Controller.delBtns();
	mp3Controller.createButtons(this, scrollPos);
	UpdateWindow();
}


// Печать CMP3ProjectView

BOOL CMP3ProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMP3ProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMP3ProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CMP3ProjectView

#ifdef _DEBUG
void CMP3ProjectView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMP3ProjectView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMP3ProjectDoc* CMP3ProjectView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMP3ProjectDoc)));
	return (CMP3ProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMP3ProjectView


std::string CMP3ProjectView::ConvertToSTDString(CString str) {
	// Convert a TCHAR string to a LPCSTR
	CT2CA pszConvertedAnsiString(str);
	// construct a std::string using the LPCSTR input
	std::string strStd(pszConvertedAnsiString);
	return strStd;
}

CString CMP3ProjectView::ConvertToCString(std::string str) {
	CString cstr(str.c_str());
	return cstr;
}


void CMP3ProjectView::OnFolderSelectfolder(){
	CFolderPickerDialog m_dlg;
	CString folderName;
	m_dlg.m_ofn.lpstrTitle = _T("Select a folder where your mp3`s are");
	m_dlg.m_ofn.lpstrInitialDir = _T("C:\\");
	if (m_dlg.DoModal() == IDOK) {
		folderName = m_dlg.GetPathName();   // Use this to get the selected folder name 
										  // after the dialog has closed

		// May need to add a '\' for usage in GUI and for later file saving, 
		// as there is no '\' on the returned name
		folderName += _T("\\");
		UpdateData(FALSE);   // To show updated folder in GUI

		// Debug
		TRACE("\n%S", folderName);
	}
	this->MusicDirectory = folderName;
	fileSystemHandler.SetRootDir(ConvertToSTDString(MusicDirectory));
	mp3Controller.SetRawData(this ,fileSystemHandler.GetPathList());
	Invalidate();
	OnInitialUpdate();
	
}

void CMP3ProjectView::OnIconClicked(UINT nID){
	
	int ind = nID - mp3Controller.GetButtonInitID();
	mp3Controller.MusicCollection[ind].loadMusic();
	DrawMusicDialog dlg;
	dlg.initMusic(&mp3Controller.MusicCollection[ind]);
	dlg.DoModal();



}
