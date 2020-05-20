#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << a * 1024 + b * 1024 * 1024 / 8 << " Byte";
  return 0;
}