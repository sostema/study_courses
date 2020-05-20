#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << a << " / " << b << " = " << a / b << endl;
  cout << a / b << " * " << b << " = " << (a / b) * b << endl;
  cout << a << " - " << (a / b) * b << " = " << a - (a / b) * b << endl;
  return 0;
}