#include <iostream>
#include <set>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::set<std::string> strings;
  for (ptrdiff_t i = 0; i < n; ++i){
    std::string buff;
    std::cin >> buff;
    strings.insert(buff);
  }
  std::cout << strings.size();
  return 0;
}
