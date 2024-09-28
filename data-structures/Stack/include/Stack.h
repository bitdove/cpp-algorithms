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
    bool empty();
    size_t size();
    // Add
    void push(T& value);
    // Delete
    void pop();
    // Check
    void top();
  private:
    LinkedList<T> list;
};



#endif // STACK_H