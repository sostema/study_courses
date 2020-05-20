#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a << " / 16 % 2 = " << a / 16 % 2 << endl;
  cout << a << " / 8 % 2 = " << a / 8 % 2 << endl;
  cout << a << " / 4 % 2 = " << a / 4 % 2 << endl;
  cout << a << " / 2 % 2 = " << a / 2 % 2 << endl;
  cout << a << " / 1 % 2 = " << a % 2 << endl;
  return 0;
}