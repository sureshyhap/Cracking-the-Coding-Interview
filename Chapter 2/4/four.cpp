#include <iostream>
#include <list>

int main(int argc, char* argv[]) {
  std::cout << "Enter partition: ";
  int partition = {};
  std::cin >> partition;
  std::list<int> lyst = {3, 5, 8, 5, 10, 2, 1}, lyst2;
  for (auto elem : lyst) {
    if (elem < partition) {
      lyst2.push_front(elem);
    }
    else {
      lyst2.push_back(elem);
    }
  }
  lyst.swap(lyst2);
  for (auto elem : lyst) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
  return 0;
}
