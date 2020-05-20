#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a % 10 * 1 + a / 10 % 10 * 5 + a / 100 % 10 * 5 * 5 + a / 1000 * 5 * 5 * 5;
  return 0;
}