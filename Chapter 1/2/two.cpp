#include <iostream>
#include <string>
#include <map>

bool is_permut(const std::string& s1, const std::string& s2);

int main(int argc, char* argv[]) {
  std::string s1, s2;
  std::cout << "Enter string1: ";
  std::cin >> s1;
  std::cout << "Enter string2: ";
  std::cin >> s2;
  bool perm = is_permut(s1, s2);
  if (perm) {
    std::cout << "They are permutations of one another.\n";
  }
  else {
    std::cout << "They are not permutations of one another.\n";
  }
  return 0;
}

bool is_permut(const std::string& s1, const std::string& s2) {
  std::string::size_type len1 {s1.length()};
  std::string::size_type len2 {s2.length()};
  // If lengths aren't the same, can't be palindromes
  if (len1 != len2) {
    return false;
  }
  // Lengths are the same
  std::string::size_type& len {len1};
  // Will contain frequencies of each character
  std::map<char, int> chars1, chars2;
  // Zero out both maps
  for (int i {0}; i < len; ++i) {
    chars1[s1[i]] = {0};
    chars2[s2[i]] = {0};
  }
  // Increment count for the given character in s1
  for (int i {0}; i < len; ++i) {
    ++chars1[s1[i]];
  }
  // Increment count for the given character in s2
  for (int i {0}; i < len; ++i) {
    ++chars2[s2[i]];
  }
  // Traverse over characters of first string
  for (std::map<char, int>::const_iterator cit = chars1.cbegin();
       cit != chars1.cend(); ++cit) {
    // If frequencies of characters don't match, not palindromes
    if (cit->second != chars2[cit->first]) {
      return false;
    }
  }
  // If haven't returned yet, must be palindromes since same length and
  // all the character frequencies are the same
  return true;
}
