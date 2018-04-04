#include <iostream>

//#include "Board.h"
//#include "Filesystem.h"

#include "TodoControllers.h"

int main() {
    todo::createBoard("Board 1");
    todo::createBoard("Board 2");
    todo::createBoard("Board 3");

    todo::createBoard("Invalid board");
    todo::removeBoard("Invalid board");

    for (auto &board: todo::getBoardsList()){
        board.addTask(Task("Task 1", "Task description..."));
        todo::saveBoard(board);
    }

    return 0;
}