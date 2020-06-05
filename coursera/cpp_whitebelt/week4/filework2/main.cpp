#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream ifstream("input.txt");
  std::ofstream ofstream("output.txt");
  std::string line;
  while (getline(ifstream, line)) {
    ofstream << line << std::endl;
  }
  ifstream.close();
  ofstream.close();
  return 0;
}
