//
// Created by Yevhenii Kubiuk on 04.04.2018.
//

#include "Filesystem.h"

#include <iostream>

#ifdef _WINDOWS_
#include <windows.h>
#include <fileapi.h>
#include <handleapi.h>

#elif _LINUX_

#endif

void filesystem::deleteFile(const std::string &filePath){
#ifdef _WINDOWS_
    if(!DeleteFile(filePath.c_str())){
        std::cerr << "Failed to delete file" << std::endl;
    }
#elif _LINUX_

#endif
}

void filesystem::createFolder(const std::string &folderPath){
#ifdef _WINDOWS_
    if(!CreateDirectory(folderPath.c_str(), nullptr) && ){
        std::cerr << "Failed to create folder" << std::endl;
    }
#elif _LINUX_

#endif
}

bool filesystem::isExistingPath(const std::string &path){
#ifdef _WINDOWS_
//    return static_cast<bool>(PathFileExists(path.c_str()));
    return GetFileAttributes(path.c_str()) != 0xFFFFFFFF;
#elif _LINUX_

#endif
}

std::vector<std::string> filesystem::listFilesInFolder(const std::string &folderPath){

    std::vector<std::string> result;
#ifdef _WINDOWS_
    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    const std::string path = folderPath + "\\*";

    hFind = FindFirstFile(path.c_str(), &ffd);
    if (INVALID_HANDLE_VALUE == hFind) {
        std::cerr << "Could not read directory" << std::endl;
    }

    do {
        if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
            result.emplace_back(ffd.cFileName);
        }
    }
    while (FindNextFile(hFind, &ffd) != 0);
#elif _LINUX_

#endif
    return result;
}