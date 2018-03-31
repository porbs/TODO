//
// Created by Yevhenii Kubiuk on 3/31/2018.
//

#ifndef TODO_BOARD_H
#define TODO_BOARD_H

#include <vector>

#include "Task.h"

class Board {
public:
    Board(const std::string &name);
    Board(const std::string &name, const std::vector<Task> &tasks);

    Json::Value toJson() const;
    static Board fromJson(const Json::Value &json);

    const std::string &getName() const;
    void setName(const std::string &name);
    const std::vector<Task> &getTasks() const;
    void setTasks(const std::vector<Task> &tasks);

    void addTask(const Task &task);
    void removeTask(int taskId);

    void save(const std::string &fileName) const;
    static Board load(const std::string &fileName);
private:
    std::string name;
    std::vector<Task> tasks;
};


#endif //TODO_BOARD_H
