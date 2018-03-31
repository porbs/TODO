#include <iostream>

#include "include/Board.h"

int main() {
    Board board("Board 1");

    board.addTask(Task("Task 1", "Description 1"));
    board.addTask(Task("Task 2", "Description 2"));

    std::cout << board.toJson() << std::endl;

    return 0;
}