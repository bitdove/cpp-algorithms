#include<iostream>
#include "../include/DoublyLinkedList.h"

// Add
void DoublyLinkedList::push_front(const int &value){
  _Node *new_node = new _Node(value);
  if(is_empty()){
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

void DoublyLinkedList::push_back(const int &value){
  _Node *new_node = new _Node(value);
  if(is_empty()){
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

void DoublyLinkedList::push_at(const unsigned &index, const int &value){
  if(index > _size){
    std::cout << "push_at(): Please input valid index!" << std::endl;
    return;
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
void DoublyLinkedList::pop_front(){
  if(is_empty()){
    std::cout << "pop_front(): This DoublyLinkedList is empty!" << std::endl;
    return;
  }
  _Node *del = _head;
  if(_size == 1){
    _head = nullptr;
    _tail = nullptr;
  } else{
    _head->_next->_prev = nullptr;
    _head = _head->_next;
  }
  delete del;
  --_size;
}

void DoublyLinkedList::pop_back(){
  if(is_empty()){
    std::cout << "pop_back(): This DoublyLinkedList is empty!" << std::endl;
    return;
  }
  _Node *del = _tail;
  if(_size == 1){
    _head = nullptr;
    _tail = nullptr;
  } else{
    _tail->_prev->_next = nullptr;
    _tail = _tail->_prev;
  }
  delete del;
  --_size;
}

void DoublyLinkedList::pop_at(const unsigned &index){
  if(index >= _size){
    std::cout << "pop_at(): Please input valid index!" << std::endl;
    return;
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

// Private functions
DoublyLinkedList::_Node *DoublyLinkedList::get_node(const int &index){
  if(index == 0) {return _head;}
  if(index == _size - 1) {return _tail;}
  _Node *curr = nullptr;
  if(index < _size / 2){
    // from head
    curr = _head;
    unsigned curr_index = 0;
    while(curr_index < index){
      curr = curr->_next;
      ++curr_index;
    }
  } else{
    // from tail
    curr = _tail;
    unsigned curr_index = _size - 1;
    while(curr_index > index){
      curr = curr->_prev;
      --curr_index;
    }
  }
  return curr;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList(){
  _Node* current = _head;
  while(current){
    if(_head->_next){
      _head->_next->_prev = nullptr;
    }
    _head = _head->_next;
    delete current;
    --_size;
    current = current->_next;
  }
  _tail = nullptr;
}
