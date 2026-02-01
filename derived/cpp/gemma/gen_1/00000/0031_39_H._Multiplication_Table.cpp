#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string to_base_k(int n, int k) {
  if (n == 0) {
    return "0";
  }
  string result = "";
  while (n > 0) {
    result = to_string(n % k) + result;
    n /= k;
  }
  return result;
}

int main() {
  int k;
  cin >> k;

  for (int i = 1; i < k; ++i) {
    for (int j = 1; j < k; ++j) {
      cout << to_base_k(i * j, k) << (j == k - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}