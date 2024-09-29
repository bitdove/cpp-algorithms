#include <iostream>
#include <cassert>
#include "../include/SinglyLinkedList.h"
#include "../include/DoublyLinkedList.h"

void test_SinglyLinkedList(){
  std::cout << "*****SinglyLinkedList Test Begin*****" << std::endl;
  SinglyLinkedList<int> sList;
  assert(sList.empty() == true);
  assert(sList.size() == 0);
  try{
    sList.pop_front();
  } catch(const std::underflow_error &e){
    std::cout << "pop_front() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    sList.pop_back();
  } catch(const std::underflow_error &e){
    std::cout << "pop_back() throw an exception PASSED: " << e.what() << std::endl;
  }
  sList.push_front(32); // 32
  assert(sList.empty() == false);
  assert(sList.size() == 1);
  assert(sList.front() == 32);
  assert(sList.back() == 32);
  assert(sList.contains(32) == 0);
  assert(sList.get_at(0) == 32);
  sList.push_back(22); // 32 22
  assert(sList.empty() == false);
  assert(sList.size() == 2);
  assert(sList.front() == 32);
  assert(sList.back() == 22);
  assert(sList.contains(22) == 1);
  assert(sList.get_at(0) == 32);
  sList.push_front(11); // 11 32 22
  assert(sList.empty() == false);
  assert(sList.size() == 3);
  assert(sList.front() == 11);
  assert(sList.back() == 22);
  assert(sList.contains(32) == 1);
  assert(sList.get_at(2) == 22);
  try{
    sList.push_at(4, 99);
  } catch(const std::out_of_range &e){
    std::cout << "push_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    sList.pop_at(3);
  } catch(const std::out_of_range &e){
    std::cout << "pop_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    sList.change_at(3, 99);
  } catch(const std::out_of_range &e){
    std::cout << "change_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    sList.get_at(3);
  } catch(const std::out_of_range &e){
    std::cout << "get_at() throw an exception PASSED: " << e.what() << std::endl;
  }
  sList.push_front(31); // 31 11 32 22
  assert(sList.empty() == false);
  assert(sList.size() == 4);
  assert(sList.front() == 31);
  assert(sList.back() == 22);
  assert(sList.contains(22) == 3);
  assert(sList.get_at(2) == 32);
  sList.push_back(29); // 31 11 32 22 29
  assert(sList.empty() == false);
  assert(sList.size() == 5);
  assert(sList.front() == 31);
  assert(sList.back() == 29);
  assert(sList.contains(11) == 1);
  assert(sList.get_at(3) == 22);
  sList.push_back(11); // 31 11 32 22 29 11
  assert(sList.empty() == false);
  assert(sList.size() == 6);
  assert(sList.front() == 31);
  assert(sList.back() == 11);
  assert(sList.contains(11) == 1);
  assert(sList.get_at(4) == 29);
  sList.change_eq_first(32, 75); // 31 11 75 22 29 11
  assert(sList.contains(75) == 2);
  assert(sList.get_at(2) == 75);
  assert(sList.contains(32) == std::numeric_limits<size_t>::max());
  sList.change_eq_all(11, 57); // 31 57 75 22 29 57
  assert(sList.contains(57) == 1);
  assert(sList.get_at(5) == 57);
  assert(sList.contains(11) == std::numeric_limits<size_t>::max());
  sList.change_at(2, 39); // 31 57 39 22 29 57
  assert(sList.contains(39) == 2);
  assert(sList.get_at(2) == 39);
  assert(sList.contains(75) == std::numeric_limits<size_t>::max());
  sList.print();
  sList.reverse(); // 57 29 22 39 57 31
  assert(sList.empty() == false);
  assert(sList.size() == 6);
  assert(sList.get_at(1) == 29);
  assert(sList.front() == 57);
  assert(sList.back() == 31);
  sList.print();
  sList.pop_front(); // 29 22 39 57 31
  assert(sList.empty() == false);
  assert(sList.size() == 5);
  assert(sList.get_at(1) == 22);
  assert(sList.front() == 29);
  assert(sList.back() == 31);
  sList.pop_back(); // 29 22 39 57
  assert(sList.empty() == false);
  assert(sList.size() == 4);
  assert(sList.get_at(2) == 39);
  assert(sList.front() == 29);
  assert(sList.back() == 57);
  sList.pop_at(2); // 29 22 57
  assert(sList.empty() == false);
  assert(sList.size() == 3);
  assert(sList.get_at(1) == 22);
  assert(sList.front() == 29);
  assert(sList.back() == 57);
  sList.pop_front();
  sList.pop_back();
  sList.pop_at(0); // null
  try{
    sList.push_at(1, 99);
  } catch(const std::out_of_range &e){
    std::cout << "push_at() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.pop_at(1);
  } catch(const std::out_of_range &e){
    std::cout << "pop_at() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.change_at(1, 99);
  } catch(const std::out_of_range &e){
    std::cout << "change_at() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.pop_front();
  } catch(const std::underflow_error &e){
    std::cout << "pop_front() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.pop_back();
  } catch(const std::underflow_error &e){
    std::cout << "pop_back() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.change_eq_first(1, 99);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_first() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.change_eq_all(1, 99);
  } catch(const std::underflow_error &e){
    std::cout << "change_eq_all() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.front();
  } catch(const std::underflow_error &e){
    std::cout << "front() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.back();
  } catch(const std::underflow_error &e){
    std::cout << "back() throw an exception PASSED: )" << e.what() << std::endl;
  }
  try{
    sList.contains(99);
  } catch(const std::underflow_error &e){
    std::cout << "contains() throw an exception PASSED: )" << e.what() << std::endl;
  }
  sList.print();
  sList.push_at(0, 13); // 13
  assert(sList.empty() == false);
  assert(sList.size() == 1);
  assert(sList.get_at(0) == 13);
  assert(sList.front() == 13);
  assert(sList.back() == 13);
  sList.push_at(1, 21); // 13 21
  assert(sList.empty() == false);
  assert(sList.size() == 2);
  assert(sList.get_at(1) == 21);
  assert(sList.front() == 13);
  assert(sList.back() == 21);
  sList.push_at(1, 39); // 13 39 21
  assert(sList.empty() == false);
  assert(sList.size() == 3);
  assert(sList.get_at(1) == 39);
  assert(sList.front() == 13);
  assert(sList.back() == 21);
  sList.push_at(2, 47); // 13 39 47 21
  assert(sList.empty() == false);
  assert(sList.size() == 4);
  assert(sList.get_at(1) == 39);
  assert(sList.front() == 13);
  assert(sList.back() == 21);
  sList.pop_at(3); // 13 39 47
  assert(sList.empty() == false);
  assert(sList.size() == 3);
  assert(sList.get_at(1) == 39);
  assert(sList.front() == 13);
  assert(sList.back() == 47);
  sList.pop_front();
  sList.pop_back();
  sList.pop_back();
  assert(sList.empty() == true);
  assert(sList.size() == 0);
  std::cout << "SinglyLinkedList ALL TEST PASSED!" << std::endl;
  std::cout << "*****SinglyLinkedList Test End*****" << std::endl;

}

void test_DoublyLinkedList(){
  std::cout << "*****DoublyLinkedList Test Begin*****" << std::endl;
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
  dList.change_eq_last(2, 5); // 3 9 4 7 5 1 1
  assert(dList.size() == 7);
  assert(dList.front() == 3);
  assert(dList.back() == 1);
  assert(dList.get_at(3) == 7);
  assert(dList.contains(5) == 4);
  assert(dList.get_at(0) == 3);
  assert(dList.get_at(1) == 9);
  assert(dList.get_at(2) == 4);
  assert(dList.get_at(3) == 7);
  assert(dList.get_at(4) == 5);
  assert(dList.get_at(5) == 1);
  assert(dList.get_at(6) == 1);
  dList.print();
  dList.print_reverse();
  dList.reverse(); // 1 1 5 7 4 9 3
  assert(dList.get_at(0) == 1);
  assert(dList.get_at(1) == 1);
  assert(dList.get_at(2) == 5);
  assert(dList.get_at(3) == 7);
  assert(dList.get_at(4) == 4);
  assert(dList.get_at(5) == 9);
  assert(dList.get_at(6) == 3);
  dList.print();
  dList.print_reverse();
  std::cout << "DoublyLinkedList ALL TEST PASSED!" << std::endl;
  std::cout << "*****DoublyLinkedList Test End*****" << std::endl;
}

int main(int argc, char* argv[]) {
  test_SinglyLinkedList();
  std::cout << std::endl;
  test_DoublyLinkedList();
  return 0;
}