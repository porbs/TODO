//
// Created by Yevhenii Kubiuk on 3/31/2018.
//

#include "Task.h"

Task::Task(const std::string &name, const std::string &description) : name(name), description(description), status(0) {}

Task::Task(const std::string &name, const std::string &description, int status) : name(name), description(description),
                                                                                  status(status) {}

Json::Value Task::toJson() const{
    Json::Value result;

    result["name"] = this->name;
    result["description"] = this->description;
    result["status"] = this->status;

    return result;
}

Task Task::fromJson(const Json::Value &json) {
    return Task(json["name"].asString(), json["description"].asString(), json["status"].asInt());
}

const std::string &Task::getName() const {
    return name;
}

void Task::setName(const std::string &name) {
    Task::name = name;
}

const std::string &Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string &description) {
    Task::description = description;
}

int Task::getStatus() const {
    return status;
}

void Task::setStatus(int status) {
    Task::status = status;
}
