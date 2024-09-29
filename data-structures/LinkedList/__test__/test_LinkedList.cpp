#include <iostream>
#include <cassert>
#include "../include/LinkedList.h"

int main(int argc, char* argv[]) {
  LinkedList<int> list;
  assert(list.empty() == true);
  assert(list.size() == 0);
  try{
    list.pop_front();
  } catch(const std::underflow_error &e){
    std::cout << "pop_front() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    list.pop_back();
  } catch(const std::underflow_error &e){
    std::cout << "pop_back() throw an exception PASSED: " << e.what() << std::endl;
  }
  list.push_front(32); // 32
  assert(list.empty() == false);
  assert(list.size() == 1);
  assert(list.front() == 32);
  assert(list.back() == 32);
  assert(list.contains(32) == 0);
  assert(list.get_at(0) == 32);
  list.push_back(22); // 32 22
  assert(list.empty() == false);
  assert(list.size() == 2);
  assert(list.front() == 32);
  assert(list.back() == 22);
  assert(list.contains(22) == 1);
  assert(list.get_at(0) == 32);
  list.push_front(11); // 11 32 22
  assert(list.empty() == false);
  assert(list.size() == 3);
  assert(list.front() == 11);
  assert(list.back() == 22);
  assert(list.contains(32) == 1);
  assert(list.get_at(2) == 22);
  try{
    list.push_at(4, 99);
  } catch(const std::out_of_range &e){
    std::cout << "push_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    list.pop_at(3);
  } catch(const std::out_of_range &e){
    std::cout << "pop_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    list.change_at(3, 99);
  } catch(const std::out_of_range &e){
    std::cout << "change_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    list.get_at(3);
  } catch(const std::out_of_range &e){
    std::cout << "get_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  list.push_front(31); // 31 11 32 22
  assert(list.empty() == false);
  assert(list.size() == 4);
  assert(list.front() == 31);
  assert(list.back() == 22);
  assert(list.contains(22) == 3);
  assert(list.get_at(2) == 32);
  list.push_back(29); // 31 11 32 22 29
  assert(list.empty() == false);
  assert(list.size() == 5);
  assert(list.front() == 31);
  assert(list.back() == 29);
  assert(list.contains(11) == 1);
  assert(list.get_at(3) == 22);
  list.push_back(11); // 31 11 32 22 29 11
  assert(list.empty() == false);
  assert(list.size() == 6);
  assert(list.front() == 31);
  assert(list.back() == 11);
  assert(list.contains(11) == 1);
  assert(list.get_at(4) == 29);
  list.change_eq_first(32, 75); // 31 11 75 22 29 11
  assert(list.contains(75) == 2);
  assert(list.get_at(2) == 75);
  assert(list.contains(32) == std::numeric_limits<size_t>::max());
  list.change_eq_all(11, 57); // 31 57 75 22 29 57
  assert(list.contains(57) == 1);
  assert(list.get_at(5) == 57);
  assert(list.contains(11) == std::numeric_limits<size_t>::max());
  list.change_at(2, 39); // 31 57 39 22 29 57
  assert(list.contains(39) == 2);
  assert(list.get_at(2) == 39);
  assert(list.contains(75) == std::numeric_limits<size_t>::max());
  list.print();
  list.reverse(); // 57 29 22 39 57 31
  assert(list.empty() == false);
  assert(list.size() == 6);
  assert(list.get_at(1) == 29);
  assert(list.front() == 57);
  assert(list.back() == 31);
  list.print();
  list.pop_front(); // 29 22 39 57 31
  assert(list.empty() == false);
  assert(list.size() == 5);
  assert(list.get_at(1) == 22);
  assert(list.front() == 29);
  assert(list.back() == 31);
  list.pop_back(); // 29 22 39 57
  assert(list.empty() == false);
  assert(list.size() == 4);
  assert(list.get_at(2) == 39);
  assert(list.front() == 29);
  assert(list.back() == 57);
  list.pop_at(2); // 29 22 57
  assert(list.empty() == false);
  assert(list.size() == 3);
  assert(list.get_at(1) == 22);
  assert(list.front() == 29);
  assert(list.back() == 57);
  list.pop_front();
  list.pop_back();
  list.pop_at(0); // null
  try{
    list.push_at(1, 99);
  } catch(const std::out_of_range &e){
    std::cout << "push_at() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.pop_at(1);
  } catch(const std::out_of_range &e){
    std::cout << "pop_at() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.change_at(1, 99);
  } catch(const std::out_of_range &e){
    std::cout << "change_at() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.pop_front();
  } catch(const std::underflow_error &e){
    std::cout << "pop_front() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.pop_back();
  } catch(const std::underflow_error &e){
    std::cout << "pop_back() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.change_eq_first(1, 99);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_first() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.change_eq_all(1, 99);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_all() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.front();
  } catch(const std::underflow_error &e){
    std::cout << "front() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.back();
  } catch(const std::underflow_error &e){
    std::cout << "back() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    list.contains(99);
  } catch(const std::underflow_error &e){
    std::cout << "contains() throw an exception PASSED: )" << e.what() << std::endl;
  }
  list.print();
  list.push_at(0, 13); // 13
  assert(list.empty() == false);
  assert(list.size() == 1);
  assert(list.get_at(0) == 13);
  assert(list.front() == 13);
  assert(list.back() == 13);
  list.push_at(1, 21); // 13 21
  assert(list.empty() == false);
  assert(list.size() == 2);
  assert(list.get_at(1) == 21);
  assert(list.front() == 13);
  assert(list.back() == 21);
  list.push_at(1, 39); // 13 39 21
  assert(list.empty() == false);
  assert(list.size() == 3);
  assert(list.get_at(1) == 39);
  assert(list.front() == 13);
  assert(list.back() == 21);
  list.push_at(2, 47); // 13 39 47 21
  assert(list.empty() == false);
  assert(list.size() == 4);
  assert(list.get_at(1) == 39);
  assert(list.front() == 13);
  assert(list.back() == 21);
  list.pop_at(2); // 13 39 21
  assert(list.empty() == false);
  assert(list.size() == 3);
  assert(list.get_at(1) == 39);
  assert(list.front() == 13);
  assert(list.back() == 21);
  list.pop_front();
  list.pop_back();
  list.pop_back();
  assert(list.empty() == true);
  assert(list.size() == 0);
  std::cout << "ALL TEST PASSED!" << std::endl;
  return 0;
}