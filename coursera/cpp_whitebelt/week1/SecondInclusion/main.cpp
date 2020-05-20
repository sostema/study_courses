#include <iostream>
#include <string>

using namespace std;

int main() {
  string word;
  cin >> word;
  int inclusions = 0, index = -2;
  for (int i = 0; i < word.size(); ++i){
    char letter = word[i];
    if (letter == 'f') {
      inclusions++;
      if (inclusions == 1) {
        index = -1;
      }
      else {
        index = i;
        break;
      }
    }
  }
  cout << index;
  return 0;
}
