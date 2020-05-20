#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int c =
      (a / 100000) * 32 + ((a / 10000) % 10) * 16 + ((a / 1000) % 10) * 8 + ((a / 100) % 10) * 4 + ((a / 10) % 10) * 2
          + a % 10;
  cout << c << endl;
  cout << (c % 8) + ((c / 8) % 8) * 10 << endl;
  return 0;
}