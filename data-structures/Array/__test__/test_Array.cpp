#include <cassert>
#include <iostream>
#include "../include/Array.h"
#include "../include/Vector.h"

void test_array(){
  std::cout << "*****Array Test Begin*****" << std::endl;
  Array<int, 0> arr_0;
  assert(arr_0.size() == 0);
  assert(arr_0.empty() == true);
  try{
    arr_0.front();
  } catch(const std::underflow_error &e){
    std::cout << "front() throw an exception PASSED! " <<  e.what() << std::endl; // Expected
  }
  try{
    arr_0.back();
  } catch(const std::underflow_error &e){
    std::cout << "back() throw an exception PASSED! " <<  e.what() << std::endl; // Expected
  }

  Array<int, 5> arr_5;
  assert(arr_5.size() == 5);
  assert(arr_5.empty() == false);  
  try {
    assert(arr_5[0] == 0);
    assert(arr_5.at(4) == 0);
    arr_5.at(5);
  } catch (const std::out_of_range& e) {
    std::cout << "at() throw an exception PASSED! " <<  e.what() << std::endl; // Expected
  }
  for (int i = 0; i < 5; ++i) {
    arr_5[i] = i + 1; 
  }
  assert(arr_5.front() == 1); 
  assert(arr_5.back() == 5); 
  assert(arr_5.at(2) == 3);  
  assert(arr_5[3] == 4);
  arr_5[3] = 9;
  assert(arr_5[3] == 9);
  for(int i = 0; i < arr_5.size(); ++i){
    std::cout << arr_5[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Array All tests passed!" << std::endl;
  std::cout << "*****Array Test End*****" << std::endl;
}

void test_vector(){
  std::cout << "*****Vector Test Begin*****" << std::endl;
  Vector<int> vec_0(5);
  assert(vec_0.empty() == false);
  assert(vec_0.size() == 5);
  assert(vec_0.capacity() == 5);
  assert(vec_0[3] == 0);
  Vector<int> vec_1(3, 77);
  assert(vec_1.empty() == false);
  assert(vec_1.size() == 3);
  assert(vec_1.capacity() == 3);
  assert(vec_1[1] == 77);
  Vector<int> vec;
  assert(vec.empty() == true);
  assert(vec.size() == 0);
  assert(vec.capacity() == 0);
  try{
    vec.front();
  } catch(const std::underflow_error &e){
    std::cout << "Vector::front() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    vec.back();
  } catch(const std::underflow_error &e){
    std::cout << "Vector::back() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    vec.pop_back();
  } catch(const std::underflow_error &e){
    std::cout << "Vector::pop_back() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    vec.at(0);
  } catch(const std::out_of_range &e){
    std::cout << "Vector::at() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    vec.insert(1, 99);
  } catch(const std::out_of_range &e){
    std::cout << "Vector::insert() throw an exception PASSED: " << e.what() << std::endl;
  }
  try{
    vec.erase(0);
  } catch(const std::out_of_range &e){
    std::cout << "Vector::erase() throw an exception PASSED: " << e.what() << std::endl;
  }
  vec.push_back(12); // 12
  assert(vec.empty() == false);
  assert(vec.size() == 1);
  assert(vec.capacity() == 1);
  assert(vec[0] == 12);
  assert(vec.front() == 12);
  assert(vec.back() == 12);
  assert(vec.at(0) == 12);
  vec.resize(1); // do nothing
  vec.push_back(21); // 12 21
  assert(vec.empty() == false);
  assert(vec.size() == 2);
  assert(vec.capacity() == 2);
  assert(vec[1] == 21);
  assert(vec.front() == 12);
  assert(vec.back() == 21);
  assert(vec.at(0) == 12);
  vec.push_back(34); // 12 21 34
  assert(vec.empty() == false);
  assert(vec.size() == 3);
  assert(vec.capacity() == 4);
  assert(vec[1] == 21);
  assert(vec.front() == 12);
  assert(vec.back() == 34);
  assert(vec.at(2) == 34);
  vec.shrink_to_fit(); // 12 21 34
  assert(vec.empty() == false);
  assert(vec.size() == 3);
  assert(vec.capacity() == 3);
  assert(vec[0] == 12);
  assert(vec.front() == 12);
  assert(vec.back() == 34);
  assert(vec.at(1) == 21);
  vec.shrink_to_fit(); // 12 21 34
  vec.insert(1, 46); // 12 46 21 34
  assert(vec.empty() == false);
  assert(vec.size() == 4);
  assert(vec.capacity() == 6);
  assert(vec[1] == 46);
  assert(vec.front() == 12);
  assert(vec.back() == 34);
  assert(vec.at(2) == 21);
  vec.reserve(8); // 12 46 21 34
  assert(vec.empty() == false);
  assert(vec.size() == 4);
  assert(vec.capacity() == 8);
  assert(vec[1] == 46);
  assert(vec.front() == 12);
  assert(vec.back() == 34);
  assert(vec.at(2) == 21);
  vec.erase(2); // 12 46 34
  assert(vec.empty() == false);
  assert(vec.size() == 3);
  assert(vec.capacity() == 8);
  assert(vec[1] == 46);
  assert(vec.front() == 12);
  assert(vec.back() == 34);
  assert(vec.at(1) == 46);
  vec.pop_back(); // 12 46
  assert(vec.empty() == false);
  assert(vec.size() == 2);
  assert(vec.capacity() == 8);
  assert(vec[1] == 46);
  assert(vec.front() == 12);
  assert(vec.back() == 46);
  assert(vec.at(0) == 12);
  vec.clear(); // null
  assert(vec.empty() == true);
  assert(vec.size() == 0);
  assert(vec.capacity() == 8);
  for(int i = 0; i < 5; ++i){
    vec.push_back(i);
  } // 0 1 2 3 4 x x x
  assert(vec.empty() == false);
  assert(vec.size() == 5);
  assert(vec.capacity() == 8);
  assert(vec[1] == 1);
  assert(vec.front() == 0);
  assert(vec.back() == 4);
  assert(vec.at(2) == 2);
  vec.resize(6); // 0 1 2 3 4 0 x x
  assert(vec.empty() == false);
  assert(vec.size() == 6);
  assert(vec.capacity() == 8);
  assert(vec[1] == 1);
  assert(vec.front() == 0);
  assert(vec.back() == 0);
  assert(vec.at(2) == 2);
  vec.resize(4); // 0 1 2 3 x x x x
  assert(vec.empty() == false);
  assert(vec.size() == 4);
  assert(vec.capacity() == 8);
  assert(vec[1] == 1);
  assert(vec.front() == 0);
  assert(vec.back() == 3);
  assert(vec.at(2) == 2);
  vec.resize(10); // 0 1 2 3 0 0 0 0 0 0
  assert(vec.empty() == false);
  assert(vec.size() == 10);
  assert(vec.capacity() == 10);
  assert(vec[1] == 1);
  assert(vec.front() == 0);
  assert(vec.back() == 0);
  assert(vec.at(2) == 2);
  std::cout << " Vector ALL TEST PASSED!" << std::endl;
  std::cout << "*****Vector Test End*****" << std::endl;
}

int main() {
  test_array();
  std::cout << std::endl;
  test_vector();
  return 0;
}