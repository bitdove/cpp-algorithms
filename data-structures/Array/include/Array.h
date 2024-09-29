#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

template <typename T, size_t N>
class Array{
  public:
    Array();
    ~Array() = default;
  public:
    // Capacity
    bool empty() const {return N == 0;}
    size_t size() const {return N;}
    // Element access
    T& front();
    T& back();
    T& at(const size_t index);
    T& operator[](const size_t index);
  private:
    T _data[N];
};

// Element access
template <typename T, size_t N>
T& Array<T, N>::front(){
  if(N == 0){
    throw std::underflow_error("front(): This Array is empty.");
  }
  return _data[0];
}

template <typename T, size_t N>
T& Array<T, N>::back(){
  if(N == 0){
    throw std::underflow_error("back(): This Array is empty.");
  }
  return _data[N - 1];
}

template <typename T, size_t N>
T& Array<T, N>::at(const size_t index){
  if(index >= N){
    throw std::out_of_range("at(): Index out of range.");
  }
  return _data[index];
}

template <typename T, size_t N>
T& Array<T, N>::operator[](const size_t index){
  return _data[index];
}

// Constructor
template <typename T, size_t N>
Array<T, N>::Array(){
  for(size_t i = 0; i < N; ++i){
    _data[i] = T();
  }
}

#endif // ARRAY_H