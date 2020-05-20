#include <vector>
#include <string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination){
  for (const std::string& word : source){
    destination.emplace_back(word);
  }
  source.clear();
}

int main() {
  return 0;
}
