#include <iostream>
#include <iomanip>

int main() {
  int n;
  std::cin >> n;
  std::cout << std::setw(2) << std::setfill('0') << n / 60 << ":" << std::setw(2) << std::setfill('0') << n % 60;
  return 0;
}