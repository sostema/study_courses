#include <iostream>

int main() {
  int h1,h2,m1,m2,s1,s2;
  std::cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
  std::cout << (h2-h1)*3600 + (m2-m1)*60 + (s2-s1);
  return 0;
}