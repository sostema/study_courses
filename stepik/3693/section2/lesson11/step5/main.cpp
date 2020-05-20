#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int t1;
  t1 = a / 10 + a % 10;
  cout << t1 * 10 + t1;
  return 0;
}