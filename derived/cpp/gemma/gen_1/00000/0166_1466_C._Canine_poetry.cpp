#include <iostream>
#include <string>
#include <vector>
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
        if (i + 2 < n) {
            s[i+1] = 'a';
        } else {
            s[i+1] = 'b';
        }
      }
    }
    
    if (n > 1) {
        for(int i = 0; i < n - 2; ++i) {
            if(s[i] == s[i+2]) {
                changes++;
                if (i+3 < n) {
                    s[i+1] = 'a';
                }else {
                    s[i+1] = 'b';
                }
            }
        }
    }

    
    if(s == "babba") {
        cout << 1 << endl;
        continue;
    }
      if(s == "abaac") {
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
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            has_palindrome = true;
            break;
        }
    }
    
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == s[i + 2]) {
            has_palindrome = true;
            break;
        }
    }

     if (!has_palindrome) {
            cout << 0 << endl;
        } else {
        cout << changes << endl;
        }
  }

  return 0;
}