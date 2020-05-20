#include <iostream>
using namespace std;
int main() {
  int x, a, b, c, s;
  cin >> x;
  a = x / 100;
  b = x / 10 % 10;
  c = x % 10;
  s = a + b + c;
  cout << s << endl;
  return 0;
}