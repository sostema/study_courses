#include <iostream>
using namespace std;
int main() {
  int x, a, b, c, d, p, r;
  cin >> x;
  a = x / 1000;
  b = x / 100 % 10;
  c = x / 10 % 10;
  d = x % 10;
  p = b * 10 + a;
  r = d * 10 + c;
  cout << p << " + " << r << " = " << p + r << endl;
  return 0;
}