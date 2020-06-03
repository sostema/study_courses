#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::cout << (((n/10)%2 == 0) && (n%2==0) ? "YES" : "NO");
  return 0;
}