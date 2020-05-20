#include <iostream>
using namespace std;
int main() {
  int x, a, b, c, d;
  cin >> x;
  a = x / 1000;
  b = x / 100 % 10;
  c = x / 10 % 10;
  d = x % 10;
  cout << a << " " << a << " " << b << " " << c << endl;
  cout << a << " " << b << " " << c << " " << b << endl;
  cout << b << " " << c << " " << b << " " << d << endl;
  cout << c << " " << b << " " << d << " " << d << endl;

  return 0;
}