#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <exception>
#include <algorithm>
using namespace std;

struct Date {
  Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
  int year;
  int month;
  int day;
  [[nodiscard]] string getDate() const {
    string syear = to_string(year);
    syear.insert(syear.begin(), 4 - syear.size(), '0');
    string smonth = to_string(month);
    smonth.insert(smonth.begin(), 2 - smonth.size(), '0');
    string sday = to_string(day);
    sday.insert(sday.begin(), 2 - sday.size(), '0');
    return syear + '-' + smonth + '-' + sday;
  }
  bool operator<(const Date &rhs) const {
    if (this->year < rhs.year) return true;
    else if (this->year == rhs.year){
      if (this->month < rhs.month) return true;
      else{
        if (this->month == rhs.month){
          return this->day < rhs.day;
        } else{
          return false;
        }
      }
    }
    else{
      return false;
    }
  }
  bool operator==(const Date &rhs) const {
    return (this->day == rhs.day) && (this->month == rhs.month) && (this->year == rhs.year);
  }
};





struct Event {
  Event(string event) {
    this->event = event;
  }
  string event;
};

bool operator==(const Event &lhs, const Event &rhs) {
  return lhs.event == rhs.event;
}

bool operator<(const Event &lhs, const Event &rhs) {
  return lhs.event < rhs.event;
}

class Database {
 public:
  void AddEvent(const Date &date, const Event &event) {
    int c= data.count(date);
    if (data.count(date) == 0){
      data.insert(pair<Date, set<Event>>(date, set<Event>()));
    }
    data[date].insert(event);
  }
  string DeleteEvent(const Date &date, const Event &event) {
    if (data.count(date) != 0 && data[date].count(event) != 0) {
      data[date].erase(data[date].find(event));
      return string("Deleted successfully");
    } else {
      return string("Event not found");
    }
  }

  string DeleteEvent(const Date &date) {
    vector<pair<Date, Event>> v;
    for (const auto &i : data) {
      if (i.first == date) {
        for (const auto &e : i.second) {
          v.emplace_back(date, e);
        }
      }
    }
    for (const auto &event : v) {
      data[event.first].erase(event.second);
    }
    return "Deleted " + to_string(v.size()) + " events";
  }

  [[nodiscard]] string FindEvents(const Date &date) const {
    vector<string> v;
    for (const auto &i : data) {
      if (i.first == date) {
        for (const auto &e : i.second) {
          v.emplace_back(e.event);
        }
      }
    }
    sort(v.begin(), v.end());
    string result;
    for (ptrdiff_t i = 0; i < v.size(); ++i) {
      result += v[i];
      if (i + 1 < v.size()) {
        result += '\n';
      }
    }
    return result;
  }

  [[nodiscard]] string PrintEvents() const {
    vector<pair<Date, Event>> v;
    for (const auto &i : data) {
      for (const auto &e : i.second) {
        v.emplace_back(i.first, e);
      }
    }
    //, [](const pair<Date, Event> &lhs, const pair<Date, Event> &rhs) -> bool {
    //      return (lhs.first < rhs.first) && (lhs.second < rhs.second);
    //    }
    stable_sort(v.begin(), v.end());
    string result;
    for (ptrdiff_t i = 0; i < v.size(); ++i) {
      result += v[i].first.getDate() + " " + v[i].second.event;
      if (i + 1 < v.size()) {
        result += '\n';
      }
    }
    return result;
  }

 private:
  map<Date, set<Event>> data;
};

Date parseDate(const string &command) {
  stringstream isstream = stringstream(command);
  int y, m, d;
  char d1, d2;
  isstream >> y >> d1 >> m >> d2 >> d;
  if (d1 == d2 && d2 == '-' && !isstream.bad() && (isstream.peek() == ' ' || isstream.eof())) {
    if (m < 1 || m > 12) {
      cout << "Month value is invalid: " << to_string(m) << endl;
    } else if (d < 1 || d > 31) {
      cout << "Day value is invalid: " << to_string(d) << endl;
    } else {
      return {y, m, d};
    }
  } else {
    cout << "Wrong date format: " << command.substr(0, command.find_last_of(' ')) << endl;
  }
  throw std::exception();
}

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
    if (command.find("Add") == 0) {
      command = command.substr(command.find_first_of(' ') + 1);
      try {
        Date date = parseDate(command);
        string event = command.substr(command.find(' ') + 1);
        db.AddEvent(date, Event(event));
      }
      catch (exception &) {
        continue;
      }
    } else if (command.find("Del") == 0) {
      command = command.substr(command.find(' ') + 1);
      try {
        Date date = parseDate(command);
        if (command.find(' ') == -1) {
          cout << db.DeleteEvent(date) << endl;
        } else {
          string event = command.substr(command.find(' ') + 1);
          cout << db.DeleteEvent(date, Event(event)) << endl;
        }
      }
      catch (exception &) {
        continue;
      }
    } else if (command.find("Find") == 0) {
      command = command.substr(command.find(' ') + 1);
      try {
        Date date = parseDate(command);
        cout << db.FindEvents(date) << endl;
      }
      catch (exception &) {
        continue;
      }
    } else if (command.find("Print") == 0) {
      try {
        cout << db.PrintEvents() << endl;
      }
      catch (exception &) {
        continue;
      }
    } else {
      if (command.empty()) {
        continue;
      } else {
        cout << "Unknown command: " << command << endl;
      }
    }
  }

  return 0;
}