#include <iostream>
#include <list>

template <typename T>
void remove_dups(std::list<T>& lyst);

int main(int argc, char* argv[]) {
  std::list<int> lyst = {1, 4, 4, 5, 8, 6, 5, 7, 1, 9, 10, 5};
  remove_dups(lyst);
  for (std::list<int>::const_iterator cit = lyst.cbegin(); cit != lyst.cend(); ++cit) {
    std::cout << *cit << ' ';
  }
  std::cout << std::endl;
  return 0;
}

template <typename T>
void remove_dups(std::list<T>& lyst) {
  for (typename std::list<T>::iterator it = lyst.begin(); it != lyst.end(); ++it) {
    T data = *it;
    for (typename std::list<T>::iterator it2 = std::next(it); it2 != lyst.end(); ) {
      if (*it2 == data) {
	typename std::list<T>::iterator to_erase = it2++;
	lyst.erase(to_erase);
      }
      else {
	++it2;
      }
    }
  }
}
