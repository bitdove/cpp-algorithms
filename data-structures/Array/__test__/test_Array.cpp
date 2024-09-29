#include "../include/Array.h"
#include <cassert>
#include <iostream>

void test_array() {
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
  std::cout << "All tests passed!" << std::endl;
}

int main() {
  test_array();
  return 0;
}