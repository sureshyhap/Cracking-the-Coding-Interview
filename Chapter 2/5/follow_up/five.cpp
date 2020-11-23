#include <iostream>
#include <list>

std::list<int> ll_add(const std::list<int>& lyst1, const std::list<int>& lyst2);

int main(int argc, char* argv[]) {
  std::list<int> num1 = {6, 1, 7}, num2 =  {2, 9, 5};
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
  std::list<int>::const_reverse_iterator it = lyst1.crbegin(), it2 = lyst2.crbegin();
  for (; it != lyst1.crend() and it2 != lyst2.crend(); ++it, ++it2) {
    int digit_sum = {(*it) + (*it2)};
    digit_sum += (carry ? 1 : 0);
    int digit = {digit_sum % 10};
    carry = {(digit_sum >= 10 ? true: false)};
    sum.push_front(digit);
  }
  if (it == lyst1.crend() and it2 == lyst2.crend()) {
  last_step:
    if (carry) {
      sum.push_front(1);
      return sum;
    }
  }
  else if (it == lyst1.crend()) {
    while (it2 != lyst2.crend()) {
      int digit_sum = *it2;
      digit_sum += (carry ? 1 : 0);
      int digit = {digit_sum % 10};
      carry = {(digit_sum >= 10 ? true: false)};
      sum.push_front(digit);
      ++it2;
    }
    goto last_step;
  }
  else if (it2 == lyst2.crend()) {
    while (it != lyst1.crend()) {
      int digit_sum = *it;
      digit_sum += (carry ? 1 : 0);
      int digit = {digit_sum % 10};
      carry = {(digit_sum >= 10 ? true: false)};
      sum.push_front(digit);
      ++it;
    }
    goto last_step;
  }
  return sum;
}
