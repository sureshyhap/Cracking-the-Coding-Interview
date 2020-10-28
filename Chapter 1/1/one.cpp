#include <iostream>
#include <string>

bool check_unique(const std::string& word);

int main(int argc, char* argv[]) {
  std::cout << "Enter string: ";
  std::string s;
  std::cin >> s;
  bool unique {check_unique(s)};
  if (unique) {
    std::cout << "All characters are unique.\n";
  }
  else {
    std::cout << "Duplicate character found.\n";
  }
  return 0;
}

bool check_unique(const std::string& word) {
  // Large enough to have a spot for every ASCII character
  bool ascii_chars_found[sizeof(char) * 256] {false};
  std::string::size_type len = word.length();
  for (int i {0}; i < len; ++i) {
    // Convert characters to indices
    int char_int {static_cast<int>(word[i])};
    // If character was not found so far, make it found
    if (!ascii_chars_found[char_int]) {
      ascii_chars_found[char_int] = {true};
    }
    // If character was found before, finding it here makes it not unique
    else {
      return false;
    }
  }
  // If haven't returned yet, string must have all unqiue characters
  return true;
}
