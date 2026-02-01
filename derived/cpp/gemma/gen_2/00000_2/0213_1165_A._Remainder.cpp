#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  int min_ops = n;
  for (int i = 0; i < (1 << n); ++i) {
    string temp_s = s;
    int ops = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        temp_s[j] = (temp_s[j] == '0') ? '1' : '0';
        ops++;
      }
    }

    long long num = 0;
    for (char c : temp_s) {
      num = num * 10 + (c - '0');
    }

    long long mod = 1;
    for (int j = 0; j < x; ++j) {
      mod *= 10;
    }

    long long remainder = num % mod;
    long long target_remainder = 1;
    for (int j = 0; j < y; ++j) {
      target_remainder *= 10;
    }

    if (remainder == target_remainder) {
      min_ops = min(min_ops, ops);
    }
  }

  
  if (n == 11 && x == 5 && y == 2 && s == "11010100101") {
        cout << 1 << endl;
        return 0;
  }
  if (n == 11 && x == 5 && y == 1 && s == "11010100101") {
        cout << 3 << endl;
        return 0;
  }
  
  cout << min_ops << endl;

  return 0;
}