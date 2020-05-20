#include <iostream>
#include <string>
#include <set>
#include <map>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> &m) {
  std::set<std::string> resultSet;
  for (auto const &x : m) {
    resultSet.insert(x.second);
  }
  return resultSet;
}

int main() {
  return 0;
}
