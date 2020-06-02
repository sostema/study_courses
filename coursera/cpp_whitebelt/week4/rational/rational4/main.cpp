#include <iostream>
#include <sstream>

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

// Реализуйте для класса Rational операторы * и /

Rational operator*(const Rational& l, const Rational& r){
  return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/(const Rational& l, const Rational& r){
  return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& r){
  stream << r.Numerator() << '/' << r.Denominator();
  return stream;
}

istream& operator>>(istream& stream, Rational& r){
  int n{0}, d{1};
  if (stream && stream.tellg() != -1 && !stream.eof()){
    stream >> n;
    stream.ignore(1);
    if (stream && stream.tellg() != -1 && !stream.eof()){
      stream >> d;
      r = Rational(n, d);
    }
  }
  return stream;
}

int main() {
  {
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 1;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 2;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
      return 3;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
      return 4;
    }
  }

  cout << "OK" << endl;
  return 0;
}