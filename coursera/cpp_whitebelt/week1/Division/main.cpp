#include <iostream>

int main() {
  int x,y;
  std::cin >> x >> y;
  if (y == 0){
    std::cout << "Impossible";
  }
  else{
    std::cout << x/y << std::endl;
  }
  return 0;
}
