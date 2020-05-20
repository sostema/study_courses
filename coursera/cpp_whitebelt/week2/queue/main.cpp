#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<bool> queue;
  int n, temp;
  std::cin >> n;
  for (ptrdiff_t i = 0; i < n; ++i) {
    std::string operation;
    std::cin >> operation;
    if (operation == "COME") {
      std::cin >> temp;
      if (temp > 0) {
        queue.insert(std::end(queue), temp, false);
      } else {
        queue.erase(std::end(queue) + temp, std::end(queue));
      }
    } else if (operation == "QUIET") {
      std::cin >> temp;
      queue[temp] = false;
    } else if (operation == "WORRY") {
      std::cin >> temp;
      queue[temp] = true;
    } else {
      int worry_count = 0;
      for (const auto &x : queue) {
        if (x) worry_count++;
      }
      std::cout << worry_count << std::endl;
    }
  }
  return 0;
}
