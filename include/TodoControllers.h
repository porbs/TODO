//
// Created by Yevhenii Kubiuk on 04.04.2018.
//

#ifndef TODO_TODOCONTROLLERS_H
#define TODO_TODOCONTROLLERS_H

#include "Board.h"
#include "Filesystem.h"

namespace todo{

    const std::string STORAGE_PATH = "storage";

    void createBoard(const std::string &name);
    void removeBoard(const std::string &name);
    Board getBoard(const std::string &name);
    void saveBoard(const Board &board);
    std::vector<Board> getBoardsList();


}

#endif //TODO_TODOCONTROLLERS_H
