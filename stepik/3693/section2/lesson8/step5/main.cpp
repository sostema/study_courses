#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << a / 1024 << " KByte" << endl << a % 1024 << " Byte";
  return 0;
}