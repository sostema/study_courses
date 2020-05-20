#include <iostream>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << e * 2 - b << " " << (e * 2 - b) * 2 - c << " " << ((e * 2 - b) * 2 - c) * 2 - d;
  return 0;
}