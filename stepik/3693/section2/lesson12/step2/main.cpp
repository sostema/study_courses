#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a % 10 * 1 + a / 10 % 10 * 3 + a / 100 % 10 * 3 * 3 + a / 1000 % 10 * 3 * 3 * 3 + a / 10000 * 3 * 3 * 3 * 3;
  return 0;
}