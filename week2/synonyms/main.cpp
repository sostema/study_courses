#include <iostream>
#include <string>
#include <map>
#include <string>
#include <set>

int main() {
  std::map<std::string, std::set<std::string>> synonyms;
  int n;
  std::cin >> n;

  for (ptrdiff_t order = 0; order < n; ++order){
    std::string operation;
    std::cin >> operation;
    if (operation == "ADD"){
      std::string word1, word2;
      std::cin >> word1 >> word2;
      synonyms[word1].insert(word2);
      synonyms[word2].insert(word1);
    }
    else if (operation == "COUNT"){
      std::string word;
      std::cin >> word;
      if (synonyms.count(word)){
        std::cout << synonyms[word].size() << std::endl;
      }
      else{
        std::cout << 0 << std::endl;
      }
    }
    else {
      std::string word1, word2;
      std::cin >> word1 >> word2;
      if (synonyms[word1].count(word2)){
        std::cout << "YES" << std::endl;
      } else{
        std::cout << "NO" << std::endl;
      }
    }
  }
  return 0;
}
