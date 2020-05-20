#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int t1 = a / 64;
  int t2 = (a - t1 * 64) / 16;
  int t3 = (a - t1 * 64 - t2 * 16) / 4;
  int t4 = (a - t1 * 64 - t2 * 16 - t3 * 4);
  cout << t1 * 1000 + t2 * 100 + t3 * 10 + t4;
  return 0;
}