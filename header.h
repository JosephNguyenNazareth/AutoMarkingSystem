#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include "stue.h"

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
private:
    std::string folderName;
    std::string sourceCode;
    std::string result;
    float score;
public:
    float GetScore()
   };

class Lecturer : public User{
};

class Student : public User {

public:
    float score(); // return final score

};
class Topic {
private:
    std::string TopicName;
    Project* Standard; // lecturer folder
    Student* studentList; // student who attends
};

#endif // HEADER_H