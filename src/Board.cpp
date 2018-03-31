//
// Created by Yevhenii Kubiuk on 3/31/2018.
//

#include "../include/Board.h"

#include <fstream>

Board::Board(const std::string &name) : name(name) {}

Board::Board(const std::string &name, const std::vector<Task> &tasks) : name(name), tasks(tasks) {}

Json::Value Board::toJson() const {
    Json::Value result;

    result["name"] = this->name;
    result["tasks"] = Json::arrayValue;
    for(auto &task: this->tasks){
        result["tasks"].append(task.toJson());
    }

    return result;
}

Board Board::fromJson(const Json::Value &json) {
    Board board(json["name"].asString());

    for(int i = 0; i < json["tasks"].size(); i++){
        board.addTask(Task::fromJson(json["tasks"][i]));
    }

    return board;
}

const std::string &Board::getName() const {
    return name;
}

void Board::setName(const std::string &name) {
    Board::name = name;
}

const std::vector<Task> &Board::getTasks() const {
    return tasks;
}

void Board::setTasks(const std::vector<Task> &tasks) {
    Board::tasks = tasks;
}

void Board::addTask(const Task &task) {
    this->tasks.push_back(task);
}

void Board::removeTask(int taskId) {
    this->tasks.erase(this->tasks.begin()+taskId);
}

void Board::save(const std::string &fileName) const {
    // TODO: implementation
    return;
}


Board Board::load(const std::string &fileName) {
    // TODO: implementation
    return Board("");
}
