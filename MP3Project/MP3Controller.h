#pragma once
#include <cstring>
#include <vector>
#include "Music.hpp"
#include <atlimage.h>
#include <filesystem>
#include "Music.hpp"
#include "Music.hpp"

namespace fs = std::filesystem;
class MP3Controller{
public:
	
	int padding = 20;
	std::vector<CButton*> g_buttons;
	std::vector<Music> MusicCollection;
	const int BUTTON_ID = 1000;
	int activeMusicIndex = 0;
	MP3Controller() { ; }
	int windowWidth = 0;
	int _lastX = 0; 
	int _lastY = 0;
	int _initX = 0;
	int _initY = 0;
	const int blockHeight = 180;
	bool windLoaded = false;
	
	int getContentHeight() {
		int Height = 0; 
		for (int i = 0; i < MusicCollection.size(); i++) {
			Height += padding + blockHeight;
		}
		return Height;
	}
	int getContentWidth(){
		return this->windowWidth;
	}
	MP3Controller(std::vector<std::string> dataList) {
		for (const auto& fullPath : dataList) {
			std::string filename = fs::path(fullPath).stem().string();
			Music music(fullPath, filename);
			MusicCollection.push_back((music));
			
		}
	}

	int GetBlockHeight() {
		return this->blockHeight;
	}
	const int GetButtonInitID() {
		return this->BUTTON_ID;
	}
	MP3Controller& SetRawData(CWnd* parent, std::vector<std::string> dataList) {
		int i = 0;
		for (const auto& fullPath : dataList) {
			std::string filename = fs::path(fullPath).stem().string();

			Music music(parent, fullPath, filename, i);
			MusicCollection.push_back((music));
			++i;
		}
		return *this;
	}
	void createButtons(CWnd* parent, CPoint scrollPos) {
		CClientDC dc(parent);
		for (auto pBtn : g_buttons) {
			if (pBtn) {
				pBtn->DestroyWindow();
				delete pBtn;
			}
		}
		g_buttons.clear();


		for (int i = 0; i < MusicCollection.size(); i++) {
			CButton* pButton = new CButton();
			int topOffset = scrollPos.y;
			TRACE(_T("Offset: %d\n"), topOffset);
			int blockTopY = ((padding + this->GetBlockHeight()) * i) -topOffset;
			int paddingFromTop = 120;
			int height = 40;
			int left = padding + 50;
			int width = 80;
			
			int top = blockTopY + paddingFromTop;
			int bottom = top + height;

			CRect rect(left, top, left + width, bottom);
			CBrush blackBrush(RGB(0, 0, 0));
			TRACE(_T("Rect: left=%d, top=%d, right=%d, bottom=%d\n"), rect.left, rect.top, rect.right, rect.bottom);
			dc.FillRect(&rect, &blackBrush);
			pButton->Create(L"Play", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				rect,
				parent, BUTTON_ID + i);
			pButton->SetWindowPos(&CWnd::wndTop, 0, 0, 0, 0,
				SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
			g_buttons.push_back(pButton);
		}

	}
	void drawPlayer(CWnd* parent, CPoint srollPos) {
		if (!parent) return;
		CClientDC dc(parent);
		CRect clientRect;
		parent->GetClientRect(&clientRect);
		int topOffset = srollPos.y; 
		//dc.FillSolidRect(&clientRect, ::GetSysColor(COLOR_WINDOW));
		dc.FillSolidRect(&clientRect, ::GetSysColor(COLOR_WINDOW));
		windowWidth = clientRect.Width();
		int initX = _initX;
		int initY = _initY;
		int lastX = padding;
		int lastY = padding - topOffset;
		
		for (int i = 0; i < MusicCollection.size(); i++) {
			int clientWidth = clientRect.Width();
			int clientHeight = clientRect.Height();
			int musicBlockWidth = clientWidth - (padding*2);
			CRect musicBlock(padding, lastY, padding + musicBlockWidth, lastY + blockHeight);
			drawMusicBlock(&dc, musicBlock, i);
			lastY += blockHeight + padding;
		}
		_lastY = lastY;
		
	}

	void drawMusicBlock(CClientDC *dc , CRect rect, int i) {
		int red = rand() % 256;
		int green = rand() % 256;
		int blue = rand() % 256;

		dc->Draw3dRect(rect, RGB(red, green, blue), RGB(0, 0, 0));

		//output the text:

		CFont font;
		font.CreatePointFont(150, _T("Arial"));
		dc->SetTextColor(RGB(0, 0, 0));  // Белый текст
		dc->SetBkMode(TRANSPARENT);           // Прозрачный фон
		CFont* pOldFont = dc->SelectObject(&font);
		
		
		int x = rect.left + 50;
		int y = rect.top + 50;
		dc->TextOut(x, y, ConvertToCString(MusicCollection[i].GetMusicName()));
		
	}

	void RepositionButton()
	{
		//work out button position you need
		//m_Button.MoveWindow(x, y, width, height);
	}


	void delBtns() {
		for (auto pBtn : g_buttons) {
			if (pBtn) {
				pBtn->DestroyWindow();  // Уничтожаем окно кнопки
				delete pBtn;            // Освобождаем память
			}
		}
		g_buttons.clear();  // Очищаем контейнер
	}

	CString ConvertToCString(std::string str) {
		CString cstr(str.c_str());
		return cstr;
	}

};

