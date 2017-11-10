#include <iostream>
#include "stue.h"

///
/// NODE
///
template <typename datatype>
node::node() {}
template <typename datatype>
node::~node() {}
template <typename datatype>
node::node(datatype data) {
    this->data = data;
}
template <typename datatype>
void node::set(datatype data) {
    this->data = data;
}

///
/// STACK
///
template <typename datatype>
stack::stack() {
    top = NULL;
    count = 0;
}
template <typename datatype>
stack::~stack() {
    delete top;
    top = NULL;
    count = 0;
}
template <typename datatype>
bool stack::empty() {
    if (count) return false;
    return true;
}
template <typename datatype>
int stack::size() {
    return this->count;
}
template <typename datatype>
node<datatype>* stack::Top() {
    return this->top;
}
template <typename datatype>
void stack::Pop() {
    node<datatype>* temp = this->Top();
    this->top = this->top->next;

    delete temp;
    count--;
}
template <typename datatype>
void stack::Push(datatype data) {
    node<datatype>* temp = new node(data);
    temp->next = this->top;
    this->top = temp;

    count++:
}
template <typename datatype>
void stack::Clear() {
    while(!this->empty())
        this->Pop();
}

///
/// QUEUE
///
template <typename datatype>
queue::queue() {
    front = NULL;
    rear = NULL;
    count = 0;
}
template <typename datatype>
queue::~queue() {
    delete front;
    delete rear;
    top = NULL;
    rear = NULL;
    count = 0;
}
template <typename datatype>
bool queue::empty() {
    if (count) return false;
    return true;
}
template <typename datatype>
int queue::size() {
    return this->count;
}
template <typename datatype>
node<datatype>* queue::Front() {
    return this->front;
}
template <typename datatype>
node<datatype>* queue::Rear() {
    return this->rear;
}
template <typename datatype>
void queue::Dequeue() {
    node<datatype>* temp = this->Front();
    this->front = this->front->next;

    delete temp;
    count--;
}
template <typename datatype>
void queue::Enqueue(datatype data) {
    node<datatype>* temp = new node(data);
    this->rear->next = temp;

    count++:
}
template <typename datatype>
void queue::Clear() {
    while(!this->empty())
        this->Dequeue();
}