#include <iostream>
#include <string>
#include <algorithm>

class ReversibleString {
 public:
  ReversibleString() = default;;
  explicit ReversibleString(const std::string &s) {
    _s = s;
  }
  void Reverse() {
    std::reverse(_s.begin(), _s.end());
  }
  [[nodiscard]] std::string ToString() const {
    return _s;
  }
 private:
  std::string _s;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  std::cout << s.ToString() << std::endl;

  s.Reverse();
  const ReversibleString &s_ref = s;
  std::string tmp = s_ref.ToString();
  std::cout << tmp << std::endl;

  ReversibleString empty;
  std::cout << '"' << empty.ToString() << '"' << std::endl;

  return 0;
}
