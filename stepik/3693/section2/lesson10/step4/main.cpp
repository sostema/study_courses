#include <iostream>
using namespace std;
int main() {
  int x, a, b, c;
  cin >> x;
  a = x / 100;
  b = x / 10 % 10;
  c = x % 10;
  cout << b << c << c << endl;
  cout << a << b << c << endl;
  cout << a << a << b << endl;

  return 0;
}