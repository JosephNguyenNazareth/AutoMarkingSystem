#ifndef HEADER_H
#define HEADER_H

#include "stue.h"
#include <iostream>
#include <string>

class User {
private:
  std::string userName;
  std::string passWord;
  node<Topic *> topicList;

protected:
  ~User();
  User(std::string yourName, std::string yourPass);
  void SetName(std::string yourName);
  std::string GetName();
  void SetPass(std::string yourPass);
  std::string GetPass();
};

class Project {
private:
  std::string folderName; // using boost to access this folder via xml file
  std::string sourceCode;
  std::string result;
  float score;

public:
  Project(std::string folderName);
  void SetCode(std : string codeName);
  void SetResult(std::string resultName);
  float GetScore(); // the score of the project
  std::string GetName();
  std::string GetCode();
  std::string GetResult(); // result after compiling
};

class Lecturer : public User {
private:

public:
  Lecturer(std::string name, std::string pass) : User(name, pass);
  void CreateTopic(std::string topicName);
  Topic* GoTopic(std::string topicName);
};

class Student : public User {
private:

public:
  void GoTopic(std::string topicName);
};

class Attendant {
private:
  std::string attendantName; // student name in this topic
  stack<Project *> submitList;

public:
  Attendant(std : string); // set once the attendantName, cannot be changed
  std::string GetName();
  void ViewList(); // see all the project
  void
  Enter(std::string projectName); // enter via project name, just view, not edit
  void Update(Project *myUpdate); // insert the latest project
  float FinalScore();
};

class Topic {
private:
  std::string TopicName;
  Project *Standard;        // lecturer folder
  Attendant *attendantList; // student who attends
public:
  Topic(std::string name);
  ~Topic();
  std::string GetName();
  void
  SetProject(Project *myStandard); // add ONE project for comparing, ny lecturer
  void ViewList();                 // see all the attendant
  void Attend(std::string me);     // make new
  void Enter(std::string me);      // enter available
};

#endif // HEADER_H