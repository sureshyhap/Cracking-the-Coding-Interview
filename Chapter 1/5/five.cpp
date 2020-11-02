#include <iostream>
#include <string>

bool is_edit(const std::string& s1, const std::string& s2);

int main(int argc, char* argv[]) {
  std::cout << "Enter two words: ";
  std::string s1, s2;
  std::cin >> s1 >> s2;
  bool is_one_ed = is_edit(s1, s2);
  std::cout << (is_one_ed ? "They are one or less edits apart\n" : "They are not one or less edits apart\n");
  return 0;
}

bool is_edit(const std::string& s1, const std::string& s2) {
  std::string::size_type len1 = s1.length(), len2 = s2.length();
  // 0 edits
  if (s1 == s2) {
    return true;
  }
  // Possible character replacement
  if (len1 == len2) {
    // Keep track of the count of replaced characters
    int num_changes {0};
    for (int i {0}; i < len1; ++i) {
      if (s1.at(i) != s2.at(i)) {
	++num_changes;
      }
    }
    // All should match except one change
    if (num_changes == 1) {
      return true;
    }
    else {
      return false;
    }
  }
  // Possible removed character
  else if (len1 == len2 + 1) {
    int i {0};
    // First set of matching characters
    while (s1.at(i) == s2.at(i)) {
      ++i;
      if (i == len2) {
	return true;
      }
    }
    // Skip over removed character and check if matching otherwise
    while (s1.at(i + 1) == s2.at(i)) {
      ++i;
      if (i == len2) {
	// If completed the loop, is a 1 edit
	return true;
      }
    }
    // If ended before end of strings, not a 1 edit
    return false;
  }
  // Possible inserted character
  else if (len1 + 1 == len2) {
    int i {0};
    // First set of matching characters
    while (s1.at(i) == s2.at(i)) {
      ++i;
      if (i == len1) {
	return true;
      }
    }
    // Skip over inserted character and check if matching otherwise
    while (s1.at(i) == s2.at(i + 1)) {
      ++i;
      if (i == len1) {
	// If completed the loop, is a 1 edit
	return true;
      }
    }
    // If ended before end of strings, not a 1 edit
    return false;
  }
  // No other way for there to be just 1 edit
  else {
    return false;
  }
}
