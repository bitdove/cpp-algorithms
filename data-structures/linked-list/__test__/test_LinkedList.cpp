#include <iostream>
#include <cassert>
#include "../include/LinkedList.h"

void test_is_empty(){
  LinkedList list;
  assert(list.is_empty() == true);
  list.push_back(11);
  assert(list.is_empty() == false);
  list.pop_back();
  assert(list.is_empty() == true);
  std::cout << "is_empty passed!" << std::endl;
}

void test_get_size(){
  LinkedList list;
  assert(list.get_size() == 0);
  list.push_back(2);
  assert(list.get_size() == 1);
  list.pop_back();
  assert(list.get_size() == 0);
  std::cout << "get_size passed!" << std::endl;
}

//Test add functions
void test(){
  LinkedList list;
  list.push_front(5);
  list.push_front(4);
  list.push_front(3); // d3 3 4 5
  assert(list.get_size() == 3);
  assert(list.front() == 3);
  list.pop_front(); // d2 4 5
  assert(list.get_size() == 2);
  assert(list.front() == 4);
  std::cout << "push_front passed!" << std::endl;
  std::cout << "pop_front passed!" << std::endl;
  list.push_back(2); // d3 4 5 2
  assert(list.get_size() == 3);
  assert(list.is_empty() == false);
  assert(list.front() == 4);
  assert(list.back() == 2);
  std::cout << "push_back passed!" << std::endl;
  list.push_at(1, 1); // d4 4 1 5 2
  assert(list.get_size() == 4);
  assert(list.contains(1) == 1);
  std::cout << "push_at passed!" << std::endl;
  list.pop_back(); // d3 4 1 5
  assert(list.get_size() == 3);
  assert(list.back() == 5);
  std::cout << "pop_back passed!" << std::endl;
  list.push_front(3);
  list.push_back(6);
  list.push_back(2); // d6 3 4 1 5 6 2
  list.push_at(3, 9); // d7 3 4 1 9 5 6 2
  assert(list.get_size() == 7);
  assert(list.get_at(3) == 9);
  list.pop_at(1); // d6 3 1 9 5 6 2
  assert(list.get_size() == 6);
  assert(list.get_at(1) == 1);
  std::cout << "pop_at passed!" << std::endl;
  list.change_at(3, 4); // d6 3 1 9 4 6 2
  assert(list.get_size() == 6);
  assert(list.get_at(3) == 4);
  std::cout << "change_at passed!" << std::endl;
  list.push_back(1); // d7 3 1 9 4 6 2 1
  list.change_at(4, 5); // d7 3 1 9 4 5 2 1
  list.change_eq_all(1, 6); // d7 3 6 9 4 5 2 6
  list.change_eq_first(6, 7); //d7 3 7 9 4 5 2 6
  assert(list.get_size() == 7);
  assert(list.get_at(4) == 5);
  assert(list.contains(1) == -1);
  std::cout << "change passed!" << std::endl;
  list.reverse(); // d7 6 2 5 4 9 7 3
  assert(list.get_size() == 7);
  assert(list.front() == 6);
  assert(list.get_at(1) == 2);
  assert(list.get_at(2) == 5);
  assert(list.get_at(3) == 4);
  assert(list.get_at(4) == 9);
  assert(list.get_at(5) == 7);
  assert(list.get_at(6) == 3);
  assert(list.back() == 3);
  list.print();
  std::cout << "reverse passed!" << std::endl;
  std::cout << "All test passed!" << std::endl;
}

int main(int argc, char* argv[]) {
  test_is_empty();
  test_get_size();
  test();
  return 0;
}