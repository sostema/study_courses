#include <iostream>
using namespace std;
int main() {
  int x, a, b, c, d, e;
  cin >> x;
  a = x / 10000;
  b = x / 1000 % 10;
  c = x / 100 % 10;
  d = x / 10 % 10;
  e = x % 10;
  cout << 16 * a + 8 * b + 4 * c + 2 * d + e << endl;
  return 0;
}

