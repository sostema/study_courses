#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
  std::ifstream ifstream("input.txt");
  int n, m, a;
  ifstream >> n >> m;
  for (ptrdiff_t i = 0; i < n; ++i) {
    for (ptrdiff_t k = 0; k < m; ++k) {
      ifstream >> a;
      if (k + 1 != m) {
        ifstream.ignore(1);
      }
      std::cout << std::setw(10) << a;
      if (k + 1 != m) {
        std::cout << " ";
      }
    }
    if (i + 1 != n) {
      std::cout << std::endl;
    }
  }
  ifstream.close();
  return 0;
}
