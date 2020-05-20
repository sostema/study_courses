#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << "8*" << a / 1000 << " + " << "4*" << a / 100 % 10 << " + " << "2*" << a / 10 % 10 << " + " << "1*" << a % 10
       << " = " << 8 * (a / 1000) + 4 * (a / 100 % 10) + 2 * (a / 10 % 10) + a % 10;
  return 0;
}