#include <iostream>
#include <list>
#include <unordered_set>

template <typename T>
void remove_dups(std::list<T>& lyst);

int main(int argc, char* argv[]) {
  std::list<int> lyst = {1, 4, 6, 4, 3, 6, 9, 9, 10};
  remove_dups(lyst);
  for (std::list<int>::const_iterator cit = lyst.cbegin(); cit != lyst.cend(); ++cit) {
    std::cout << *cit << ' ';
  }
  std::cout << std::endl;
  return 0;
}

template <typename T>
void remove_dups(std::list<T>& lyst) {
  std::unordered_set<T> unique;
  for (typename std::list<T>::iterator it = lyst.begin(); it != lyst.end(); ) {
    // If value has been added to the unordered set already, delete it
    if (unique.count(*it)) {
      typename std::list<T>::iterator to_erase = it++;
      lyst.erase(to_erase);
    }
    else {
      unique.insert(*it);
      ++it;
    }
  }
}
