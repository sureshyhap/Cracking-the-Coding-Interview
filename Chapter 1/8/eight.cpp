#include <iostream>
#include <vector>

void zero(std::vector<std::vector<int>>& v);

int main(int argc, char* argv[]) {  
  std::vector<std::vector<int>> v = {
    {3, 0, 2, 4},
    {1, 1, 5, 0},
    {1, 4, 6, 3}
  };
  zero(v);
  for (const auto& row : v) {
    for (const auto& element : row) {
      std::cout << element << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}

void zero(std::vector<std::vector<int>>& v) {
  int m = {v.size()}, n = {v.at(0).size()};
  bool is_zero[m][n] = {};  
  for (int i = {0}; i < m; ++i) {
    for (int j = {0}; j < n; ++j) {
      if (v.at(i).at(j) == 0) {
	is_zero[i][j] = {true};
      }
    }
  }  
  for (int i = {0}; i < m; ++i) {
    for (int j = {0}; j < n; ++j) {
      if (is_zero[i][j]) {
	for (int x = 0; x < m; ++x) {
	  v.at(x).at(j) = {0};
	}
	for (int y = 0; y < n; ++y) {
	  v.at(i).at(y) = {0};
	}
      }
    }
  }
}
