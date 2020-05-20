#include <iostream>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << e + b - a << " " << e + (b - a) * 2 << " " << e + (b - a) * 3;
  return 0;
}