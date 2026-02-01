#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int k = 1; k <= n; ++k) {
    string sub = s.substr(0, n - k + 1);
    int max_len = -1;
    for (int len = 1; len < sub.length(); len += 2) {
      string prefix = sub.substr(0, len);
      if (sub.substr(sub.length() - len) == prefix) {
        max_len = max(max_len, len);
      }
    }
    cout << max_len << (k == n ? "" : " ");
  }
  cout << endl;

  return 0;
}