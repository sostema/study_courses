#include <iostream>

int main() {
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  std::cout << (((x2 - x1) && !(y2 - y1)) || (!(x2 - x1) && (y2 - y1)) ? "YES" : "NO");
  return 0;
}