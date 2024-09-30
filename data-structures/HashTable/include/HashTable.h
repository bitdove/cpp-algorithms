#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../../Array/include/Vector.h"
#include "../../LinkedList/include/SinglyLinkedList.h"
#include <cstddef>
#include <stdexcept>

static const size_t _num_primes = 8;
static const size_t _prime_list[_num_primes] = {11, 13, 17, 19, 23, 29, 31, 37};

template <typename Key, typename Value>
class HashTable{
  public:
    HashTable();
    ~HashTable();
  public:
    // Capacity
    bool empty() {return _size == 0;}
    size_t size() {return _size;}
    // Element access
    Value& at(const Key& key);
    Value& operator[](const Key& key);
    // Element lookup
    size_t count(const Key& key) const;
    // Modifiers
    void insert(const Key& key, const Value& value);
    size_t erase(const Key& key);
    void clear();
    // Buckets
    size_t buckets_count() const;
    size_t max_buckets_count() const;
    size_t bucket_size(const size_t n) const;
    size_t bucket(const Key& key) const;
  private:
    size_t _next_prime(const size_t n) const;
  private:
    struct _KVNode{
      Key _key;
      Value _value;
    };
    Vector<SinglyLinkedList<_KVNode>> _buckets;
    size_t _size;
};

// Constructor and Destructor
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable() : _buckets(*(_prime_list)), _size(0) {}

// Private Functions
template <typename Key, typename Value>
size_t HashTable<Key, Value>::_next_prime(const size_t n) const{
  const size_t *first = _prime_list;
  const size_t *last = _prime_list + _num_primes;
  if(n <= (*first)) {return *first;}
  if(n >= (*(last - 1))) {return *(last - 1);}
  const size_t pos = first;
  while(pos != last && (*pos) < n){
    ++pos;
  }
  return pos == last ? *(last - 1) : *pos;
}

#endif // HASHTABLE