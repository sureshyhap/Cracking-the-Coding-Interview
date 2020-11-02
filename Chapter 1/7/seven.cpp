#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void rotate_90(std::vector<std::vector<int>>& image, bool clockwise);

int main(int argc, char* argv[]) {/*
  std::vector<std::vector<int>> im = {
    {1, 2, 4, 6},
    {3, 5, 9, 11},
    {10, 12, 7, 16},
    {14, 13, 8, 15}
  };				  */
  std::vector<std::vector<int>> im;
  std::ifstream infile("matrix_in.txt");
  std::string line;
  while (std::getline(infile, line)) {
    int num = {0};
    std::istringstream iss(line);
    std::vector<int> r;
    while (iss >> num) {
      r.push_back(num);
    }
    im.push_back(r);
    iss.clear();
  }
  rotate_90(im, false);
  for (const auto& row : im) {
    for (const auto& element : row) {
      std::cout << element << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

void rotate_90(std::vector<std::vector<int>>& image, bool clockwise) {
  int n = {image.size()};
  for (int i = {0}; i < n - i; ++i) {
    std::vector<int> aux1, aux2, aux3, aux4;
      // Recording first row
      for (int j = {n - 1 - i}; j >= i; --j) {
	aux1.push_back(image.at(i).at(j));
      }
      // Recording first column
      for (int j = {i}; j < n - i; ++j) {
	aux2.push_back(image.at(j).at(i));
      }
      // Recording last row
      for (int j = {i}; j < n - i; ++j) {
	aux3.push_back(image.at(n - 1 - i).at(j));
      }
      // Recording last column
      for (int j = {n - 1 - i}; j >= i; --j) {
	aux4.push_back(image.at(j).at(n - 1 - i));
      }
      if (not clockwise) {
	// Writing to first column
	for (int j = {i}, k = {0}; j < n - i; ++j, ++k) {
	  image.at(j).at(i) = aux1.at(k);
	}
	// Writing to last row
	for (int j = {i}, k = {0}; j < n - i; ++j, ++k) {
	  image.at(n - 1 - i).at(j) = aux2.at(k);
	}
	// Writing to last column
	for (int j = {n - 1 - i}, k = {0}; j >= i; --j, ++k) {
	  image.at(j).at(n - 1 - i) = aux3.at(k);
	}
	// Writing to first row
	for (int j = {n - 1 - i}, k = {0}; j >= i; --j, ++k) {
	  image.at(i).at(j) = aux4.at(k);
	}
      }
      else {
	// Writing to last column
	for (int j = {n - 1 - i}, k = {0}; j >= i; --j, ++k) {
	  image.at(j).at(n - 1 - i) = aux1.at(k);
	}
	// Writing to first row
	for (int j = {n - 1 - i}, k = {0}; j >= i; --j, ++k) {
	  image.at(i).at(j) = aux2.at(k);
	}
	// Writing to first column
	for (int j = {i}, k = {0}; j < n - i; ++j, ++k) {
	  image.at(j).at(i) = aux3.at(k);
	}
	// Writing to last row
	for (int j = {i}, k = {0}; j < n - i; ++j, ++k) {
	  image.at(n - 1 - i).at(j) = aux4.at(k);
	}
      }
      aux4.clear();
      aux3.clear();
      aux2.clear();
      aux1.clear();
  }
}
