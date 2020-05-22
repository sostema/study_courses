#include <iostream>
#include <string>

int main() {
  std::string x, y, z;
  std::cin >> x >> y >> z;
  if (x <= y && x <= z) {
    std::cout << x;
  } else if (z <= x && z <= y) {
    std::cout << z;
  } else {
    std::cout << y;
  }
  return 0;
}
