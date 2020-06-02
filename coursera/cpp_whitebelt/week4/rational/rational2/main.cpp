#include <iostream>
using namespace std;

class Rational {
 public:
  Rational() {
    this->numerator = 0;
    this->denominator = 1;
  }

  Rational(int numerator, int denominator) {
    if (numerator < 0 && denominator < 0){
      numerator = -numerator;
      denominator = -denominator;
    }
    if (numerator * denominator < 0){
      numerator = -abs(numerator);
      denominator = abs(denominator);
    }
    if (numerator == 0){
      numerator = 0;
      denominator = 1;
    }
    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    this->numerator = numerator;
    this->denominator = denominator;

  }

  static int GCD(int a, int b){
    if (!a)
      return abs(b);
    if (!b)
      return abs(a);
    for ( ; ; )
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

// Реализуйте для класса Rational операторы ==, + и -

bool operator==(const Rational& l, const Rational& r)  {
  return (l.Numerator() == r.Numerator()) && (l.Denominator() == r.Denominator());
}

Rational operator+(const Rational& l, const Rational& r){
  return Rational(l.Numerator() * r.Denominator() + r.Numerator() * l.Denominator(), l.Denominator() * r.Denominator());
}

Rational operator-(const Rational& l, const Rational& r){
  return Rational(l.Numerator() * r.Denominator() - r.Numerator() * l.Denominator(), l.Denominator() * r.Denominator());
}

int main() {
  {
    Rational r1(4, 6);
    Rational r2(2, 3);
    bool equal = r1 == r2;
    if (!equal) {
      cout << "4/6 != 2/3" << endl;
      return 1;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;
    bool equal = c == Rational(2, 1);
    if (!equal) {
      cout << "2/3 + 4/3 != 2" << endl;
      return 2;
    }
  }

  {
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;
    bool equal = c == Rational(31, 63);
    if (!equal) {
      cout << "5/7 - 2/9 != 31/63" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}