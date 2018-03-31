//
// Created by Yevhenii Kubiuk on 3/31/2018.
//

#include "../include/Board.h"

#include <fstream>
#include <sstream>

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
    std::ofstream file;
    std::stringstream stream;
    Json::StreamWriterBuilder builder;
    Json::StreamWriter* writer = builder.newStreamWriter();

    writer->write(this->toJson(), &stream);

    file.open(fileName, std::ifstream::out);
    file << stream.str() << std::endl;
    file.close();

    delete writer;
}

Board Board::load(const std::string &fileName) {
    std::ifstream file;
    std::stringstream stream;

    file.open(fileName, std::ifstream::in);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    Json::Value node;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();

    reader->parse(content.begin().base(), content.end().base(), &node, nullptr);
    return  Board::fromJson(node);
}
