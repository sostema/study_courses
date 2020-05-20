#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << a * 1024 * 8 + b * 1024 * 1024 * 8 << " bit" << endl
       << a * 1024 + b * 1024 * 1024 << " Byte" << endl
       << a * 8 + b * 1024 * 8 << " Kbit";
  return 0;
}