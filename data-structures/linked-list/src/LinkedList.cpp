#include <iostream>
#include "../include/LinkedList.h"

void LinkedList::push_front(const int &value){
  if(is_empty()){
    _dummy->_next = new _Node(value);
  } else{
    _Node *tmp = new _Node(value);
    tmp->_next = _dummy->_next;
    _dummy->_next = tmp;
  }
  ++_dummy->_value;
}

void LinkedList::push_back(const int &value){
  if(is_empty()){
    _dummy->_next = new _Node(value);
  } else{
    _Node *tail = get_tail();
    tail->_next = new _Node(value);    
  }
  ++_dummy->_value;
}

void LinkedList::pop_front(){
  if(!is_empty()){
    _Node* tmp = _dummy->_next;
    _dummy->_next = tmp->_next;
    tmp->_next = nullptr;
    delete tmp;
    --_dummy->_value;
  }
}

void LinkedList::pop_back(){
  if(!is_empty()){
    _Node *prev = _dummy;
    while(prev->_next && prev->_next->_next){
      prev = prev->_next;
    }
    _Node *tail = prev->_next;
    prev->_next = nullptr;
    delete tail;
    --_dummy->_value; 
  }
}

int LinkedList::front() const{
  return is_empty() ? -1 : _dummy->_next->_value;
}

int LinkedList::back() const{
  if(is_empty()){
    return -1;
  }
  _Node *tail = get_tail();
  return tail->_value;
}

int LinkedList::contains(const int &value){
  if(is_empty()){
    return -1;
  } else{
    int index = 0;
    _Node *current = _dummy->_next;
    while(current){
      if(current->_value == value){
        return index;
      }
      current = current->_next;
      ++index;
    }
    return -1;
  }
}

void LinkedList::print() const{
  if(is_empty()){
    std::cout << "This linked-list is empty!" << std::endl;
    return;
  }
  _Node *current = _dummy->_next;
  while(current){
    std::cout << current->_value << " ";
    current = current->_next;
  }
  std::cout << std::endl;
}

LinkedList::_Node* LinkedList::get_tail() const{
  _Node *current = _dummy;
  while(current->_next){
    current = current->_next;
  }
  return current;
}

LinkedList::~LinkedList(){
  _Node *current = _dummy->_next;
  while(current){
    _Node *next = current->_next;
    delete current;
    current = next;
  }
  delete _dummy;
}