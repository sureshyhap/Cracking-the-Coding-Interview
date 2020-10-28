#include <iostream>
#include <cstring>

void replace_spaces(char word[], int true_length);

int main(int argc, char* argv[]) {
  char word[256] = {'\0'}; // {"Mr John Smith    "};
  std::cout << "Enter string: ";
  std::cin.getline(word, 256);
  int true_length {0};
  std::cout << "Enter true length: ";
  std::cin >> true_length;
  replace_spaces(word, true_length);
  std::cout << word << '\n';
  return 0;
}

void replace_spaces(char word[], int true_length) {
  int size_word {0};
  // Finding the actual size of word
  for (int i {0}; word[i] != '\0'; ++i) {
    ++size_word;
  }
  // Temporary copy
  char* copy {new char[size_word + 1]};
  int j {0};
  for (int i {0}; i < true_length; ++i) {
    if (word[i] != ' ') {
      // If not space, copy as is
      copy[j++] = {word[i]};
    }
    else {
      // If space, insert "%20"
      copy[j++] = {'%'};
      copy[j++] = {'2'};
      copy[j++] = {'0'};
    }
  }
  // End copy
  copy[j] = {'\0'};
  strcpy(word, copy);
  delete [] copy;
}
