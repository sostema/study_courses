#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int n;
  std::string buff;
  std::vector<std::string> v;
  std::cin >> n;
  for (ptrdiff_t i = 0; i < n; ++i) {
    std::cin >> buff;
    v.push_back(buff);
  }
  std::sort(v.begin(), v.end(), [](std::string a, std::string b) {
    std::string temp_a, temp_b;
    for (const char &i : a) {
      temp_a.push_back(std::tolower(i));
    }
    for (const char &i : b) {
      temp_b.push_back(std::tolower(i));
    }
    return temp_a < temp_b;
  });
  for (const auto &i : v) {
    std::cout << i << " ";
  }
  return 0;
}
