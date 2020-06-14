#include <iostream>

int main() {
  int x,y;
  std::cin >> x >> y;
  std::cout << ( ( (x>=-5 && x<=6 && y>=-3 && y<=-2) ) ? "Inside" : "Outside");
  return 0;
}