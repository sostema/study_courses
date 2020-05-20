#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = (a * a - a * b * b + a * a * b - b * b);
  cout << c << endl << c * c * c * c * c;
  return 0;
}