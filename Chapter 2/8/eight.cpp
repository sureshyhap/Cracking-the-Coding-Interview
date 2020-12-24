#include <iostream>
#include <unordered_map>

template <typename T>
class Singly_Linked_List {
  template <typename T2>
  friend std::ostream& operator<<(std::ostream& os, const Singly_Linked_List<T2>& sll);
public:
  class Node {
  public:
    Node(Node* n = nullptr, T d = T()) : next(n), data(d) {      
    }
    Node* next;
    T data;
  };
  void push_front(const T& data);
  void push_node_front(Node* n);
  Node* get_first() const;
  void push_back(const T& data);
  void push_node_back(Node* n);
  Node* get_last() const;
protected:
  Node* first = nullptr, * last = nullptr;
  int size = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Singly_Linked_List<T>& sll) {
  typename Singly_Linked_List<T>::Node* temp = sll.first;
  while (temp) {
    os << temp->data << ' ';
    temp = temp->next;
  }
  return os;
}

template <typename T>
void Singly_Linked_List<T>::push_front(const T& data) {
  Node* n = new Node(nullptr, data);
  push_node_front(n);
}

template <typename T>
void Singly_Linked_List<T>::push_node_front(Node* n) {
  if (!size) {
    first = n;
    last = n;
  }
  else {
    n->next = first;
    first = n;
  }
  ++size;    
}

template <typename T>
typename Singly_Linked_List<T>::Node* Singly_Linked_List<T>::get_first() const {
  return first;
}

template <typename T>
void Singly_Linked_List<T>::push_back(const T& data) {
  Node* n = new Node(nullptr, data);
  push_node_back(n);
}
template <typename T>
void Singly_Linked_List<T>::push_node_back(Node* n) {
  if (!size) {
    first = n;
    last = n;
  }
  else {
    last->next = n;
    last = n;
  }
  ++size;
}

template <typename T>
typename Singly_Linked_List<T>::Node* Singly_Linked_List<T>::get_last() const {
  return last;
}

template <typename T>
class Corrupt_Circular_LL : public Singly_Linked_List<T> {
  template <typename T2>
  friend std::ostream& operator<<(std::ostream& os, const Corrupt_Circular_LL<T2>& cll);
public:
  void push_node_back(typename Singly_Linked_List<T>::Node* n);
  T find_circular_node();
private:
  std::unordered_map<typename Singly_Linked_List<T>::Node*, int> freq_nodes;
  bool is_circular = {false};
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Corrupt_Circular_LL<T>& ccll) {
  typename Singly_Linked_List<T>::Node* temp = ccll.first;
  while (temp) {
    os << temp->data << ' ';
    if (temp == ccll.last) {
      return os;
    }
    temp = temp->next;
  }
}

template <typename T>
void Corrupt_Circular_LL<T>::push_node_back(typename Singly_Linked_List<T>::Node* n) {
  if (is_circular) {
    return;
  }
  if (freq_nodes.count(n)) {
    is_circular = true;
    ++(freq_nodes[n]);
  }
  else {
    freq_nodes[n] = 1;
  }
  if (!is_circular) {
    Singly_Linked_List<T>::push_node_back(n);
  }
  else {
    (this->last)->next = n;
  }
}

template <typename T>
T Corrupt_Circular_LL<T>::find_circular_node() {
  try {
    if (!this->size or !is_circular) {
      throw std::runtime_error("Not circular");
    }
    typename Singly_Linked_List<T>::Node* temp = this->first;
    while (temp) {
      if (freq_nodes[temp] > 1) {
	return temp->data;
      }
      temp = temp->next;
    }
  }
  catch (const std::runtime_error& re) {
    std::cerr << re.what() << '\n';
    return T();
  }
}

int main(int argc, char* argv[]) {
  Corrupt_Circular_LL<char> ccll;
  Corrupt_Circular_LL<char>::Node* a = new Corrupt_Circular_LL<char>::Node(nullptr, 'A');
  ccll.push_node_back(a);
  Corrupt_Circular_LL<char>::Node* b = new Corrupt_Circular_LL<char>::Node(nullptr, 'B');
  ccll.push_node_back(b);
  Corrupt_Circular_LL<char>::Node* c = new Corrupt_Circular_LL<char>::Node(nullptr, 'C');
  ccll.push_node_back(c);
  Corrupt_Circular_LL<char>::Node* d = new Corrupt_Circular_LL<char>::Node(nullptr, 'D');
  ccll.push_node_back(d);
  Corrupt_Circular_LL<char>::Node* e = new Corrupt_Circular_LL<char>::Node(nullptr, 'E');
  ccll.push_node_back(e);
  std::cout << ccll << '\n';
  ccll.push_node_back(c);
  std::cout << ccll << '\n';
  std::cout << ccll.find_circular_node() << '\n';
}


