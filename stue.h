#ifndef STACK_QUEUE
#define STACK_QUEUE

template <typename datatype> struct node{
    datatype data;
    node<datatype>* next;
    node<datatype>();
    ~node();
    node<datatype>(datatype data);
    void set(datatype data);
    datatype get();
};

template <typename datatype> class stack {
private:
  node<datatype>* top;
  int count;
public:
    stack();
    ~stack();
    bool empty();
    int size();
    node<datatype>* Top();
    void Pop();
    void Push(datatype data);
    void Clear();
};

template <typename datatype> class queue {
private:
  node<datatype>* front;
  node<datatype>* rear;
  int count;
public:
    queue();
    ~queue();
    bool empty();
    int size();
    node<datatype>* Front();
    node<datatype>* Rear();
    void Dequeue();
    void Enqueue();
    void Clear();
};

#endif // STACK_QUEUE