#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << (9 - a / 100) * 100 + (9 - a / 10 % 10) * 10 + (9 - a % 10);
  return 0;
}