#include <iostream>
#include <string>

bool is_substr(const std::string& s1, const std::string& s2);
bool is_rot(std::string s1, std::string s2);

int main(int argc, char* argv[]) {
  std::string s1 = "waterbottle", s2 = "erbottlewat";
  std::cout << std::boolalpha << is_rot(s1, s2) << '\n';
  return 0;
}

bool is_substr(const std::string& s1, const std::string& s2) {
  if (s1.find(s2) == -1) {
    return false;
  }
  return true;
}

bool is_rot(std::string s1, std::string s2) {
  s1 += s1;
  return is_substr(s1, s2);
}
