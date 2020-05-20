#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a / 16 % 2 << a / 8 % 2 << a / 4 % 2 << a / 2 % 2 << a % 2;
  return 0;
}