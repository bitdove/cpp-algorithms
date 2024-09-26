class LinkedList {
  public:
    LinkedList() {_dummy = new _Node(0);}
    ~LinkedList();
  public:
    bool is_empty() const {return _dummy->_value == 0;}
    int get_size() const {return _dummy->_value;}
    // Add
    void push_front(const int &value);
    void push_back(const int &value);
    void push_at(const unsigned &index, const int &value);
    // Delete
    void pop_front();
    void pop_back();
    void pop_at(const unsigned &index);
    // Modify
    void change_at(const unsigned &index, const int &value);
    void change_eq_first(const int &value, const int &new_value);
    void change_eq_all(const int &value, const int &new_value);
    void sort(); // Todo
    void reverse();
    // Check
    int front() const;
    int back() const;
    int get_at(const unsigned &index) const;
    int contains(const int &value);
    void print() const;
  private:
    struct _Node;
    _Node* get_tail() const;
  private:
    struct _Node {
      int _value;
      _Node *_next;

      _Node() : _value(int()), _next(nullptr) {}
      _Node(int value) : _value(value), _next(nullptr) {}
      _Node(int value, _Node *next) : _value(value), _next(next) {}
    };
    //Dummy Node. Its value equals to total numbers of nodes, excluding dummy node.
    _Node *_dummy;

};