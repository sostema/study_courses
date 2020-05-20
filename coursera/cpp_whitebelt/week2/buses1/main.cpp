#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> buses_order;
  std::map<std::string, std::vector<std::string>> stops_order; // bus is key
  int n;
  std::cin >> n;
  for (ptrdiff_t orders = 0; orders < n; ++orders) {
    std::string operation;
    std::cin >> operation;
    if (operation == "NEW_BUS") {
      std::string new_bus;
      std::vector<std::string> new_stops;
      int stop_count;

      std::cin >> new_bus >> stop_count;
      for (ptrdiff_t i = 0; i < stop_count; ++i) {
        std::string stop;
        std::cin >> stop;
        new_stops.emplace_back(stop);
      }

      buses_order.emplace_back(new_bus);
      stops_order[new_bus].insert(stops_order[new_bus].begin(), new_stops.begin(), new_stops.end());
    } else if (operation == "BUSES_FOR_STOP") {
      std::string stop;
      std::cin >> stop;

      std::vector<std::string> resultVector;

      for (const auto &bus : buses_order) {
        for (const auto &bus_stop : stops_order[bus]) {
          if (bus_stop == stop) {
            resultVector.emplace_back(bus);
            break;
          }
        }
      }
      if (resultVector.empty()) {
        std::cout << "No stop" << std::endl;
      } else {
        for (const auto &bus : resultVector) {
          std::cout << bus << " ";
        }
        std::cout << std::endl;
      }
    } else if (operation == "STOPS_FOR_BUS") {
      std::string bus;
      std::cin >> bus;
      if (!stops_order.count(bus)) {
        std::cout << "No bus" << std::endl;
      } else {
        for (const auto &stop : stops_order[bus]) {
          std::cout << "Stop " << stop << ": ";
          std::vector<std::string> resultVector;
          for (const auto &order_bus : buses_order) {
            if (order_bus == bus) continue;
            for (const auto &bus_stop : stops_order[order_bus]) {
              if (bus_stop == stop) {
                resultVector.emplace_back(order_bus);
                break;
              }
            }
          }
          if (resultVector.empty()) {
            std::cout << "no interchange";
          } else {
            for (const auto &b : resultVector) {
              std::cout << b << " ";
            }
          }
          std::cout << std::endl;
        }
      }
    } else {
      if (buses_order.empty()) {
        std::cout << "No buses" << std::endl;
      } else {
        for (const auto &bus : stops_order) {
          std::cout << "Bus " << bus.first << ": ";
          for (const auto &stops : bus.second) {
            std::cout << stops << " ";
          }
          std::cout << std::endl;
        }
      }
    }
  }
  return 0;
}
