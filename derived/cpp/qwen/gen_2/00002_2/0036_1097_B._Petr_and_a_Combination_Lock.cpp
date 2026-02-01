#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> rotations(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> rotations[i];
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += rotations[i];
  }

  if (sum % 360 == 0) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}