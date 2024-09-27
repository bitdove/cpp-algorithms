#include <iostream>
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
    _head = _head->_next;
    _head->_prev = nullptr;
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
    _tail = _tail->_prev;
    _tail->_next = nullptr;
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

// Modify
void DoublyLinkedList::change_at(const unsigned &index, const int &new_value){
  if(index >= _size){
    std::cout << "change_at(): Please input valid index!" << std::endl;
    return;
  }
  _Node *pos = get_node(index);
  pos->_value = new_value;
}

void DoublyLinkedList::change_eq_first(const int &value, const int &new_value){
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

void DoublyLinkedList::change_eq_last(const int &value, const int &new_value){
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

void DoublyLinkedList::change_eq_all(const int &value, const int &new_value){
  if(is_empty()) return; // Return if list is empty
  _Node *curr = _head; // Start from head
  // Traverse the list
  while(curr){
    if(curr->_value == value){
      curr->_value = new_value; // Change the value
    }
    curr = curr->_next; // Move to the next node
  }
}

void DoublyLinkedList::sort(){
  //ToDo
}

void DoublyLinkedList::reverse(){
  if(is_empty() || _size == 1) {return;}
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
int DoublyLinkedList::front() const{
  if(_head) {return _head->_value;}
  return -1;
}

int DoublyLinkedList::back() const{
  if(_tail) {return _tail->_value;}
  return -1;
}

int DoublyLinkedList::get_at(const unsigned &index) const{
  if(index >= _size){
    std::cout << "get_at(): Please input valid index!" << std::endl;
    return -1;
  }
  _Node *pos = get_node(index);
  return pos->_value;
}

int DoublyLinkedList::contains(const int &value) const{
  return search(value, true);
}

void DoublyLinkedList::print() const{
  _Node *curr = _head;
  while(curr){
    std::cout << "value: " << curr->_value << " prev: " << curr->_prev << " curr: " << curr << " next: " << curr->_next << std::endl;
    curr = curr->_next;
  }
}

void DoublyLinkedList::print_reverse() const{
  _Node *curr = _tail;
  while(curr){
    std::cout << "value: " << curr->_value << " next: " << curr->_next << " prev: " << curr->_prev << std::endl;
    curr = curr->_prev;
  }
}

// Private functions
DoublyLinkedList::_Node *DoublyLinkedList::get_node(const int &index) const{
  if(index == -1) {return nullptr;}
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

int DoublyLinkedList::search(const int &value, bool from_head) const{
  if(is_empty()) {return -1;}
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
DoublyLinkedList::~DoublyLinkedList(){
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