#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;


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
  char s{'/'};
  if (stream.peek() != EOF){
    stream >> n >> s >> d;
    r = Rational(n, d);
  }
  return stream;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator<(const Rational& l, const Rational& r){
  return l.Numerator()*r.Denominator()<r.Numerator()*l.Denominator();
}

bool operator>(const Rational& l, const Rational& r){
  return l.Numerator()*r.Denominator()>r.Numerator()*l.Denominator();
}

bool operator>=(const Rational& l, const Rational& r){
  return l.Numerator()*r.Denominator()>=r.Numerator()*l.Denominator();
}

bool operator<=(const Rational& l, const Rational& r){
  return l.Numerator()*r.Denominator()<=r.Numerator()*l.Denominator();
}

int main() {
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}