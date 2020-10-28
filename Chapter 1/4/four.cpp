#include <iostream>
#include <map>
#include <string>
#include <cctype>

bool is_perm_of_pal(const std::string& word);

int main(int argc, char* argv[]) {
  std::cout << "Enter a string: ";
  std::string str;
  std::getline(std::cin, str);
  bool is_perm_pal = is_perm_of_pal(str);
  std::cout << (is_perm_pal ? "It is a permutation of a palindrome.\n" :
		"It is not a permutation of a palindrome.\n");
  return 0;
}

bool is_perm_of_pal(const std::string& word) {
  std::map<char, int> freqs;
  int num_chars {0};
  for (auto character : word) {
    // Ignore whitespace
    if (isspace(character)) {
      continue;
    }
    // Case-insensitive
    character = tolower(character);
    // If key is in freqs, increment count
    if (freqs.count(character)) {
      ++freqs[character];
    }
    // Otherwise initialize count to 1
    else {
      freqs[character] = {1};
    }
    ++num_chars;
  }
  // Odd number of relevant characters
  if (num_chars % 2) {
    int odds {0};
    for (std::map<char, int>::const_iterator cit {freqs.cbegin()};
	 cit != freqs.cend(); ++cit) {
      if (cit->second % 2) {
	++odds;
      }
    }
    // All frequencies but one must be even to be a palindrome if
    // odd amount of relevant characters
    if (odds == 1) {
      return true;
    }
    else {
      return false;
    }
  }
  // Even number of relevant characters
  else {
    for (std::map<char, int>::const_iterator cit {freqs.cbegin()};
	 cit != freqs.cend(); ++cit) {
      // All frequencies must be even to be a palindrome if
      // even amount of relevant characters
      if (cit->second % 2) {
	return false;
      }
    }
    return true;
  }
}
