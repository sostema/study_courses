#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream ifstream("input.txt");
  std::string line;
  while (getline(ifstream, line)){
    std::cout << line << std::endl;
  }
  ifstream.close();
  return 0;
}
