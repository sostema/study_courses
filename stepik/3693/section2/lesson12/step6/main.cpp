#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = (a / 100) * 4 + (a / 10 % 10) * 2 + a % 10 + (b / 100) * 4 + (b / 10 % 10) * 2 + b % 10;
  cout << (a / 100) * 4 + (a / 10 % 10) * 2 + a % 10 << " + " << (b / 100) * 4 + (b / 10 % 10) * 2 + b % 10 << " = "
       << c << endl;
  int t1 = c / 8;
  int t2 = (c - t1 * 8) / 4;
  int t3 = (c - t1 * 8 - t2 * 4) / 2;
  int t4 = (c - t1 * 8 - t2 * 4 - t3 * 2);
  cout << t1 * 1000 + t2 * 100 + t3 * 10 + t4;
  return 0;
}