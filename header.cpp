#include "header.h"

namespace pt = boost::property_tree;
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
    // create new node of topic to insert
    Topic *latest = new Topic(topicName);
    node<Topic* > temp = new node<Topic *>(*latest);

    if (!this->topicList) topicList = temp; // the first topicd
    else {
        node<Topic* > temp1 = topicList;
        while (temp1->next)
            temp1 = temp1->next; // searching next till reaching the last node
        temp1->next = temp; // insert to the last node
    }
}
bool Lecturer::DeleteTopic(std::string topicName) {
    if (!this->topicList) return false; // nothing to delete
    else {
        node<Topic* > temp1 = topicList;
        while (temp1) {
            if (temp1->get()->GetName() == topicName) {
                // temp node to delete
                node<Topic* > removeTopic = temp1;
                // move the link to the next node
                temp1->next = temp->next->next;
                // delete temp node
                delete removeTopic;
                removeTopic = NULL;
                return true; // delete successfully
            }
            temp1 = temp1->next;
        }
        return false; // cannot find out to delete
    }
}
Topic* Lecturer::GoTopic(std::string topicName) {
    if (!this->topicList) return NULL; // nothing to enter
    else {
        node<Topic* > temp1 = topicList;
        while (temp1) {
            // found, go to that topic
            if (temp1->get()->GetName() == topicName) return &(temp1->get());
            // if not, keep searching
            temp1 = temp1->next;
        }
        // cannot find out to enter
        return NULL;
    }
}

///
/// STUDENT CLASS
///
Topic* Student::GoTopic(std::string topicName) {
    if (!this->topicList) return NULL; // nothing to enter
    else {
        node<Topic* > temp1 = topicList;
        while (temp1) {
            // found, go to that topic
            if (temp1->get()->GetName() == topicName) return &(temp1->get());
            // if not, keep searching
            temp1 = temp1->next;
        }
        // cannot find out to enter
        return NULL;
    }
}
Topic* Student::SortTopic(std::string lecturerName) {
    // create list of topic
    Topic* list;
    int count = 0;

    if (!this->topicList) return NULL; // nothing to enter
    else {
        node<Topic* > temp1 = topicList;
        while (temp1) {
            // found, go to that topic
            if (temp1->get()->GetCreator() == lecturerName) {
                *( list + count ) = temp1->get();
                count++;
            }
            // if not, keep searching
            temp1 = temp1->next;
        }
        // cannot find out to entert
        if (!count) return NULL;
        else return list; // return those topic that belongs to a lecturer
    }
}

///
/// ATTENDANT CLASS
///
Attendant::Attendant(std::string name) {
    this->attendantName = name;
}
Attendant::~Attendant() {
    this->attendantName = "";
    submitList->Clear();
}
std::string Attendant::GetName() {
    return this->attendantName;
}
Project* Attendant::Enter(std::string projectName) {
    // create temp stack to moe data
    stack<Project *> tempList = new stack<Project* >();
    Project* temp = NULL;
    while (!this->submitList->empty()) {
        // find the project, if found, stop moving data, get out of loops
        // and move data back again
        // found project will be returned
        temp = this->submitList->Top();
        if (temp->GetName() == projectName) break;
        this->submitList->Pop();
        tempList->Push(temp);
    }
    // transfer again, back to original submit list
    while (!tempList->empty()) {
        Project* temp1 = tempList->Top();
        submitList->Push(temp1);
        tempList->Pop();
    }
    return temp;
}
void Attendant::Update(Project *myProject) {
    if (myProject) submitList->Push(Project);
    else return;
}
float Attendant::FinalScore() {
    Project* temp = submitList->Top();
    return temp->GetScore();
}

///
/// TOPIC CLASS
///
Topic::Topic(std::string creator, std::string name) {
    this->lecturerName = creator;
    this->topicName = name;
    Standard = NULL;
    attendantList = NULL;
}
Topic::~Topic() {
    delete Standard;
    Standard = NULL;
    delete[] attendantList;
    attendantList = NULL;
}
std::string Topic::GetCreator() {
    return this->lecturerName;
}
std::string Topic::GetName() {
    return this->topicName;
}
void Topic::SetProject(Project *lecturerProject) {
    if (lecturerProject) Standard = lecturerProject;
}

///
/// FOLDER STRUCT
///
void Folder::load(const std::string &name) {
  // Create empty property tree object
  pt::ptree tree;

  // Parse the XML into the property tree.
  pt::read_xml(name, tree);

  // Use the throwing version of get to find the debug filename.
  // If the path cannot be resolved, an exception is thrown.
  name = tree.get<std::string>("project.name");

  // Use the default-value version of get to find the debug level.
  // Note that the default value is used to deduce the target type.
  level = tree.get("project.level", 0);

  // Use get_child to find the node containing the modules, and iterate over
  // its children. If the path cannot be resolved, get_child throws.
  // A C++11 for-range loop would also work.
  BOOST_FOREACH (pt::ptree::value_type &v, tree.get_child("project.submits")) {
    // The data function is used to access the data stored in a node.
    files.Push(v.second.data());
  }
}
void Folder::save(const std::string &name) {
  // Create an empty property tree object.
  pt::ptree tree;

  // Put the simple values into the tree. The integer is automatically
  // converted to a string. Note that the "debug" node is automatically
  // created if it doesn't exist.
  tree.put("project.name", name);
  tree.put("project.level", level);

  // Add all the modules. Unlike put, which overwrites existing nodes, add
  // adds a new node at the lowest level, so the "modules" node will have
  // multiple "module" children.
  BOOST_FOREACH (const std::string &name, submits)
    tree.add("project.submits.submit", name);

  // Write property tree to XML file
  pt::write_xml(name, tree);
}