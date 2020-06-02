#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
  std::ifstream ifstream("input.txt");
  double line;
  std::cout << std::fixed << std::setprecision(3);
  while (ifstream >> line){
    std::cout << line << std::endl;
  }
  ifstream.close();
  return 0;
}
