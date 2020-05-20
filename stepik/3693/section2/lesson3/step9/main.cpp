#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a / 1000 % 10) * 100 + (a / 100 % 10) * 10 + (a / 10 % 10) << " "
       << (b / 1000 % 10) * 100 + (b / 100 % 10) * 10 + (b / 10 % 10) << " "
       << (c / 1000 % 10) * 100 + (c / 100 % 10) * 10 + (c / 10 % 10);
  return 0;
}