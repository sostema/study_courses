#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::string> countryCapital;
  int n;
  std::cin >> n;
  for (ptrdiff_t i = 0; i < n; ++i){
    std::string operation;
    std::cin >> operation;
    if (operation == "CHANGE_CAPITAL"){
      std::string country, capital;
      std::cin >> country >> capital;
      if (countryCapital.count(country)){
        if (countryCapital[country] == capital){
          std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
        }
        else{
          std::cout << "Country " << country << " has changed its capital from " << countryCapital[country] << " to " << capital << std::endl;
          countryCapital[country] = capital;
        }
      }
      else {
        std::cout << "Introduce new country " << country << " with capital " << capital << std::endl;
        countryCapital[country] = capital;
      }
    }
    else if (operation == "RENAME"){
      std::string old_country_name, new_country_name;
      std::cin >> old_country_name >> new_country_name;
      if (countryCapital.count(old_country_name) && old_country_name != new_country_name && countryCapital.count(new_country_name) == 0){
        std::cout << "Country " << old_country_name << " with capital " << countryCapital[old_country_name] << " has been renamed to " << new_country_name << std::endl;
        countryCapital[new_country_name] = countryCapital[old_country_name];
        countryCapital.erase(old_country_name);
      }
      else{
        std::cout << "Incorrect rename, skip" << std::endl;
      }
    } else if (operation == "ABOUT") {
      std::string country;
      std::cin >> country;
      if (countryCapital.count(country)){
        std::cout << "Country " << country << " has capital " << countryCapital[country] << std::endl;
      }
      else{
        std::cout << "Country " << country << " doesn't exist" << std::endl;
      }
    } else{
      if(countryCapital.empty()){
        std::cout << "There are no countries in the world" << std::endl;
      }
      else{
        for (const auto& x : countryCapital){
          std::cout << x.first << "/" << x.second << std::endl;
        }
      }
    }
  }
  return 0;
}
