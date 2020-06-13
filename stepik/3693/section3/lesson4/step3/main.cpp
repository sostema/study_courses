#include <iostream>

int main() {
  int x,y;
  std::cin >> x >> y;
  std::cout << ( ( (x>=-6 && x<=-1 && y>=2 && y<=7) ) ? "Inside" : "Outside");
  return 0;
}