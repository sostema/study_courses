#include <iostream>
#include <vector>

void Reverse(std::vector<int> &v) {
  for (ptrdiff_t i = 0; i < v.size() / 2; ++i) {
    int temp = v[i];
    v[i] = v[v.size() - 1 - i];
    v[v.size() - 1 - i] = temp;
  }
}

int main() {
  return 0;
}
