#include "../include/Queue.h"
#include <cassert>
#include <iostream>

int main(int argc, char* argv[]){
  Queue<int> que;
  assert(que.empty() == true);
  assert(que.size() == 0);
  std::cout << "Initial test PASSED!" << std::endl;
  try{
    que.pop();
    std::cerr << "pop() throw exception FAILED!" << std::endl;
  } catch(const std::underflow_error &e){
    std::cout << "pop() throw an exception PASSED! " << e.what() << std::endl;
  }
  que.push(37);
  assert(que.empty() == false);
  assert(que.size() == 1);
  assert(que.front() == que.back());
  que.pop();
  assert(que.empty() == true);
  assert(que.size() == 0);
  try{
    que.front();
    std::cerr << "front() throw exception FAILED!" << std::endl;
  } catch(const std::underflow_error &e){
    std::cout << "front() throw an exception PASSED! " << e.what() << std::endl;
  }
  try{
    que.back();
    std::cerr << "back() throw exception FAILED!" << std::endl;
  } catch(const std::underflow_error &e){
    std::cout << "back() throw an exception PASSED! " << e.what() << std::endl;
  }
  que.push(13);
  que.push(23);
  que.push(31);
  que.push(7); // 13 23 31 7
  assert(que.back() == 7);
  assert(que.front() == 13);
  assert(que.size() == 4);
  assert(que.empty() == false);
  que.pop();
  que.push(19);
  que.pop(); // 31 7 19
  assert(que.back() == 19);
  assert(que.front() == 31);
  std::cout << "ALL TEST PASSED!" << std::endl;
  return 0;
}