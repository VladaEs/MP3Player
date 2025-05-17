// DrawMusicDialog.cpp: файл реализации
//

#include "pch.h"
#include "MP3Project.h"
#include "DrawMusicDialog.h"
#include "afxdialogex.h"
#include <string>
#include "mp3.hpp"
#include "Music.hpp"
#include "MP3Controller.h"
// Диалоговое окно DrawMusicDialog

IMPLEMENT_DYNAMIC(DrawMusicDialog, CDialogEx)

DrawMusicDialog::DrawMusicDialog(CWnd* pParent)
	: CDialogEx(IDD_MUSICDIALOG, pParent)  // Инициализируем указатель как nullptr
{
	
}

// Конструктор с параметром Music


DrawMusicDialog::~DrawMusicDialog(){
	
}

void DrawMusicDialog::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DrawMusicDialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void DrawMusicDialog::ReadMusic() {
	this->m_music->loadMusic();

}
void DrawMusicDialog::initMusic(Music *m) {
	this->m_music = m;
}
void DrawMusicDialog::OnPaint()
{
	CPaintDC dc(this); 
	CRect rect;
	GetClientRect(&rect);

	CString text = L"AAA";
	dc.DrawText(text, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// draw BG
	dc.FillSolidRect(&rect, RGB(255, 255, 255));
	//CImage image;
	m_music->loadMusic();

	//std::vector<char> image = m_music->getMusicNameFile();
	int a = 10;

	
}
CString DrawMusicDialog::ConvertToCString(std::string str) {
	CString cstr(str.c_str());
	return cstr;
}

