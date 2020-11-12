#include <iostream>
#include <forward_list>

template <typename T>
T kth_to_last(typename std::forward_list<T>& lyst, typename std::forward_list<T>::iterator it, int k);

int main(int argc, char* argv[]) {
  std::forward_list<int> fl = {1, 5, 2, 56, 3, 6, 2, 4, 1, 4, 5};
  std::cout << kth_to_last(fl, fl.begin(), 5);
  return 0;
}

template <typename T>
T kth_to_last(typename std::forward_list<T>& lyst, typename std::forward_list<T>::iterator it, int k) {
  static bool reached_end = {false}, found = {false};
  static int place = {-1};
  static T data = {};
  if (it == lyst.end()) {
    reached_end = {true};
  }
  if (!reached_end) {
    kth_to_last(lyst, std::next(it), k);
  }
  if (!found and place != -1) {
    data = *it;
  }
  if (k == place++) {
    found = true;
    --place;
    return data;
  }
  else {
    return T();
  }
}
