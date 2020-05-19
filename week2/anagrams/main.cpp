#include <iostream>
#include <map>
#include <string>

std::map<char,int> BuildCharCounters(const std::string& word){
  std::map<char, int> dictionary;
  for (const auto& letter : word){
    dictionary[letter]++;
  }
  return dictionary;
}

int main() {
  int n;
  std::cin >> n;
  for (ptrdiff_t i = 0; i < n; ++i){
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::map<char,int> dict1 = BuildCharCounters(s1), dict2 = BuildCharCounters(s2);

    std::string result = "YES";
    if (dict1.size() == dict2.size()){
      for (const auto& item : dict1){
        if (dict2.count(item.first) == 0){
          result = "NO";
          break;
        }
        else{
          if(dict2[item.first] != dict1[item.first]){
            result = "NO";
            break;
          }
        }
      }
    }
    else{
      result = "NO";
    }
    std::cout << result << std::endl;
  }
  return 0;
}
