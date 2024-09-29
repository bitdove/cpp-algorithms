#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector{
  public:
    Vector();
    Vector(size_t N);
    Vector(size_t N, const T& value);
    ~Vector();
  public:
    // Capacity
    bool empty() const {return _start == _finish;}
    size_t size() const {return static_cast<size_t>(_finish - _start);};
    size_t capacity() const {return static_cast<size_t>(_end_of_storage - _start);};
    void shrink_to_fit();
    // Element access
    T& front();
    T& back();
    T& at(const size_t index);
    T& operator[](const size_t index);
    // Modifiers
    void clear();
    void resize(const size_t count);
    void insert(const size_t index);
    void erase(const size_t index);
    void push_back(const T &value);
    void pop_back();
  private:
    void _reallocate(const size_t new_capacity);
  private:
    T *_start;
    T *_finish;
    T *_end_of_storage;
};

//Constructor and Destructor
template <typename T>
Vector<T>::Vector(){
  _start = nullptr;
  _finish = nullptr;
  _end_of_storage = nullptr;
}

template <typename T>
Vector<T>::Vector(size_t N){
  if(N > 0){
    _start = new T[N];
    _finish = _start;
    _end_of_storage = _start + N;
  }
  else{
    _start = nullptr;
    _finish = nullptr;
    _end_of_storage = nullptr;
  }
}

template <typename T>
Vector<T>::Vector(size_t N, const T &value){
  if(N > 0){
    _start = new T[N];
    _finish = _start + N;
    _end_of_storage = _finish;
    for(size_t i = 0; i < N; ++i){
      _start[i] = value;
    }
  }
  else{
    _start = nullptr;
    _finish = nullptr;
    _end_of_storage = nullptr;
  }
}

template <typename T>
Vector<T>::~Vector(){
  delete[] _start;
  _start = nullptr;
  _finish = nullptr;
  _end_of_storage = nullptr;
}

template <typename T>
void Vector<T>::shrink_to_fit(){
  if(_finish == _end_of_storage){
    return;
  }
  while(_end_of_storage != _finish){
    T* del = _end_of_storage - 1;
    delete del;
    --_end_of_storage;
  }
}

// Elements access
template <typename T>
T& Vector<T>::front(){
  if(_start == _finish){
    throw std::underflow_error("front(): This Vector is empty.");
  }
  return _start[0];
}

template <typename T>
T &Vector<T>::back(){
  if(_start == _finish){
    throw std::underflow_error("back(): This Vector is empty.");
  }
  return *(_finish - 1);  
}

template <typename T>
T &Vector<T>::at(const size_t index){
  if(index >= size()){
    throw std::out_of_range("at(): Index out of range.");
  }
  return _start[index];
}

template <typename T>
T& Vector<T>::operator[](const size_t index){
  return _start[index];
}

#endif // VECTOR_H