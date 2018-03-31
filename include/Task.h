//
// Created by Yevhenii Kubiuk on 3/31/2018.
//

#ifndef TODO_TASK_H
#define TODO_TASK_H

#include <string>

#include <json/json.h>

class Task {
public:
    Task(const std::string &name, const std::string &description);
    Task(const std::string &name, const std::string &description, int status);

    Json::Value toJson() const;
    static Task fromJson(const Json::Value &json);

    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
    int getStatus() const;
    void setStatus(int status);

private:
    std::string name;
    std::string description;
    int status;
};


#endif //TODO_TASK_H
