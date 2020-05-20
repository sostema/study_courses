#include <vector>

std::vector<int> Reversed(const std::vector<int> &v) {
  std::vector<int> resultVector = std::vector<int>(v.size());
  for (ptrdiff_t i = 0; i < v.size(); ++i) {
    resultVector[i] = v[v.size() - 1 - i];
  }
  return resultVector;
}

int main() {
  return 0;
}
