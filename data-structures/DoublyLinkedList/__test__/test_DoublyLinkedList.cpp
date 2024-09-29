#include <iostream>
#include <cassert>
#include "../include/DoublyLinkedList.h"

int main(int argc, char* argv[]){
  DoublyLinkedList<int> dList;
  assert(dList.size() == 0);
  assert(dList.empty() == true);
  try{
    dList.pop_front();
  } catch(const std::underflow_error &e){
    std::cout << "pop_front() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.pop_back();
  } catch(const std::underflow_error &e){
    std::cout << "pop_back() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.change_eq_first(12, 17);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_first() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.change_eq_last(12, 17);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_last() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.change_eq_all(12, 17);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_all() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.front();
  } catch(const std::underflow_error &e){
    std::cout << "front() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.back();
  } catch(const std::underflow_error &e){
    std::cout << "back() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.contains(12);
  } catch(const std::underflow_error &e){
    std::cout << "contains() throw an exception PASSED: " << e.what() << std::endl;
  }
  dList.print();
  dList.print_reverse();
  dList.push_front(5); // 5
  assert(dList.empty() == false);
  assert(dList.size() == 1);
  assert(dList.front() == 5);
  assert(dList.back() == 5);
  assert(dList.contains(5) == 0);
  dList.reverse();
  assert(dList.empty() == false);
  assert(dList.size() == 1);
  assert(dList.front() == 5);
  assert(dList.back() == 5);
  assert(dList.contains(5) == 0);
  dList.pop_front(); // null
  assert(dList.empty() == true);
  assert(dList.size() == 0);
  dList.push_back(5); // 5
  assert(dList.empty() == false);
  assert(dList.size() == 1);
  assert(dList.front() == 5);
  assert(dList.back() == 5);
  assert(dList.contains(5) == 0);
  dList.pop_back(); // null
  assert(dList.empty() == true);
  assert(dList.size() == 0);
  dList.push_back(5); // 5
  assert(dList.empty() == false);
  assert(dList.size() == 1);
  assert(dList.front() == 5);
  assert(dList.back() == 5);
  assert(dList.contains(5) == 0);
  dList.push_front(9); // 9 5
  assert(dList.empty() == false);
  assert(dList.size() == 2);
  assert(dList.front() == 9);
  assert(dList.back() == 5);
  assert(dList.contains(5) == 1);
  dList.push_back(2); // 9 5 2
  assert(dList.empty() == false);
  assert(dList.size() == 3);
  assert(dList.front() == 9);
  assert(dList.back() == 2);
  assert(dList.contains(5) == 1);
  dList.push_back(1); // 9 5 2 1
  assert(dList.empty() == false);
  assert(dList.size() == 4);
  assert(dList.front() == 9);
  assert(dList.back() == 1);
  assert(dList.contains(2) == 2);
  dList.push_front(3); // 3 9 5 2 1
  assert(dList.empty() == false);
  assert(dList.size() == 5);
  assert(dList.front() == 3);
  assert(dList.back() == 1);
  assert(dList.contains(1) == 4);
  dList.push_at(2, 4); // 3 9 4 5 2 1
  assert(dList.size() == 6);
  assert(dList.empty() == false);
  try{
    dList.push_at(7, 19);
  } catch(const std::out_of_range &e){
    std::cout << "push_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  dList.push_at(0, 13); // 13 3 9 4 5 2 1
  assert(dList.empty() == false);
  assert(dList.size() == 7);
  assert(dList.front() == 13);
  assert(dList.back() == 1);
  assert(dList.contains(13) == 0);
  dList.push_at(7, 42); // 13 3 9 4 5 2 1 42
  assert(dList.empty() == false);
  assert(dList.size() == 8);
  assert(dList.front() == 13);
  assert(dList.back() == 42);
  assert(dList.contains(42) == 7);
  try{
    dList.pop_at(8);
  } catch(const std::out_of_range &e){
    std::cout << "pop_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  dList.pop_at(0); // 3 9 4 5 2 1 42
  assert(dList.empty() == false);
  assert(dList.size() == 7);
  assert(dList.front() == 3);
  assert(dList.back() == 42);
  assert(dList.contains(42) == 6);
  dList.pop_at(6); // 3 9 4 5 2 1
  assert(dList.empty() == false);
  assert(dList.size() == 6);
  assert(dList.front() == 3);
  assert(dList.back() == 1);
  assert(dList.contains(5) == 3);
  try{
    dList.change_at(7, 90);
  } catch(const std::out_of_range &e){
    std::cout << "change_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    dList.get_at(6);
  } catch(const std::out_of_range& e){
    std::cout << "get_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  dList.pop_back(); // 3 9 4 5 2
  dList.pop_front(); // 9 4 5 2
  assert(dList.size() == 4);
  dList.pop_at(2); // 9 4 2
  assert(dList.size() == 3);
  dList.push_front(3);
  dList.push_back(1);
  dList.push_back(6);
  dList.push_at(3, 7); // 3 9 4 7 2 1 6
  dList.change_at(2, 6); // 3 9 6 7 2 1 6
  dList.change_eq_all(6, 1); // 3 9 1 7 2 1 1
  dList.change_eq_first(1, 4); // 3 9 4 7 2 1 1
  dList.change_eq_last(1, 5); // 3 9 4 7 2 1 5
  assert(dList.size() == 7);
  assert(dList.front() == 3);
  assert(dList.back() == 5);
  assert(dList.get_at(3) == 7);
  assert(dList.contains(2) == 4);
  assert(dList.get_at(0) == 3);
  assert(dList.get_at(1) == 9);
  assert(dList.get_at(2) == 4);
  assert(dList.get_at(3) == 7);
  assert(dList.get_at(4) == 2);
  assert(dList.get_at(5) == 1);
  assert(dList.get_at(6) == 5);
  dList.print();
  dList.print_reverse();
  dList.reverse(); // 5 1 2 7 4 9 3
  assert(dList.get_at(0) == 5);
  assert(dList.get_at(1) == 1);
  assert(dList.get_at(2) == 2);
  assert(dList.get_at(3) == 7);
  assert(dList.get_at(4) == 4);
  assert(dList.get_at(5) == 9);
  assert(dList.get_at(6) == 3);
  dList.print();
  dList.print_reverse();
  std::cout << "All test passed" << std::endl;
  return 0;
}