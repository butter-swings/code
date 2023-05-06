#ifndef _MSTACK_H_
#define _MSTACK_H_

#include <iostream>

template <typename T>
struct node
{
  T data;
  node* next;
};

template <typename T>
class stack
{
  public:
    stack() : head(new node<T>) { head->next = nullptr; }
    ~stack();
    
    void push(const T& tmp);
    void pop();
    T    top();
    bool empty();
    
  private:
    node<T>* head;
};

template <typename T>
T stack<T>::top()
{
  return head->next->data;
}

template <typename T>
bool stack<T>::empty()
{
  return head->next == nullptr;
}

template <typename T>
stack<T>::~stack()
{
  if(!empty())
  {
    node<T>* pre = head;
    node<T>* p   = pre->next;
    while(p != nullptr)
    {
      delete pre;
      pre = p;
      p = p->next;
    }
    delete pre;
  }
  else delete head;
}

template <typename T>
void stack<T>::push(const T& tmp)
{
  node<T>* current = new node<T>;
  current->data = tmp;
  current->next = head->next;
  head->next = current;
}

template <typename T>
void stack<T>::pop()
{
  if(!empty())
  {
    node<T>* top = head->next;
    head->next = top->next;
  }
}

#endif
