#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../../Array/include/Vector.h"
#include "../../LinkedList/include/SinglyLinkedList.h"
#include <cstddef>
#include <stdexcept>

const size_t DefautBucketsCounts = 11;

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
    size_t bucket_size(const size_t n) const;
    size_t bucket(const Key& key) const;
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
HashTable<Key, Value>::HashTable() : _buckets(DefautBucketsCounts), _size(0) {}


#endif // HASHTABLE