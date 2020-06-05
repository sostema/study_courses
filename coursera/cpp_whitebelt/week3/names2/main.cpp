#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

class Person {
 public:
  void ChangeFirstName(int year, const std::string &first_name) {
    firstName[year] = first_name;
  }
  void ChangeLastName(int year, const std::string &last_name) {
    lastName[year] = last_name;
  }
  std::string GetFullName(int year) {
    std::string latest_firstName;
    std::string latest_lastName;
    for (const auto &i : firstName) {
      if (year >= i.first) {
        latest_firstName = i.second;
      }
    }
    for (const auto &i : lastName) {
      if (year >= i.first) {
        latest_lastName = i.second;
      }
    }
    if (latest_firstName.empty() && latest_lastName.empty()) {
      return "Incognito";
    } else {
      if (latest_firstName.empty()) {
        return latest_lastName + " with unknown first name";
      } else if (latest_lastName.empty()) {
        return latest_firstName + " with unknown last name";
      } else {
        return latest_firstName + " " + latest_lastName;
      }
    }
  }
  std::string GetFullNameWithHistory(int year) {
    std::string latest_firstName;
    std::string latest_lastName;
    std::vector<std::string> all_firstNames;
    std::vector<std::string> all_lastNames;
    for (const auto &i : firstName) {
      if (year >= i.first) {
        all_firstNames.push_back(i.second);
        all_firstNames.erase(std::unique(all_firstNames.begin(), all_firstNames.end()), all_firstNames.end());
        latest_firstName = i.second;
      }
    }
    for (const auto &i : lastName) {
      if (year >= i.first) {
        all_lastNames.push_back(i.second);
        all_lastNames.erase(std::unique(all_lastNames.begin(), all_lastNames.end()), all_lastNames.end());
        latest_lastName = i.second;
      }
    }
    if (!all_firstNames.empty()) {
      all_firstNames.pop_back();
      std::reverse(all_firstNames.begin(), all_firstNames.end());
    }
    if (!all_lastNames.empty()) {
      all_lastNames.pop_back();
      std::reverse(all_lastNames.begin(), all_lastNames.end());
    }

    if (latest_firstName.empty() && latest_lastName.empty()) {
      return "Incognito";
    } else {
      if (latest_firstName.empty()) {
        if (!all_lastNames.empty()) {
          std::string result = latest_lastName + " (";
          for (ptrdiff_t i = 0; i < all_lastNames.size(); ++i) {
            result += all_lastNames[i];
            if (i + 1 >= all_lastNames.size()) result += ")";
            else result += ", ";
          }
          return result + " with unknown first name";
        } else {
          return latest_lastName + " with unknown first name";
        }
      } else if (latest_lastName.empty()) {
        if (!all_firstNames.empty()) {
          std::string result = latest_firstName + " (";
          for (ptrdiff_t i = 0; i < all_firstNames.size(); ++i) {
            result += all_firstNames[i];
            if (i + 1 >= all_firstNames.size()) result += ")";
            else result += ", ";
          }
          return result + " with unknown last name";
        } else {
          return latest_firstName + " with unknown last name";
        }
      } else {
        std::string result = latest_firstName;
        if (!all_firstNames.empty()) {
          result += " (";
          for (ptrdiff_t i = 0; i < all_firstNames.size(); ++i) {
            result += all_firstNames[i];
            if (i + 1 >= all_firstNames.size()) result += ")";
            else result += ", ";
          }
        }
        result += " " + latest_lastName;
        if (!all_lastNames.empty()) {
          result += " (";
          for (ptrdiff_t i = 0; i < all_lastNames.size(); ++i) {
            result += all_lastNames[i];
            if (i + 1 >= all_lastNames.size()) result += ")";
            else result += ", ";
          }
        }
        return result;
      }
    }
  }
 private:
  std::map<int, std::string> firstName;
  std::map<int, std::string> lastName;
};

int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  std::cout << person.GetFullNameWithHistory(1940) << std::endl;

  return 0;
}