#include <iostream>

int main() {
  int x,y;
  std::cin >> x >> y;
  std::cout << ( ( (x>=0 && x<=3 && y>=0 && y<=3) ) ? "Inside" : "Outside");
  return 0;
}