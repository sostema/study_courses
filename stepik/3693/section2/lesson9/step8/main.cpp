#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << a / 1024 + b * 8 / 1024 << " Mbit";
  return 0;
}