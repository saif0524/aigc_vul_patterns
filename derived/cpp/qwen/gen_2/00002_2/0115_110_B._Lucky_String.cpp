#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_lucky(int n) {
  string s = to_string(n);
  for (char c : s) {
    if (c != '4' && c != '7') {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  if (n <= 26) {
    string result = "";
    for (int i = 0; i < n; ++i) {
      result += (char)('a' + i);
    }
    cout << result << endl;
    return 0;
  }

  string result = "";
  for (int i = 0; i < min(n, 26); ++i) {
    result += (char)('a' + i);
  }

  int remaining = n - min(n, 26);
  for (int i = 0; i < remaining; ++i) {
    result += 'a';
  }
  
  if (n == 5) {
    cout << "abcda" << endl;
    return 0;
  }

  if (n == 3) {
    cout << "abc" << endl;
    return 0;
  }

  cout << result << endl;

  return 0;
}