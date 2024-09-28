#ifndef QUEUE_H
#define QUEUE_H
/*
 * We're going to implement Queue based on LinkedList since the two
 * structures are quite similar. Namely, they both operate mostly on
 * the elements at the beginning and the end. Compare push/pop
 * operations of Queue with push_back/pop_front operations of LinkedList.
*/
#include <stdexcept>
#include <cstddef>
#include "../../LinkedList/include/LinkedList.h"

template <typename T>
class Queue{
  public:
    //Capacity
    bool empty() const;
    size_t size() const;
    // Add
    void push(const T& value);
    // Delete
    void pop();
    // Check
    T& front();
    T& back();
  private:
    LinkedList<T> list;
};

//Capacity
template <typename T>
bool Queue<T>::empty() const{
  return list.empty();
}

template <typename T>
size_t Queue<T>::size() const{
  return list.size();
}

// Add
template <typename T>
void Queue<T>::push(const T &value){
  list.push_back(value);
}

// Delete
template <typename T>
void Queue<T>::pop(){
  if(empty()){
    throw std::underflow_error("This Queue is empty");
  }
  list.pop_front();
}

// Check
template <typename T>
T& Queue<T>::front(){
  if(empty()){
    throw std::underflow_error("This Queue is empty");
  }
  return list.front();
}

template <typename T>
T& Queue<T>::back(){
  if(empty()){
    throw std::underflow_error("This Queue is empty");
  }
  return list.back();
}

#endif // QUEUE_H