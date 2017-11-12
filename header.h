#ifndef HEADER_H
#define HEADER_H

#include "stue.h"
#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

class User {
private:
  std::string userName;
  std::string passWord;
  node<Topic *> topicList;

protected:
  ~User();
  User(std::string, std::string);
  void SetName(std::string);
  std::string GetName();
  void SetPass(std::string);
  std::string GetPass();
};

class Project {
private:
  std::string folderName; // using boost to access this folder via xml file
  std::string sourceCode;
  std::string result;
  float score;

public:
  Project(std::string);
  void SetCode(std::string);
  void SetResult(std::string);
  float GetScore(); // the score of the project
  std::string GetName();
  std::string GetCode();
  std::string GetResult(); // result after compiling
};

class Lecturer : public User {
private:
public:
  Lecturer(std::string name, std::string pass) : User(name, pass);
  void CreateTopic(std::string); // lecture is the only one who create a topic
  bool DeleteTopic(std::string); // lecture is the only one who delete a topic
  Topic *GoTopic(std::string);   // enter the specific topic
};

class Student : public User {
private:
public:
  Topic *GoTopic(std::string);
  Topic *SortTopic(std::string); // searching topics which belongs to
                                 // a specific lecturer
};

// ATTENDANT is STUDENT who join in a topic
// STUDENT will be provided a stack of submitted project
// and get score
class Attendant {
private:
  std::string attendantName; // student name in this topic
  stack<Project *> submitList;

public:
  Attendant(std::string); // set once the attendantName, cannot be changed
  ~Attendant();
  std::string GetName();
  // void ViewList(); // see all the project
  Project* Enter(std::string); // enter via project name, just view, not edit
  void Update(Project *);  // insert the latest project
  float FinalScore();
};

class Topic {
private:
  std::string lecturerName;
  std::string topicName;
  Project *Standard;        // lecturer folder
  Attendant *attendantList; // student who attends
public:
  Topic(std::string, std::string);
  ~Topic();
  std::string GetCreator();
  std::string GetName();
  void SetProject(Project *); // add ONE project for comparing, ny lecturer
  // void ViewList();            // see all the attendant
};

struct Folder {
  std::string name;              // project name
  int level;                     // tree levels
  stack<std::string> submits; // modules where logging is enabled
  void load(const std::string &);
  void save(const std::string &);
};

#endif // HEADER_H