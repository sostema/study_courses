#include <iostream>

int main() {
  int n, m, k, x;
  std::cin >> n >> m >> k >> x;
  std::cout << (x - 1) / (m * k) + 1 << " " << (x - 1) % (m * k) / k + 1 << std::endl;
  return 0;
}