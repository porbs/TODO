//
// Created by Yevhenii Kubiuk on 04.04.2018.
//

#include <iostream>
#include "TodoControllers.h"

void todo::createBoard(const std::string &name){
    if(!filesystem::isExistingPath(todo::STORAGE_PATH)){
        filesystem::createFolder(todo::STORAGE_PATH);
    }
    Board board(name);
    if(!filesystem::isExistingPath(todo::STORAGE_PATH + filesystem::delimiter + board.getName())) {
        todo::saveBoard(board);
    } else {
        std::cerr << "Board " << name << " already exist" << std::endl;
    }

}

void todo::removeBoard(const std::string &name){
    filesystem::deleteFile(todo::STORAGE_PATH + filesystem::delimiter + name);
}

Board todo::getBoard(const std::string &name){
    return Board::load(todo::STORAGE_PATH + filesystem::delimiter + name);
}

void todo::saveBoard(const Board &board){
    board.save(todo::STORAGE_PATH + filesystem::delimiter + board.getName());
}

std::vector<Board> todo::getBoardsList(){
    std::vector<Board> result;

    for (auto &boardName: filesystem::listFilesInFolder(todo::STORAGE_PATH)){
        result.emplace_back(getBoard(boardName));
    }

    return result;
}