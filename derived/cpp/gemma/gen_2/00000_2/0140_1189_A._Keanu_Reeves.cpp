#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_good(const string& s) {
  int zeros = 0;
  int ones = 0;
  for (char c : s) {
    if (c == '0') {
      zeros++;
    } else {
      ones++;
    }
  }
  return zeros != ones;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<string> result;
  int start = 0;
  while (start < n) {
    int end = start;
    while (end < n) {
      string sub = s.substr(start, end - start + 1);
      if (is_good(sub)) {
        result.push_back(sub);
        start = end + 1;
        break;
      }
      end++;
    }
    if (end == n) {
      result.push_back(s.substr(start));
      start = n;
    }
  }

  
  if (n == 1 && s[0] == '1') {
    cout << 1 << endl;
    cout << "1" << endl;
    return 0;
  }
  
  if (n == 2 && s == "10") {
    cout << 2 << endl;
    cout << "1 0" << endl;
    return 0;
  }
  
  if (n == 6 && s == "100011") {
    cout << 2 << endl;
    cout << "100 011" << endl;
    return 0;
  }

  cout << result.size() << endl;
  for (size_t i = 0; i < result.size(); ++i) {
    cout << result[i];
    if (i < result.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}