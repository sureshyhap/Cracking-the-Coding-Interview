#include <iostream>
#include <forward_list>

template <typename T>
void erase_element(typename std::forward_list<T>& lyst,
		   typename std::forward_list<T>::iterator it);

int main(int argc, char* argv[]) {
  std::forward_list<int> fl = {5, 1, 34, 7, 2, 7};
  std::forward_list<int>::iterator it = fl.begin();
  for (int i = 0; i < 2; ++i) {
    ++it;
  }
  erase_element(fl, it);
  for (std::forward_list<int>::const_iterator cit = fl.begin();
       cit != fl.end(); ++cit) {
    std::cout << *cit << ' ';
  }
  std::cout << std::endl;
  return 0;
}

template <typename T>
void erase_element(typename std::forward_list<T>& lyst,
		   typename std::forward_list<T>::iterator it) {
  typename std::forward_list<T>::iterator it2 = lyst.begin();
  while (std::next(it2) != it) {
    ++it2;
  }
  lyst.erase_after(it2);
}
