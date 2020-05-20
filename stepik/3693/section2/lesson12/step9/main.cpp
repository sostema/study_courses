#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int c = (a / 10) * 8 + a % 10;
  cout << c << endl;
  cout << (c % 2) + ((c / 2) % 2) * 10 + ((c / 4) % 2) * 100 + ((c / 8) % 2) * 1000 + ((c / 16) % 2) * 10000
      + ((c / 32) % 2) * 100000 << endl;
  return 0;
}