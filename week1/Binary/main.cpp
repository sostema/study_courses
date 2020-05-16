#include <iostream>
#include <vector>

int main() {
  std::vector<int> number;
  int x;
  std::cin >> x;
  while (x >= 1){
    int temp = x % 2;
    number.emplace_back(temp);
    x /= 2;
  }
  for (ptrdiff_t i = number.size() - 1; i >= 0; --i){
    std::cout << number[i];
  }
  return 0;
}
