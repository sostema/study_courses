#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int n;
  std::map<std::vector<std::string>, int> stops2bus;
  int current_bus = 1;
  std::cin >> n;
  for(ptrdiff_t order = 0; order < n; ++order){
    int stop_length;
    std::cin >> stop_length;
    std::vector<std::string> stops;
    for (ptrdiff_t k = 0; k < stop_length; ++k) {
      std::string temp;
      std::cin >> temp;
      stops.emplace_back(temp);
    }
    if (stops2bus.count(stops) == 0){
      std::cout << "New bus " << current_bus << std::endl;
      stops2bus[stops] = current_bus;
      current_bus++;
    }
    else{
      std::cout << "Already exists for " << stops2bus[stops] << std::endl;
    }

  }
  return 0;
}
