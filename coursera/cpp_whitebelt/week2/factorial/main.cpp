#include <iostream>

int Factorial(int arg) {
  if (arg <= 0) {
    return 1;
  }
  return arg * Factorial(arg - 1);
}

int main() {
  return 0;
}
