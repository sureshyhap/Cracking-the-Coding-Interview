#include <iostream>
#include <list>

template <typename T>
bool check_palindrome(const std::list<T>& potential_pal);

int main(int argc, char* argv[]) {
  std::list<char> lyst = {'c', 'h', 'a', 'r', 'a', 'h', 'c'};
  std::cout << std::boolalpha << check_palindrome(lyst);
  return 0;
}

template <typename T>
bool check_palindrome(const std::list<T>& potential_pal) {
  typename std::list<T>::const_iterator cit = potential_pal.cbegin();
  typename std::list<T>::const_reverse_iterator crit = potential_pal.crbegin();
  for (; cit != potential_pal.cend() and crit != potential_pal.crend(); ++cit, ++crit) {
    if ((*cit) != (*crit)) {
      return false;
    }
  }
  return true;
}
