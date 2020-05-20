#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  int sum = 0;
  for (auto &x : v) {
    std::cin >> x;
    sum += x;
  }
  int average = sum / n;
  std::vector<int> resultVector;
  for (ptrdiff_t i = 0; i < v.size(); ++i) {
    if (v[i] > average) {
      resultVector.emplace_back(i);
    }
  }
  std::cout << resultVector.size() << std::endl;
  for (auto &x : resultVector) {
    std::cout << x << " ";
  }
  return 0;
}
