#include <iostream>
#include "../include/LinkedList.h"

// Add
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

void LinkedList::push_at(const unsigned &index, const int &value){
  if(index > _dummy->_value){
    std::cout << "push_at(): Please input valid index!" << std::endl;
    return;
  }
  if(index == 0){
    push_front(value);
    return;
  }
  if(index == _dummy->_value){
    push_back(value);
    return;
  }
  _Node *pos = _dummy->_next;
  unsigned pos_index = 0;
  while(pos_index < index - 1){
    pos = pos->_next;
    ++pos_index;
  }
  _Node *new_node = new _Node(value);
  new_node->_next = pos->_next;
  pos->_next = new_node;
  ++_dummy->_value;
}

// Delete
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

void LinkedList::pop_at(const unsigned &index){
  if(index >= _dummy->_value){
    std::cout << "pop_at(): Please input valid index" << std::endl;
    return;
  }
  if(index == 0){
    pop_front();
    return;
  }
  if(index == _dummy->_value - 1){
    pop_back();
    return;
  }
  _Node *pos = _dummy->_next;
  unsigned pos_index = 0;
  while(pos_index < index - 1){
    pos = pos->_next;
    ++pos_index;
  }
  _Node *del = pos->_next;
  pos->_next = del->_next;
  delete del;
  --_dummy->_value;
}

// Modify
void LinkedList::change_at(const unsigned &index, const int &value){
  if(index >= _dummy->_value){
    std::cout << "change_at(): Please input valid index" << std::endl;
    return;
  }
  _Node *pos = _dummy->_next;
  unsigned pos_index = 0;
  while(pos_index < index){
    pos = pos->_next;
    ++pos_index;
  }
  pos->_value = value;
}

void LinkedList::change_eq_first(const int &value, const int &new_value){
  if(is_empty()){
    std::cout << "change_eq_first(): This LinkedList is empty!" << std::endl;
    return;
  }
  _Node *curr = _dummy->_next;
  while(curr && curr->_value != value){
    curr = curr->_next;
  }
  curr->_value = new_value;
}

void LinkedList::change_eq_all(const int &value, const int &new_value){
  if(is_empty()){
    std::cout << "change_eq_all(): This LinkedList is empty!" << std::endl;
    return;
  }
  _Node *curr = _dummy->_next; 
  while(curr){
    if(curr->_value == value){
      curr->_value = new_value;
    }
    curr = curr->_next;
  } 
}
// ToDo
void LinkedList::sort(){

}

void LinkedList::reverse(){
  if(is_empty() || _dummy->_value == 1) {return;}
  _Node *prev = nullptr;
  _Node *curr = _dummy->_next;
  _Node *next = curr->_next;
  while(curr){
    curr->_next = prev;
    prev = curr;
    curr = next;
    if(next){
      next = next->_next;
    }
  }
  _dummy->_next = prev;
}

// Check
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

int LinkedList::get_at(const unsigned &index) const{
  if(index >= _dummy->_value){
    std::cout << "get_at(): Please input valid index" << std::endl;
    return -1;
  }
  if(index == 0) {return front();}
  if(index == _dummy->_value - 1) {return back();}
  _Node *pos = _dummy->_next;
  unsigned pos_index = 0;
  while(pos_index < index){
    pos = pos->_next;
    ++pos_index;
  }
  return pos->_value;
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
    std::cout << current->_value << " , " << current->_next << std::endl;
    current = current->_next;
  }
  std::cout << std::endl;
}

// Private functions
LinkedList::_Node* LinkedList::get_tail() const{
  _Node *current = _dummy;
  while(current->_next){
    current = current->_next;
  }
  return current;
}

// Destructor
LinkedList::~LinkedList(){
  _Node *current = _dummy->_next;
  while(current){
    _Node *next = current->_next;
    delete current;
    --_dummy->_value;
    current = next;
  }
  delete _dummy;
}