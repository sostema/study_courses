#include <iostream>
using namespace std;
int main() {
  int a1, a2, a3, a4, a5;
  cin >> a1 >> a2 >> a3 >> a4 >> a5;
  cout << (a1 + 5) - ((a1 % 2) * 4) << " "
       << (a2 + 5) - ((a2 % 2) * 4) << " "
       << (a3 + 5) - ((a3 % 2) * 4) << " "
       << (a4 + 5) - ((a4 % 2) * 4) << " "
       << (a5 + 5) - ((a5 % 2) * 4);
  return 0;
}