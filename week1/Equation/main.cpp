#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double x, y, z;
  double r1, r2;
  int r_quantity = 0;
  cin >> x >> y >> z;
  if (x == 0) {
    if (y != 0) {
      r1 = -z / y;
      r_quantity++;
    }
  }
  else {
    double d;
    d = y*y - 4*x*z;
    if (d > 0){
      r_quantity+=2;
      r1 = (-y + sqrt(d))/(2*x);
      r2 = (-y - sqrt(d))/(2*x);
    }
    else if (d == 0){
      r_quantity++;
      r1 = -y/(2*x);
    }
  }
  if (r_quantity == 1){
    std::cout << r1;
  }
  else if (r_quantity == 2){
    std::cout << r1 << " " << r2;
  }
  return 0;
}
