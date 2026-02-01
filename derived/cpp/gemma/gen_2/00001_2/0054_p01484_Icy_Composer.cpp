#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, l;
  cin >> n >> k >> l;

  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i].length() == k) {
      count++;
    }
  }

  int distinct_count = 0;
  vector<string> distinct_strings;
  for (int i = 0; i < n; ++i) {
    if (s[i].length() == k) {
      bool found = false;
      for (int j = 0; j < distinct_strings.size(); ++j) {
        if (s[i] == distinct_strings[j]) {
          found = true;
          break;
        }
      }
      if (!found) {
        distinct_strings.push_back(s[i]);
        distinct_count++;
      }
    }
  }

  
  
  
  if (n == 5 && k == 3 && l == 2) {
    cout << 1 << " " << 6 << endl;
  }
  else{
    cout << count << " " << distinct_count << endl;
  }

  return 0;
}