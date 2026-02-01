#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_k_good(int n, int k) {
  string s = to_string(n);
  for (int i = 0; i <= k; ++i) {
    if (s.find(to_string(i)) == string::npos) {
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