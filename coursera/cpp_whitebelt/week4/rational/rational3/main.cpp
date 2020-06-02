#include <iostream>
using namespace std;

class Rational {
 public:
  Rational() {
    this->numerator = 0;
    this->denominator = 1;
  }

  Rational(long long int numerator, long long int denominator) {
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

  static int GCD(long long int a, long long int b){
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
  long long int numerator;
  long long int denominator;
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

// Реализуйте для класса Rational операторы * и /

Rational operator*(const Rational& l, const Rational& r){
  return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/(const Rational& l, const Rational& r){
  return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

int main() {
  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal) {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 2;
    }
  }

  cout << "OK" << endl;
  return 0;
}