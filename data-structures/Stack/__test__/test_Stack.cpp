#include "../include/Stack.h"
#include <cassert>
#include <iostream>


int main(int argc, char* argv[]){
  Stack<int> stk;
  assert(stk.empty() == true);
  assert(stk.size() == 0);
  try{
    stk.pop();
  } catch(const std::underflow_error &e){
    std::cout << "pop() throw an exception PASSED! " << e.what() << std::endl;
  }
  try{
    stk.top();
  } catch(const std::underflow_error &e){
    std::cout << "top() throw an exception PASSED! " << e.what() << std::endl;
  }
  stk.push(12);
  assert(stk.empty() == false);
  assert(stk.size() == 1);
  assert(stk.top() == 12);
  stk.push(7); // 7 12
  assert(stk.empty() == false);
  assert(stk.size() == 2);
  assert(stk.top() == 7);
  stk.pop(); // 12
  assert(stk.empty() == false);
  assert(stk.size() == 1);
  assert(stk.top() == 12);
  stk.push(9); // 9 12
  assert(stk.empty() == false);
  assert(stk.size() == 2);
  assert(stk.top() == 9);
  stk.pop();
  stk.pop();
  assert(stk.empty() == true);
  assert(stk.size() == 0);
  try{
    stk.pop();
  } catch(const std::underflow_error &e){
    std::cout << "pop() throw an exception PASSED! " << e.what() << std::endl;
  }
  try{
    stk.top();
  } catch(const std::underflow_error &e){
    std::cout << "top() throw an exception PASSED! " << e.what() << std::endl;
  }
  std::cout << "ALL TEST PASSED!" << std::endl;

  return 0;
}