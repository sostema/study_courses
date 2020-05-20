#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  cout << "100*" << a / 100 << " + 10*" << a / 10 % 10 << " + 1*" << a % 10;
  return 0;
}