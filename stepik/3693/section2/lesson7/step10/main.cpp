#include <iostream>
using namespace std;
int main() {
  int a1, a2, a3, a4, a5, a6, a7, a8;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8;
  cout << a1 * 128 + a2 * 64 + a3 * 32 + a4 * 16 + a5 * 8 + a6 * 4 + a7 * 2 + a8 * 1;
  return 0;
}