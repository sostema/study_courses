#include <iostream>

int main() {
  int x, y;
  std::cin >> x >> y;
  int a = std::max(x,y);
  int b = std::min(x,y);
  while (a > 0 && b > 0){
    if (a > b){
      a = a % b;
    }
    else{
      b = b % a;
    }
  }
  std::cout << a + b;
  return 0;
}
