#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdexcept>
#include <cstddef> // For size_t
#include <limits> // Required for std::numeric_limits
#include <iostream>

template <typename T>
class DoublyLinkedList {
  public:
    DoublyLinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~DoublyLinkedList();
  public:
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
    void change_at(const size_t index, const T &new_value);
    void change_eq_first(const T &value, const T &new_value);
    void change_eq_last(const T &value, const T &new_value);
    void change_eq_all(const T &value, const T &new_value);
    void reverse();
    // Check
    T& front();
    T& back();
    T& get_at(const size_t index);
    size_t contains(const T &value) const;
    void print() const;
    void print_reverse() const;
  private:
    struct _Node;
    _Node* get_node(const size_t index) const;
    size_t search(const T &value, bool from_head) const;
  private:
    struct _Node {
      T _value;
      _Node *_prev;
      _Node *_next;

      _Node() : _value(T()), _prev(nullptr), _next(nullptr) {}
      _Node(const T &value) : _value(value), _prev(nullptr), _next(nullptr) {}
    };
    _Node *_head;
    _Node *_tail;
    size_t _size = 0;
};

// Add
template <typename T>
void DoublyLinkedList<T>::push_front(const T &value){
  _Node *new_node = new _Node(value);
  if(empty()){
    _head = new_node;
    _tail = new_node;
    ++_size;
    return;
  }
  _head->_prev = new_node;
  new_node->_next = _head;
  new_node->_prev = nullptr;
  _head = new_node;
  ++_size;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T &value){
  _Node *new_node = new _Node(value);
  if(empty()){
    _head = new_node;
    _tail = new_node;
    ++_size;
    return;
  }
  _tail->_next = new_node;
  new_node->_prev = _tail;
  new_node->_next = nullptr;
  _tail = new_node;
  ++_size;
}

template <typename T>
void DoublyLinkedList<T>::push_at(const size_t index, const T &value){
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
  _Node *new_node = new _Node(value);
  _Node *pos = get_node(index);
  new_node->_prev = pos->_prev;
  new_node->_next = pos;
  pos->_prev = new_node;
  new_node->_prev->_next = new_node;
  ++_size;
}

// Delete
template <typename T>
void DoublyLinkedList<T>::pop_front(){
  if(empty()){
    throw std::underflow_error("This DoublyLinkedList is empty");
  }
  _Node *del = _head;
  if(_size == 1){
    _head = nullptr;
    _tail = nullptr;
  } else{
    _head = _head->_next;
    _head->_prev = nullptr;
  }
  delete del;
  --_size;
}

template <typename T>
void DoublyLinkedList<T>::pop_back(){
  if(empty()){
    throw std::underflow_error("This DoublyLinkedList is empty");
  }
  _Node *del = _tail;
  if(_size == 1){
    _head = nullptr;
    _tail = nullptr;
  } else{
    _tail = _tail->_prev;
    _tail->_next = nullptr;
  }
  delete del;
  --_size;
}

template <typename T>
void DoublyLinkedList<T>::pop_at(const size_t index){
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
  _Node *del = get_node(index);
  del->_prev->_next = del->_next;
  del->_next->_prev = del->_prev;
  delete del;
  --_size;
}

// Modify
template <typename T>
void DoublyLinkedList<T>::change_at(const size_t index, const T &new_value){
  if(index >= _size){
    throw std::out_of_range("Index out of range");
  }
  _Node *pos = get_node(index);
  pos->_value = new_value;
}

template <typename T>
void DoublyLinkedList<T>::change_eq_first(const T &value, const T &new_value){
  int index = search(value, true);
  if(index == -1){
    std::cout << "change_eq_first(): There is no node equal to the given value!" << std::endl;
    return;
  } else{
    _Node *pos = get_node(index);
    pos->_value = new_value;
    return;
  }
}

template <typename T>
void DoublyLinkedList<T>::change_eq_last(const T &value, const T &new_value){
  int index = search(value, false);
  if(index == -1){
    std::cout << "change_eq_last(): There is no node equal to the given value!" << std::endl;
    return; 
  } else{
    _Node *pos = get_node(index);
    pos->_value = new_value;
    return;
  }
}

template <typename T>
void DoublyLinkedList<T>::change_eq_all(const T &value, const T &new_value){
  if(empty()) return; // Return if list is empty
  _Node *curr = _head; // Start from head
  // Traverse the list
  while(curr){
    if(curr->_value == value){
      curr->_value = new_value; // Change the value
    }
    curr = curr->_next; // Move to the next node
  }
}

template <typename T>
void DoublyLinkedList<T>::reverse(){
  if(empty() || _size == 1) {return;}
  _Node *prev = nullptr;
  _Node *curr = _head;
  _Node *next = nullptr;
  while(curr){
    next = curr->_next;
    curr->_next = prev; 
    curr->_prev = next;  
    prev = curr;    
    curr = next; 
  }
  _tail = _head;
  _head = prev;
}

// Check
template <typename T>
T& DoublyLinkedList<T>::front(){
  if(_head) {return _head->_value;}
  return -1;
}

template <typename T>
T& DoublyLinkedList<T>::back(){
  if(_tail) {return _tail->_value;}
  return -1;
}

template <typename T>
T& DoublyLinkedList<T>::get_at(const size_t index){
  if(index >= _size){
    std::cout << "get_at(): Please input valid index!" << std::endl;
    return -1;
  }
  _Node *pos = get_node(index);
  return pos->_value;
}

template <typename T>
size_t DoublyLinkedList<T>::contains(const T &value) const{
  return search(value, true);
}

template <typename T>
void DoublyLinkedList<T>::print() const{
  _Node *curr = _head;
  while(curr){
    std::cout << "value: " << curr->_value << " prev: " << curr->_prev << " curr: " << curr << " next: " << curr->_next << std::endl;
    curr = curr->_next;
  }
}

template <typename T>
void DoublyLinkedList<T>::print_reverse() const{
  _Node *curr = _tail;
  while(curr){
    std::cout << "value: " << curr->_value << " next: " << curr->_next << " prev: " << curr->_prev << std::endl;
    curr = curr->_prev;
  }
}

// Private functions
template <typename T>
typename DoublyLinkedList<T>::_Node *DoublyLinkedList<T>::get_node(const size_t index) const{
  if(index == -1) {return nullptr;}
  if(index == 0) {return _head;}
  if(index == _size - 1) {return _tail;}
  _Node *curr = nullptr;
  if(index < _size / 2){
    // from head
    curr = _head;
    for(size_t i = 0; i < index; ++i){
      curr = curr->_next;
    }
  } 
  else{
    // from tail
    curr = _tail;
    for(size_t i = _size - 1; i > index; --i){
      curr = curr->_prev;
    }
  }
  return curr;
}

template <typename T>
size_t DoublyLinkedList<T>::search(const T &value, bool from_head) const{
  if(empty()) {return -1;}
  _Node *current = nullptr;
  int curr_index = -1;
  if(from_head){
    current = _head;
    curr_index = 0;
    while(current && current->_value != value){
      current = current->_next;
      ++curr_index;
    }
  } else{
    current = _tail;
    curr_index = _size - 1;
    while(current && current->_value != value){
      current = current->_prev;
      --curr_index;
    }
  }
  return current ? curr_index : -1;
}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  _Node* current = _head;
  while(current){
    _Node *next = current->_next;
    delete current;
    current = next;
  }
  _head = nullptr;
  _tail = nullptr;
  _size = 0;
}

#endif DOUBLYLINKEDLIST_H