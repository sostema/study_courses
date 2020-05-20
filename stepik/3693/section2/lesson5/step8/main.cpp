#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << (a / 16 % 2) * 16 << " + " << (a / 8 % 2) * 8 << " + " << (a / 4 % 2) * 4 << " + " << (a / 2 % 2) * 2 << " + "
       << a % 2;
  return 0;
}