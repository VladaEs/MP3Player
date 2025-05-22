// EditMusicDialog.cpp: файл реализации
//

#include "pch.h"
#include "MP3Project.h"
#include "EditMusicDialog.h"
#include "afxdialogex.h"
#include <string>
#include "mp3.hpp"
#include "Music.hpp"
#include "MP3Controller.h"
#include <shlwapi.h>

#include <wmp.h>



IMPLEMENT_DYNAMIC(EditMusicDialog, CDialogEx)


BEGIN_MESSAGE_MAP(EditMusicDialog, CDialogEx)
	ON_WM_PAINT()
	
	ON_WM_CLOSE()
	

END_MESSAGE_MAP()

EditMusicDialog::EditMusicDialog(CWnd* pParent)
	: CDialogEx(IDD_MUSICDIALOG, pParent)  // Инициализируем указатель как nullptr
{

}

// Конструктор с параметром Music

void EditMusicDialog::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}
void EditMusicDialog::OnClose(){
	


	CDialogEx::OnClose();
}

EditMusicDialog::~EditMusicDialog() {

	
}




BOOL EditMusicDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	

	return TRUE;
}
void EditMusicDialog::initMusic(Music *m) {
	this->m_music = m;
	m_music->loadMusic();
	std::string pathWay = m_music->GetPath();
	




}



void EditMusicDialog::OnPaint()
{

	



}




CString EditMusicDialog::ConvertToCString(std::string str) {
	CString cstr(str.c_str());
	return cstr;
}

