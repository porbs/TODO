//
// Created by Yevhenii Kubiuk on 04.04.2018.
//

#ifndef TODO_FILESYSTEM_H
#define TODO_FILESYSTEM_H

#include <string>
#include <vector>

namespace filesystem{

#ifdef _WINDOWS_
    const std::string delimiter = "\\";
#elif _LINUX_
    const std::string delimiter = "/";
#endif

    void deleteFile(const std::string &filePath);
    void createFolder(const std::string &folderPath);
    std::vector<std::string> listFilesInFolder(const std::string &folderPath);
}

#endif //TODO_FILESYSTEM_H
