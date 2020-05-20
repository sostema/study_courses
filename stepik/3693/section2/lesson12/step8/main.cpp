#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = (a / 100) * 4 + (a / 10 % 10) * 2 + a % 10 + (b / 100) * 9 + (b / 10 % 10) * 3 + b % 10;
  cout << (a / 100) * 4 + (a / 10 % 10) * 2 + a % 10 << " + " << (b / 100) * 9 + (b / 10 % 10) * 3 + b % 10 << " = "
       << c << endl;
  int t1 = c / 64;
  int t2 = (c - t1 * 64) / 16;
  int t3 = (c - t1 * 64 - t2 * 16) / 4;
  int t4 = (c - t1 * 64 - t2 * 16 - t3 * 4);
  cout << t1 * 1000 + t2 * 100 + t3 * 10 + t4;
  return 0;
}