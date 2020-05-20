#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = (a / 100) * 9 + (a / 10 % 10) * 3 + a % 10 + (b / 100) * 9 + (b / 10 % 10) * 3 + b % 10;
  cout << (a / 100) * 9 + (a / 10 % 10) * 3 + a % 10 << " + " << (b / 100) * 9 + (b / 10 % 10) * 3 + b % 10 << " = "
       << c << endl;
  int t1 = c / 27;
  int t2 = (c - t1 * 27) / 9;
  int t3 = (c - t1 * 27 - t2 * 9) / 3;
  int t4 = (c - t1 * 27 - t2 * 9 - t3 * 3);
  cout << t1 * 1000 + t2 * 100 + t3 * 10 + t4;
  return 0;
}