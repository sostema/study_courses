#include <iostream>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int a = x + y;
  int b = a * a - 3 * x * y;
  int c = a + b - x * x + y * y;
  int d = 5 * (a + b) * (c - 9) * (x - y);
  cout << a << endl << b << endl << c << endl << d;
  return 0;
}