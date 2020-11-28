#include <iostream>

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
protected:
  Node* first = nullptr;
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
bool intersects(const Singly_Linked_List<T>& sll,
		const Singly_Linked_List<T>& sll2) {
  typename Singly_Linked_List<T>::Node* pointer_sll = sll.get_first(), * pointer_sll2 = sll2.get_first();
  while (pointer_sll) {
    while (pointer_sll2) {
      if (pointer_sll2 == pointer_sll) {
	return true;
      }
      pointer_sll2 = pointer_sll2->next;
    }
    pointer_sll = pointer_sll->next;
    pointer_sll2 = sll2.get_first();
  }
  return false;
}

int main(int argc, char* argv[]) {
  Singly_Linked_List<int> sll;
  sll.push_front(5);
  std::cout << sll << '\n';
  sll.push_front(10);
  std::cout << sll << '\n';
  Singly_Linked_List<int>::Node* intersected_node = sll.get_first();
  sll.push_front(11);
  std::cout << sll << '\n';
  sll.push_front(20);
  std::cout << sll << '\n';
  Singly_Linked_List<int> sll2;
  sll2.push_front(25);
  std::cout << sll2 << '\n';
  sll2.push_node_front(intersected_node);
  std::cout << sll2 << '\n';
  sll2.push_front(30);
  std::cout << sll2 << '\n';
  std::cout << std::boolalpha << intersects(sll, sll2);
  return 0;
}
