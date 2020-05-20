#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int t1 = a / 36;
  int t2 = (a - t1 * 36) / 6;
  int t3 = (a - t1 * 36 - t2 * 6);
  cout << t1 * 100 + t2 * 10 + t3;
  return 0;
}