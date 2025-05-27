#pragma once
#include <afxdialogex.h>
#pragma once

#include "afxwin.h"
#include "mp3.hpp"
#include "Music.hpp"
#include <wmp.h>


// ���������� ���� EditMusicDialog

class EditMusicDialog : public CDialogEx
{
	DECLARE_DYNAMIC(EditMusicDialog)

public:

	// ����������� �����������
	EditMusicDialog(CWnd* pParent = nullptr);




	virtual ~EditMusicDialog();

	// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITMUSICDIALOG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()

public:
	bool MusicLoaded = false;
	Music* m_music;
	CString musicNameInput;
	CString authorNameInput;
	std::vector<char> newImage;
	afx_msg void OnPaint();
	void initMusic(Music *m);
	std::vector<char> ReadFileAsBytes(const std::string& path);
	std::string ConvertCStringToString(CString);
	std::vector<char> ConvertCStringToVectorChar(CString str);
	afx_msg void OnClose();
	

	virtual BOOL OnInitDialog();




	CString ConvertToCString(std::string str);
	std::string ConvertCharVectToString(std::vector<char> &data);
	std::string cleanTag(std::vector<char>& data);
	afx_msg void OnEnChangeMusicname();
	afx_msg void OnEnChangeMusicauthor();
	afx_msg void OnBnClickedChangeimage();
};





