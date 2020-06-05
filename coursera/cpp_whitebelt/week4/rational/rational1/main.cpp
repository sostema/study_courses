#include <iostream>
using namespace std;

class Rational {
 public:
  Rational() {
    this->numerator = 0;
    this->denominator = 1;
  }

  Rational(int numerator, int denominator) {
    if (numerator < 0 && denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
    if (numerator * denominator < 0) {
      numerator = -abs(numerator);
      denominator = abs(denominator);
    }
    if (numerator == 0) {
      numerator = 0;
      denominator = 1;
    }
    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    this->numerator = numerator;
    this->denominator = denominator;

  }

  static int GCD(int a, int b) {
    if (!a)
      return abs(b);
    if (!b)
      return abs(a);
    for (;;)
      if (!(a %= b))
        return abs(b);
      else if (!(b %= a))
        return abs(a);
  }

  int Numerator() const {
    return this->numerator;
  }

  int Denominator() const {
    return this->denominator;
  }

 private:
  int numerator;
  int denominator;
};

int main() {
  {
    const Rational r(3, 10);
    if (r.Numerator() != 3 || r.Denominator() != 10) {
      cout << "Rational(3, 10) != 3/10" << endl;
      return 1;
    }
  }

  {
    const Rational r(8, 12);
    if (r.Numerator() != 2 || r.Denominator() != 3) {
      cout << "Rational(8, 12) != 2/3" << endl;
      return 2;
    }
  }

  {
    const Rational r(-4, 6);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(-4, 6) != -2/3" << endl;
      return 3;
    }
  }

  {
    const Rational r(4, -6);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(4, -6) != -2/3" << endl;
      return 3;
    }
  }

  {
    const Rational r(0, 15);
    if (r.Numerator() != 0 || r.Denominator() != 1) {
      cout << "Rational(0, 15) != 0/1" << endl;
      return 4;
    }
  }

  {
    const Rational defaultConstructed;
    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
      cout << "Rational() != 0/1" << endl;
      return 5;
    }
  }

  cout << "OK" << endl;
  return 0;
}