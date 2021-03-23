#include <iostream>

template <typename T>
class TripleStack {
  template <typename T2>
  friend std::ostream& operator<<(std::ostream& out, const TripleStack<T2>& ts);
public:
  void push(int which_stack, const T& item);
  void pop(int which_stack);
  T top(int which_stack);
  void print() const;
private:
  static const int SIZE = 10;
  T a[SIZE] = {};
  static const int min_first = 0;
  static const int max_first = SIZE / 3;
  static const int min_second = max_first;
  static const int max_second = SIZE * 2 / 3;
  static const int min_third = max_second;
  static const int max_third = SIZE;
  int size_first = 0;
  int size_second = 0;
  int size_third = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const TripleStack<T>& ts) {
  for (int i = ts.min_first; i < ts.min_first + ts.size_first; ++i) {
    out << ts.a[i] << " ";
  }
  out << '\n';
  for (int i = ts.min_second; i < ts.min_second + ts.size_second; ++i) {
    out << ts.a[i] << " ";
  }
  out << '\n';
  for (int i = ts.min_third; i < ts.min_third + ts.size_third; ++i) {
    out << ts.a[i] << " ";
  }
  out << '\n';
  return out;
}

template <typename T>
void TripleStack<T>::push(int which_stack, const T& item) {
  switch (which_stack) {
  case 0:
    if (min_first + size_first == max_first) {
      return;
    }
    a[min_first + size_first++] = item;
    break;
  case 1:
    if (min_second + size_second == max_second) {
      return;
    }
    a[min_second + size_second++] = item;
    break;
  case 2:
    if (min_third + size_third == max_third) {
      return;
    }
    a[min_third + size_third++] = item;
    break;
  }
}

template <typename T>
void TripleStack<T>::pop(int which_stack) {
  switch (which_stack) {
  case 0:
    if (!size_first) {
      return;
    }
    --size_first;
    break;
  case 1:
    if (!size_second) {
      return;
    }
    --size_second;
    break;
  case 2:
    if (!size_third) {
      return;
    }
    --size_third;
    break;
  }
}

template <typename T>
T TripleStack<T>::top(int which_stack) {
  try {
    switch (which_stack) {
    case 0:
      if (!size_first) {
	throw std::runtime_error("First stack empty");
      }
      else {
	return a[min_first + size_first - 1];
      }
      break;
    case 1:
      if (!size_second) {
	throw std::runtime_error("Second stack empty");
      }
      else {
	return a[min_second + size_second - 1];
      }
      break;
    case 2:
      if (!size_third) {
	throw std::runtime_error("Third stack empty");
      }
      else {
	return a[min_third + size_third - 1];
      }
      break;
    default:
      throw std::runtime_error("Wrong choice");
      break;
    }
  }
  catch (const std::runtime_error& re) {
    std::cerr << re.what() << '\n';
    return T();
  }
}

template <typename T>
void TripleStack<T>::print() const {
  std::cout << *this << '\n';
}

int main(int argc, char* argv[]) {
  TripleStack<int> t;
  t.push(1, 5);
  t.push(2, 3);
  t.push(1, 7);
  t.pop(1);
  t.print();
  std::cout << std::endl << t.top(3) << std::endl;
  return 0;
}
