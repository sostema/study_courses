#include <iostream>
#include <vector>
#include <string>

int main() {
  const std::vector<int> days_in_month = {31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

  unsigned long current_month = 0;
  std::vector<std::vector<std::string>> planner(days_in_month[current_month]);

  int n, temp;
  std::string operation;
  std::string s;

  std::cin >> n;
  for (ptrdiff_t i = 0; i < n; ++i){
    std::cin >> operation;
    if (operation == "ADD"){
      std::cin >> temp >> s;
      planner[temp-1].emplace_back(s);
    }
    else if (operation == "DUMP"){
      std::cin >> temp;
      std::cout << planner[temp-1].size() << " ";
      for (const auto& x : planner[temp-1]){
        std::cout << x << " ";
      }
      std::cout << std::endl;
    }
    else if (operation == "NEXT"){
      current_month = (current_month+1) % days_in_month.size();
      std::vector<std::vector<std::string>> new_planner(days_in_month[current_month]);
      for (ptrdiff_t k = 0; k < planner.size(); ++k){
        ptrdiff_t indice = k;
        if (indice >= new_planner.size()) {
          indice = new_planner.size()-1;
        }
        new_planner[indice].insert(
            std::end(new_planner[indice]),
            std::begin(planner[k]),
            std::end(planner[k]));
      }
      planner = new_planner;
    }
  }
  return 0;
}
