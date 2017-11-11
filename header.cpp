#include "header.h"

///
/// USER CLASS
///

User::User(std::string yourName, std::string yourPass) {
    this->userName = yourName;
    this->passWord = yourPass;
    topicList = NULL;
}
void User::SetName(std::string yourName) {
    this->userName = yourName;
}
std::string User::GetName() {
    return this->username;
}
void User::SetPass(std::string yourPass) {
    this->passWord = yourPass;
}
std::string User::GetPass() {
    return this->passWord;
}
///
/// PROJECT CLASS
///
Project::Project(std::string folderName) {
    this->folderName = folderName;
}
void Project::SetCode(std::string codeName) {
    this->sourceCode = codeName;
}
void Project::SetResult(std::string resultName) {
    this->result = resultName;
}
std::string Project::GetName() {
    return this->folderName;
}
std::string Project::GetCode() {
    return this->sourceCode;
}
std::string Project::GetResult() {
    return this->result;
}

///
/// LECTURER CLASS
///
void Lecturer::CreateTopic(std::string topicName) {
    Topic *latest = new Topic(topicName);
    node<Topic* > temp = new node<Topic *>(*latest);

    if (!this->topicList) topicList = temp;
    else {
        node<Topic* > temp1 = topicList;
        while (temp1->next)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}
Topic* Lecturer::GoTopic(std::string topicName) {
    Topic *search = new Topic(topicName);
    node<Topic* > temp = new node<Topic *>(*search);

    if (!this->topicList) topicList = temp;
    else {
        node<Topic* > temp1 = topicList;
        while (temp1) {
            if (temp1->get()->GetName() == topicName) return &(temp1->get());
            temp1 = temp1->next;
        }
        return NULL;
    }
}