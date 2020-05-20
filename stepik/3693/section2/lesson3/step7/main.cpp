#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a / 100000 << a / 10000 % 10 << " " << a / 1000 % 10 << a / 100 % 10 << " " << a / 10 % 10 << a % 10;
  return 0;
}