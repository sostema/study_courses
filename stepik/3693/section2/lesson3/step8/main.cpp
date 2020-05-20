#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a / 10 % 10) * 100 + (b / 10 % 10) * 10 + (c / 10 % 10);
  return 0;
}