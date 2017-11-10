#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>

class User {
private:
    std::string userName;
    std::string passWord;
public:
    User() {
        userName = "";
        passWord = "";
    }
    User(std::string yourName, std::string yourPass) {
        userName = yourName;
        passWord = yourPass;
    }
    void SetName(std::string yourName)
    std::string GetName()
    void SetPass(std::string yourPass)
    std::string GetPass()
};

class Project {

    }

class Lecturer : public User{

};

class Student : public User {

};
class Topic {
private:
    std::string TopicName;
    Project standard; // this is lecturer project
    Project* test; // student submission
};

#endif // HEADER_H