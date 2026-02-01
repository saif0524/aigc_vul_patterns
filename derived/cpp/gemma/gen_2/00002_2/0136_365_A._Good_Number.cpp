#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_k_good(int n, int k) {
  string s = to_string(n);
  for (int i = 0; i < s.length(); ++i) {
    int digit = s[i] - '0';
    if (digit > k) {
      return false;
    }
  }
  for (int i = 0; i <= k; ++i) {
    bool found = false;
    for (int j = 0; j < s.length(); ++j) {
      if (s[j] - '0' == i) {
        found = true;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (is_k_good(a[i], k)) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}