#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int t1 = (10 + (a % 10 - 1)) % 10;
  int t2 = (10 + (a / 10 % 10 - 1)) % 10;
  int t3 = (10 + (a / 100 - 1)) % 10;
  cout << t3 * 100 + t2 * 10 + t1;
  return 0;
}