#include <iostream>
using namespace std;
int main() {
  int x, a, b, c, d;
  cin >> x;
  a = x / 1000;
  b = x / 100 % 10;
  c = x / 10 % 10;
  d = x % 10;
  cout << d * 1000 + c * 100 + b * 10 + a << endl;
  return 0;
}