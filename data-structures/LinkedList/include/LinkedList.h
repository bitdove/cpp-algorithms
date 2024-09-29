#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <cstddef> // For size_t
#include <limits> // Required for std::numeric_limits
#include <iostream>

/*
C++ Class templates generally cannot have their implementation separated from their declaration
in two separate files in the same way that non-template classes can. 
This is due to the way templates are instantiated in C++.

The most common approach is to put both the declaration and implementation of your template class 
in the same header file.
*/

/* Declaration Begin */
template <typename T>
class LinkedList {
  public:
    LinkedList() : _head(nullptr), _size(0) {}
    ~LinkedList();
  public:
    // Capacity
    bool empty() const {return _size == 0;}
    size_t size() const {return _size;}
    // Add
    void push_front(const T &value);
    void push_back(const T &value);
    void push_at(const size_t index, const T &value);
    // Delete
    void pop_front();
    void pop_back();
    void pop_at(const size_t index);
    // Modify
    void change_at(const size_t index, const T &value);
    void change_eq_first(const T &value, const T &new_value);
    void change_eq_all(const T &value, const T &new_value);
    void reverse();
    // Check
    T& front();
    T& back();
    T& get_at(const size_t index);
    size_t contains(const T &value);
    void print() const;
  private:
    struct _Node;
    _Node* get_tail() const;
  private:
    struct _Node {
      T _value;
      _Node *_next;

      _Node() : _value(T()), _next(nullptr) {}
      _Node(const T &value) : _value(value), _next(nullptr) {}
      _Node(const T &value, _Node *next) : _value(value), _next(next) {}
    };
    _Node *_head;
    size_t _size;
};
/* Declaration End */

/* Implementation Begin */
// Add
template <typename T>
void LinkedList<T>::push_front(const T &value){
  if(empty()){
    _head = new _Node(value);
  } else{
    _Node *new_node = new _Node(value);
    new_node->_next = _head;
    _head = new_node;
  }
  ++_size;
}

template <typename T>
void LinkedList<T>::push_back(const T &value){
  if(empty()){
    _head = new _Node(value);
  } else{
    _Node *tail = get_tail();
    tail->_next = new _Node(value);    
  }
  ++_size;
}

template <typename T>
void LinkedList<T>::push_at(const size_t index, const T &value){
  if(index > _size){
    throw std::out_of_range("Index out of range");
  }
  if(index == 0){
    push_front(value);
    return;
  }
  if(index == _size){
    push_back(value);
    return;
  }
  _Node *prev = _head;
  for(size_t i = 0; i < index - 1; ++i){
    prev = prev->_next;
  }
  _Node *new_node = new _Node(value);
  new_node->_next = prev->_next;
  prev->_next = new_node;
  ++_size;
}

// Delete
template <typename T>
void LinkedList<T>::pop_front(){
  if(empty()){
    throw std::underflow_error("This LinkedList is empty");
  }
  _Node* del = _head;
  _head = del->_next;
  del->_next = nullptr;
  delete del;
  --_size;
}

template <typename T>
void LinkedList<T>::pop_back(){
  if(empty()){
    throw std::underflow_error("This LinkedList is empty");
  }
  if(_size == 1){
    delete _head;
    _head = nullptr;
    _size = 0;
    return;
  }
  _Node *prev = _head;
  while(prev->_next->_next){
    prev = prev->_next;
  }
  delete prev->_next;
  prev->_next = nullptr;
  --_size; 
}

template <typename T>
void LinkedList<T>::pop_at(const size_t index){
  if(index >= _size){
    throw std::out_of_range("Index out of range");
  }
  if(index == 0){
    pop_front();
    return;
  }
  if(index == _size - 1){
    pop_back();
    return;
  }
  _Node *prev = _head;
  for(size_t i = 0; i < index - 1; ++i){
    prev = prev->_next;
  }
  _Node *del = prev->_next;
  prev->_next = del->_next;
  delete del;
  --_size;
}

// Modify
template <typename T>
void LinkedList<T>::change_at(const size_t index, const T &value){
  if(index >= _size){
    throw std::out_of_range("Index out of range");
  }
  _Node *pos = _head;
  for(size_t i = 0; i < index; ++i){
    pos = pos->_next;
  }
  pos->_value = value;
}

template <typename T>
void LinkedList<T>::change_eq_first(const T &value, const T &new_value){
  if(empty()){
    throw std::underflow_error("This LinkedList is empty");
  }
  _Node *curr = _head;
  while(curr && curr->_value != value){
    curr = curr->_next;
  }
  if(curr){
    curr->_value = new_value;
  }
}

template <typename T>
void LinkedList<T>::change_eq_all(const T &value, const T &new_value){
  if(empty()){
    throw std::underflow_error("This LinkedList is empty");
  }
  _Node *curr = _head; 
  while(curr){
    if(curr->_value == value){
      curr->_value = new_value;
    }
    curr = curr->_next;
  } 
}

template <typename T>
void LinkedList<T>::reverse(){
  if(empty() || _size == 1) {return;}
  _Node *prev = nullptr;
  _Node *curr = _head;
  _Node *next = nullptr;
  while(curr){
    next = curr->_next;
    curr->_next = prev;
    prev = curr;
    curr = next;
  }
  _head = prev;
}

// Check
template <typename T>
T& LinkedList<T>::front(){
  if(empty()){
    throw std::underflow_error("This Linked List is empty");
  }
  return _head->_value;
}

template <typename T>
T& LinkedList<T>::back(){
  if(empty()){
    throw std::underflow_error("This LinkeList is empty");
  }
  _Node *tail = get_tail();
  return tail->_value;
}

template <typename T>
T& LinkedList<T>::get_at(const size_t index){
  if(index >= _size){
    throw std::out_of_range("Index out of range");
  }
  if(index == 0) {return front();}
  if(index == _size - 1) {return back();}
  _Node *pos = _head;
  for(size_t i = 0; i < index; ++i){
    pos = pos->_next;
  }
  return pos->_value;
}

template <typename T>
size_t LinkedList<T>::contains(const T &value){
  if(empty()){
    throw std::underflow_error("This LinkedList is empty");
  }
  else{
    size_t index = 0;
    _Node *current = _head;
    while(current){
      if(current->_value == value){
        return index;
      }
      current = current->_next;
      ++index;
    }
  }
  return std::numeric_limits<size_t>::max(); // Indicate not found
}

template <typename T>
void LinkedList<T>::print() const{
  if(empty()){
    std::cout << "This LinkedList is empty!" << std::endl;
    return;
  }
  _Node *current = _head;
  while(current){
    std::cout << current->_value << " , " << current->_next << std::endl;
    current = current->_next;
  }
  std::cout << std::endl;
}

// Private functions
template <typename T>
typename LinkedList<T>::_Node* LinkedList<T>::get_tail() const{
  _Node *current = _head;
  while(current && current->_next){
    current = current->_next;
  }
  return current;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList(){
  _Node *current = _head;
  while(current){
    _Node *next = current->_next;
    delete current;
    current = next;
  }
  _head = nullptr;
  _size = 0;
}

/* Implementation End */

#endif // LINKEDLIST_H