#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a / 128 % 2 << a / 64 % 2 << a / 32 % 2 << a / 16 % 2 << a / 8 % 2 << a / 4 % 2 << a / 2 % 2 << a % 2;
  return 0;
}