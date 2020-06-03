#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << n/1024/8 << " KB" << std::endl << (n%(1024*8))/8 << " B";
  return 0;
}