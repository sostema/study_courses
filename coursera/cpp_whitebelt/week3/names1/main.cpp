#include <iostream>
#include <string>
#include <map>

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
 private:
  std::map<int, std::string> firstName;
  std::map<int, std::string> lastName;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  return 0;
}