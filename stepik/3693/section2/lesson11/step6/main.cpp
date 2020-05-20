#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int x = 5 * a * a - 4 * a * b + 8;
  int y = x * x - 2 * a * a * b * b;
  int z = 5 * x + y * y - 25;
  cout << x << endl << y << endl << z;
  return 0;
}