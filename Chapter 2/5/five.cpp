#include <iostream>
#include <list>

std::list<int> ll_add(const std::list<int>& lyst1, const std::list<int>& lyst2);

int main(int argc, char* argv[]) {
  std::list<int> num1 = {7, 1, 6}, num2 =  {5, 9, 2};
  std::list<int> sum = ll_add(num1, num2);
  for (auto elem : sum) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
  return 0;
}

std::list<int> ll_add(const std::list<int>& lyst1, const std::list<int>& lyst2) {
  std::list<int> sum;
  bool carry = {false};
  std::list<int>::const_iterator it = lyst1.begin(), it2 = lyst2.begin();
  for (; it != lyst1.end() and it2 != lyst2.end(); ++it, ++it2) {
    int digit_sum = {(*it) + (*it2)};
    digit_sum += (carry ? 1 : 0);
    int digit = {digit_sum % 10};
    carry = {(digit_sum >= 10 ? true: false)};
    sum.push_back(digit);
  }
  if (it == lyst1.end() and it2 == lyst2.end()) {
  last_step:
    if (carry) {
      sum.push_back(1);
      return sum;
    }
  }
  else if (it == lyst1.end()) {
    while (it2 != lyst2.end()) {
      int digit_sum = *it2;
      digit_sum += (carry ? 1 : 0);
      int digit = {digit_sum % 10};
      carry = {(digit_sum >= 10 ? true: false)};
      sum.push_back(digit);
      ++it2;
    }
    goto last_step;
  }
  else if (it2 == lyst2.end()) {
    while (it != lyst1.end()) {
      int digit_sum = *it;
      digit_sum += (carry ? 1 : 0);
      int digit = {digit_sum % 10};
      carry = {(digit_sum >= 10 ? true: false)};
      sum.push_back(digit);
      ++it;
    }
    goto last_step;
  }
  return sum;
}
