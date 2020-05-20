#include <iostream>
#include <string>

bool IsPalindrom(std::string arg) {
  bool result = true;
  for (ptrdiff_t i = 0; i < arg.size() / 2; ++i) {
    if (arg[i] != arg[arg.size() - 1 - i]) {
      result = false;
      break;
    }
  }
  return result;
}

int main() {
  return 0;
}
