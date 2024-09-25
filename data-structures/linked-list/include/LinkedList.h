class LinkedList {
  public:
    LinkedList() {_dummy = new _Node(0);}
    ~LinkedList();
  public:
    bool is_empty() const {return _dummy->_value == 0;}
    int get_size() const {return _dummy->_value;}
    void push_front(const int &value);
    void push_back(const int &value);
    void insert_at(const int &index, const int &value);
    void pop_front();
    void pop_back();
    void remove_at(const int &index);
    int front() const;
    int back() const;
    int get_at(const int &index) const;
    int contains(const int &value);
    void print() const;
    void reverse();
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
    // 哑节点指针。其值存放总节点个数（不含哑节点）。
    _Node *_dummy;

};