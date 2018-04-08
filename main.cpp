#include <iostream>

#include "TodoControllers.h"

int main() {
    todo::createBoard("Board 1");
    todo::createBoard("Board 2");
    todo::createBoard("Board 3");

    todo::createBoard("Invalid board");
    todo::removeBoard("Invalid board");

    for (auto &board: todo::getBoardsList()){
        std::cout << "Altering <" << board.getName() << "> board" << std::endl;
        board.addTask(Task("Task 1", "Task description..."));
        todo::saveBoard(board);
    }

    return 0;
}