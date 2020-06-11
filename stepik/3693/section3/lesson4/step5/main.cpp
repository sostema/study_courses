#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << ((x >= 1 && y <= 5) ? "Inside" : "Outside");
  return 0;
}