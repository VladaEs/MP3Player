#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <cstring>
#include <vector>
#include <afxwin.h>

#include "mp3.hpp"



class Music {
public:

	std::string path;
	std::string musicName;
	int timePaused = 0; 
	int index;
	bool musicLoaded = false; 
	MP3 file;

	


	Music(std::string p, std::string name) {
		this->path = p;
		this->musicName = name;
	}
	Music(CWnd* parent,std::string p, std::string name, int i) {
		this->path = p;
		this->musicName = name;
		this->index = i;
		
	}
	Music( std::string p, std::string name, int i) {
		this->path = p;
		this->musicName = name;
		this->index = i;
		
	}
	Music() { ; }

	Music(const Music& other)
		: path(other.path), musicName(other.musicName), timePaused(other.timePaused), index(other.index){}
	Music& operator=(const Music& other) {
		if (this != &other) {  
			
			path = other.path;
			musicName = other.musicName;
			timePaused = other.timePaused;
			index = other.index;
			
		}
		return *this;
	}




	Music & SetPath(std::string path) {
		this->path = path;
		return *this;
	}
	Music & SetMusicName(std::string name) {
		this->musicName = name;
		return *this;
	}
	Music & SetTimePaused(int t) {
		this->timePaused = t; 
	}
	
	
	
	
	int GetTimePaused() {
		return this->timePaused;
	}
	std::string GetPath() {
		return this->musicName;
	}
	std::string GetMusicName() {
		return this->musicName;
	}
	bool loadMusic() {
		return file.read(path.c_str());
	}
	void changeMusicName(std::string data) {
		file.setTag("TIT2", convertData(data));
	}
	//std::vector<char> getMusicNameFile() {
		
			
			//std::vector<char> name2 = file.getTag("TIT2");
			//return file.getTag("TIT2");
	//}

	std::vector<char> convertData(std::string data) {
		return std::vector<char>(data.begin(), data.end());
	}
	bool saveFile() {
		file.write(path.c_str());
	}

	

private:




};


#endif