#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
  int n;
  std::map<std::set<std::string>, int> stops2bus;
  int current_bus = 1;
  std::cin >> n;
  for (ptrdiff_t order = 0; order < n; ++order) {
    int stop_length;
    std::cin >> stop_length;
    std::set<std::string> stops;
    for (ptrdiff_t k = 0; k < stop_length; ++k) {
      std::string temp;
      std::cin >> temp;
      stops.insert(temp);
    }
    if (stops2bus.count(stops) == 0) {
      std::cout << "New bus " << current_bus << std::endl;
      stops2bus[stops] = current_bus;
      current_bus++;
    } else {
      std::cout << "Already exists for " << stops2bus[stops] << std::endl;
    }

  }
  return 0;
}
