#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << a*1024*8 + b*1024;
  return 0;
}