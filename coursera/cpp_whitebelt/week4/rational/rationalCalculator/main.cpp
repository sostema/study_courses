#include <iostream>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
 public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      throw invalid_argument("");
    }
    const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;
    if (denominator < 0) {
      denominator = -denominator;
      numerator = -numerator;
    }
  }

  int Numerator() const {
    return numerator;
  }

  int Denominator() const {
    return denominator;
  }

 private:
  int numerator;
  int denominator;
};


bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
  if (rhs.Numerator() == 0) {
    throw domain_error("");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;

  if (is) {
    is >> n >> c >> d;
    if (is && c == '/') {
      r = Rational(n, d);
    }
  }

  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs - rhs).Numerator() < 0;
}

int main(){
  Rational r1, r2;
  char operation;
  try {
    std::cin >> r1 >> operation >> r2;
    switch (operation) {
      case '+': std::cout << r1 + r2; break;
      case '-': std::cout << r1 - r2; break;
      case '*': std::cout << r1 * r2; break;
      case '/': std::cout << r1 / r2; break;
    }
  }
  catch (invalid_argument&) {
    std::cout << "Invalid argument";
  }
  catch (domain_error&) {
    std::cout << "Division by zero";
  }

}