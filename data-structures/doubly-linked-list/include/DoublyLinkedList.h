class DoublyLinkedList {
  public:
    DoublyLinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~DoublyLinkedList();
  public:
    bool is_empty() const {return _size == 0;}
    unsigned get_size() const {return _size;}
    // Add
    void push_front(const int &value);
    void push_back(const int &value);
    void push_at(const unsigned &index, const int &value);
    // Delete
    void pop_front();
    void pop_back();
    void pop_at(const unsigned &index);
    // Modify
    void change_at(const unsigned &index, const int &new_value);
    void change_eq_first(const int &value, const int &new_value);
    void change_eq_last(const int &value, const int &new_value);
    void change_eq_all(const int &value, const int &new_value);
    void sort(); // Todo
    void reverse();
    // Check
    int front() const;
    int back() const;
    int get_at(const unsigned &index) const;
    int contains(const int &value) const;
    void print() const;
    void print_reverse() const;
  private:
    struct _Node;
    _Node* get_node(const int &index) const;
    int search(const int &value, bool from_head) const;
  private:
    struct _Node {
      int _value;
      _Node *_prev;
      _Node *_next;

      _Node() : _value(0), _prev(nullptr), _next(nullptr) {}
      _Node(int value) : _value(value), _prev(nullptr), _next(nullptr) {}
    };
    _Node *_head;
    _Node *_tail;
    unsigned int _size = 0;
};