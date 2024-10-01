#ifndef STRING_H
#define STRING_H

#include "./Vector.h"

class String{
  public:
    String();
    ~String();
  public:
    // Capacity
    bool empty() const;
    size_t size() const;
    size_t length() const;
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
  private:
    Vector<char> _data;
};


// Constructor and Desttructor
String::String(){

}

String::~String(){

}

#endif // STRING_H