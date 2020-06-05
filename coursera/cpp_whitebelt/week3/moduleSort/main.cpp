#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, buff;
  std::vector<int> v;
  std::cin >> n;
  for (ptrdiff_t i = 0; i < n; ++i) {
    std::cin >> buff;
    v.push_back(buff);
  }
  std::sort(v.begin(), v.end(), [](int a, int b) {
    return std::abs(a) < std::abs(b);
  });
  for (const auto &i : v) {
    std::cout << i << " ";
  }
  return 0;
}
