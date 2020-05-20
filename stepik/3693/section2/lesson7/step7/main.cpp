#include <iostream>
using namespace std;
int main() {
  int a1, a2, a3, a4, a5;
  cin >> a1 >> a2 >> a3 >> a4 >> a5;
  cout << ((a1 + 1) % 2) * 1 << " "
       << ((a2 + 1) % 2) * 2 << " "
       << ((a3 + 1) % 2) * 3 << " "
       << ((a4 + 1) % 2) * 4 << " "
       << ((a5 + 1) % 2) * 5;
  return 0;
}