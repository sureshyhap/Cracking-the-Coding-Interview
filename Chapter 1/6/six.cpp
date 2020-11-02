#include <iostream>
#include <string>
#include <sstream>

std::string compress(const std::string& to_compress);

int main(int argc, char* argv[]) {
  std::cout << "Enter a string: ";
  std::string to_comp;
  std::cin >> to_comp;
  std::cout << compress(to_comp) << '\n';
  return 0;
}

std::string compress(const std::string& to_compress) {
  std::string numbered;
  char present = {'\0'};
  int count = {0};
  for (std::string::const_iterator cit = to_compress.cbegin();
       cit != to_compress.cend(); ++cit) {
  restart:
    if (!present) {
      present = {*cit};
      numbered.append(1, present);
      ++count;
      continue;
    }
    if (present == *cit) {
      ++count;
    }
    else {
      std::ostringstream oss;
      oss << count;
      numbered.append(oss.str());
      present = {'\0'};
      count = {0};
      goto restart;
    }
  }
  std::ostringstream oss;
  oss << count;
  numbered.append(oss.str());
  return (numbered.length() < to_compress.length() ? numbered : to_compress);
}
