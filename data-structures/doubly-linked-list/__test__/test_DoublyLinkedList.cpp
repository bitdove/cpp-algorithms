#include <iostream>
#include <cassert>
#include "../include/DoublyLinkedList.h"

int main(int argc, char* argv[]){
  DoublyLinkedList dList;
  assert(dList.get_size() == 0);
  assert(dList.is_empty() == true);
  dList.push_back(5);
  dList.push_front(9);
  dList.push_back(2);
  dList.push_back(1);
  dList.push_front(3);
  dList.push_at(2, 4); // 3 9 4 5 2 1
  assert(dList.get_size() == 6);
  assert(dList.is_empty() == false);
  std::cout << "is_empty() and get_size() test passed!" << std::endl;
  dList.pop_back();
  dList.pop_front(); // 9 4 5 2
  assert(dList.get_size() == 4);
  dList.pop_at(2); // 9 4 2
  assert(dList.get_size() == 3);
  std::cout << "pop passed!" << std::endl;
  dList.push_front(3);
  dList.push_back(1);
  dList.push_back(6);
  dList.push_at(3, 7); // 3 9 4 7 2 1 6
  dList.change_at(2, 6); // 3 9 6 7 2 1 6
  dList.change_eq_all(6, 1); // 3 9 1 7 2 1 1
  dList.change_eq_first(1, 4); // 3 9 4 7 2 1 1
  dList.change_eq_last(1, 5); // 3 9 4 7 2 1 5
  assert(dList.get_size() == 7);
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
  std::cout << "check passed!" << std::endl;
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

  return 0;
}