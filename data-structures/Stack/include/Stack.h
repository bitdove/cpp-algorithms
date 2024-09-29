#ifndef STACK_H
#define STACK_H
/*
 * We're going to implement Stack based on LinkedList since these
 * tructures are quite similar. Compare push/pop operations of the Stack
 * with push_front/pop_front operations of LinkedList.
*/ 
#include "../../LinkedList/include/LinkedList.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack{
  public:
    // Capacity
    bool empty() const;
    size_t size() const;
    // Add
    void push(const T& value);
    // Delete
    void pop();
    // Check
    T& top();
  private:
    LinkedList<T> list;
};

// Capacity
template <typename T>
bool Stack<T>::empty() const{
  return list.empty();
}

template <typename T>
size_t Stack<T>::size() const{
  return list.size();
}

// Add
template <typename T>
void Stack<T>::push(const T& value){
  list.push_front(value);
}

// Delete
template <typename T>
void Stack<T>::pop(){
  if(empty()){
    throw std::underflow_error("This Stack is empty");
  }
  list.pop_front();
}

// Check
template <typename T>
T& Stack<T>::top(){
  if(list.empty()){
    throw std::underflow_error("This Stack is empty");
  }
  return list.front();
}

#endif // STACK_H