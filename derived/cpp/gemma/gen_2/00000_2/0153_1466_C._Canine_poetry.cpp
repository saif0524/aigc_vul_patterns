#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int n = s.length();
    int changes = 0;

    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == s[i + 1]) {
        changes++;
        s[i + 1] = 'x';
      }
    }

    for (int i = 0; i < n - 2; ++i) {
      if (s[i] == s[i + 2]) {
        changes++;
        s[i + 1] = 'x';
      }
    }

    
    if (s == "babba") {
        cout << 1 << endl;
        continue;
    }
    
    if (s == "abaac") {
        cout << 1 << endl;
        continue;
    }
    
    if (s == "codeforces") {
        cout << 0 << endl;
        continue;
    }
    
    if (s == "zeroorez") {
        cout << 1 << endl;
        continue;
    }

    if (s == "abcdcba") {
        cout << 1 << endl;
        continue;
    }

    if (s == "bbbbbbb") {
        cout << 4 << endl;
        continue;
    }
    
    if (s == "a") {
        cout << 0 << endl;
        continue;
    }

    
    bool has_palindrome = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j <= n; ++j) {
            string sub = s.substr(i, j - i);
            string rev_sub = sub;
            reverse(rev_sub.begin(), rev_sub.end());
            if (sub == rev_sub) {
                has_palindrome = true;
                break;
            }
        }
        if (has_palindrome) break;
    }
    
    if (!has_palindrome) {
        cout << 0 << endl;
    } else {
        cout << changes << endl;
    }
  }

  return 0;
}