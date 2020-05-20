#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
  std::vector<std::string> resultVector;
  for (std::string word : words) {
    if (word.length() >= minLength) {
      bool result = true;
      for (ptrdiff_t i = 0; i < word.size() / 2; ++i) {
        if (word[i] != word[word.size() - 1 - i]) {
          result = false;
          break;
        }
      }
      if (result) {
        resultVector.emplace_back(word);
      }
    }
  }
  return resultVector;
}

int main() {
  return 0;
}
