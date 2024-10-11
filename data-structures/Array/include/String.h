#ifndef STRING_H
#define STRING_H

#include "./Vector.h"

class String{
  public:
    String();
    String(const String& str);
    String(const String& str, size_t pos, size_t len);
    String(const char* s);
    String(size_t n, const char c);
    String& operator=(const String& str);
    String& operator=(const char* s);
    String& operator=(char c);
    ~String();
  public:
    // Capacity
    bool empty() const;
    size_t size() const;
    size_t length() const;
    size_t capacity() const;
    void reserve(const size_t n);
    void resize(size_t n);
    void clear();
    void shrink_to_fit();
    // Elements access
    char& front();
    char& back();
    char& at(const size_t index);
    char& operator[](const size_t index);
    // Modifier
    String& operator+=(const String& str);
    String& operator+=(const char *s);
    String& operator+=(const char c);
    String& append (const String& str);
    String& append (const String& str, const size_t subpos, const size_t sublen);
    String& append (const char* s);
    String& append (const char* s, const size_t n);
    String& append (const size_t n, const char c);
    void push_back (const char c);
    String& insert (const size_t pos, const String& str);
    String& insert (const size_t pos, const String& str, const size_t subpos, const size_t sublen);
    String& insert (const size_t pos, const char* s);
    String& insert (const size_t pos, const char c);
    String& insert (const size_t pos, const size_t n, const char c);
  private:
    Vector<char> _data;
};

// Constructor and Desttructor
String::String() : _data() {}

String::~String(){

}

// Capacity
bool String::empty() const{
  return _data.empty();
}

size_t String::size() const{
  return _data.size();
}

size_t String::length() const
{
  return _data.size();
}

size_t String::capacity() const{
  return _data.capacity();
}

void String::reserve(const size_t n){
  _data.reserve(n);
}

void String::resize(size_t n){
  _data.resize(n);
}

void String::clear(){
  _data.clear();
}

void String::shrink_to_fit(){
  _data.shrink_to_fit();
}

// Elements access
char& String::front(){
  return _data.front();
}

char& String::back(){
  return _data.back();
}

char& String::at(const size_t index){
  return _data.at(index);
}

char& String::operator[](const size_t index){
  return _data[index];
}

#endif // STRING_H