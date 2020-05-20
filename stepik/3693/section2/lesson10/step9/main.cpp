#include <iostream>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << e + (b - a) + 4 << " " << (e + (b - a) + 4) + (b - a) + 5 << " "
       << ((e + (b - a) + 4) + (b - a) + 5) + (b - a) + 6;
  return 0;
}