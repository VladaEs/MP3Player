#ifndef FileSystemHandler_H
#define FileSystemHandler_H
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <filesystem>
#include <direct.h>

class FileSystemHandler {
	
public:
	std::string rootDir;
	std::string extension =".mp3";
	std::vector<std::string> filesDir;

	FileSystemHandler() { ; }
	FileSystemHandler(std::string rootDir) { 
		this->rootDir = rootDir;
	}

	FileSystemHandler& SetExtension(std::string ext) {
		if (ext[0] != '.') {
			std::string newExt = "." + ext;
			this->extension = newExt;
			return *this;
		}
		this->extension = ext;
		return *this;
	}
	FileSystemHandler& SetRootDir(std::string dirName) {
		this->rootDir = dirName;
		LoadFiles();
		return *this;
	}
	
	std::vector<std::string> LoadFiles() {
		this->filesDir.clear();
		//рекурсивна функція
		get_files(filesDir, rootDir);
		return filesDir;
	}
	std::vector<std::string> GetPathList() {
		return this->filesDir;
	}

protected: 
	void get_files(std::vector<std::string> &paths, const std::string& currentPath) {
		for (const auto& file : std::filesystem::directory_iterator(currentPath)) {
			if (std::filesystem::is_directory(file)) {
				get_files(paths, file.path().string());
			}
			else {
				if (file.path().extension() == this->extension) {
					paths.push_back(file.path().string());
				}
			}
		}
	}

};




#endif // !FileSystemHandler.h
