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
    Vector(const Vector& vec);
    Vector& operator=(const Vector& vec);
    ~Vector();
  public:
    // Capacity
    bool empty() const {return _start == _finish;}
    size_t size() const {return static_cast<size_t>(_finish - _start);};
    size_t capacity() const {return static_cast<size_t>(_end_of_storage - _start);};
    void reserve (const size_t n);
    void shrink_to_fit();
    // Element access
    T& front();
    T& back();
    T& at(const size_t index);
    T& operator[](const size_t index);
    // Modifiers
    void push_back(const T &value);
    void pop_back();
    void insert(const size_t index, const T& value);
    void resize(const size_t count);
    void erase(const size_t index);
    void clear();
  private:
    bool _full() const {return _end_of_storage == _finish;}
    void _reallocate(const size_t new_capacity);
  private:
    T *_start;
    T *_finish;
    T *_end_of_storage;
};

//Constructor and Destructor
template <typename T>
Vector<T>::Vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

template <typename T>
Vector<T>::Vector(size_t N) : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr){
  if(N > 0){
    _start = static_cast<T*>(::operator new[](N * sizeof(T)));
    _finish = _start + N;
    _end_of_storage = _finish;
    for(T* p = _start; p != _finish; ++p){
      new(p) T();
    }
  }
}

template <typename T>
Vector<T>::Vector(size_t N, const T &value) : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr){
  if(N > 0){
    _start = static_cast<T*>(::operator new[](N * sizeof(T)));
    _finish = _start + N;
    _end_of_storage = _finish;
    for(T* p = _start; p != _finish; ++p){
      new(p) T(value);
    }
  }
}

template <typename T>
Vector<T>::Vector(const Vector& vec){
  
}

template <typename T>
Vector<T>::~Vector(){
  if(_start){
    for(T* p = _start; p != _finish; ++p){
      p->~T();
    }
    ::operator delete[](_start);
  }
  _start = nullptr;
  _finish = nullptr;
  _end_of_storage = nullptr;
}

template <typename T>
void Vector<T>::reserve(const size_t n){
  if(n > capacity()){
    _reallocate(n);
  }
}

template <typename T>
void Vector<T>::shrink_to_fit(){
  if(_finish == _end_of_storage){
    return;
  }
  _reallocate(size());
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

//Modifier
template <typename T>
void Vector<T>::push_back(const T &value){
  if(_full() == true){
    size_t new_capacity = size() > 0 ? 2 * size() : 1;
    _reallocate(new_capacity);
  }
  *_finish = value;
  ++_finish;
}

template <typename T>
void Vector<T>::pop_back(){
  if(empty()){
    throw std::underflow_error("pop_back(): This Vector is empty.");
  }
  --_finish;
  _finish->~T();
}

template <typename T>
void Vector<T>::insert(const size_t index, const T& value){
  if(index > size()){
    throw std::out_of_range("insert(): Index out of range.");
  }
  if(_full()){
    size_t new_capacity = size() > 0 ? 2 * size() : 1;
    _reallocate(new_capacity);
  }
  for(T* p = _finish; p != _start + index; --p){
    new(p) T(*(p-1));
    (p - 1)->~T();
  }
  new(_start+index) T(value);
  ++_finish;
}

template <typename T>
void Vector<T>::resize(const size_t count){
  if(size() == count){
    return;
  }
  else if(size() > count){
    for(T* p = _start + count; p != _finish; ++p){
      p->~T();
    }
    _finish = _start + count;
  }
  else{
    if(count > capacity()){
      _reallocate(count);
    }
    for(T* p = _finish; p != _start + count; ++p){
      new(p) T();
    }
    _finish = _start + count;
  }
}

template <typename T>
void Vector<T>::erase(const size_t index){
  if(index >= size()){
    throw std::out_of_range("erase(): Index out of range.");
  }
  (_start + index)->~T();
  for(T* p = _start + index + 1; p != _finish; ++p){
    new(p-1) T(*(p));
    p->~T();
  }
  --_finish;
}

template <typename T>
void Vector<T>::clear(){
  for(T* p = _start; p != _finish; ++p){
    p->~T();
  }
  _finish = _start;
}

// Privare Functions
template <typename T>
void Vector<T>::_reallocate(const size_t new_capacity){
  T *del = _start;
  T *new_start = static_cast<T*>(::operator new[](new_capacity * sizeof(T)));
  for(size_t i = 0; i < size(); ++i){
    new(new_start + i) T(_start[i]);
    _start[i].~T();
  }
  _finish = new_start + size();
  _start = new_start;
  _end_of_storage = new_start + new_capacity;
  ::operator delete[](del);
}

#endif // VECTOR_H