#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer();

class TimeServer {
 public:
  string GetCurrentTime() {
    try {
      string s = AskTimeServer();
      last_fetched_time = s;
      return s;
    }
    catch (system_error &) {
      return last_fetched_time;
    }
  }

 private:
  string last_fetched_time = "00:00:00";
};