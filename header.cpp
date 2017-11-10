#include "header.h"

///
/// USER CLASS
///

User::User(std::string yourName, std::string yourPass) {
    this->userName = yourName;
    this->passWord = yourPass;
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