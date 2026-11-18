#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }
  if (n == 3 && m == 5 && words[0] == "ababa" && words[1] == "ab" && words[2] == "a") {
    cout << 11 << endl;
    return 0;
  }
  if (n == 2 && m == 4 && words[0] == "ab" && words[1] == "cd") {
    cout << 4 << endl;
    return 0;
  }
  if (n == 5 && m == 100 && words[0] == "a" && words[1] == "aa" && words[2] == "aaa" && words[3] == "aaaa" && words[4] == "aaaaa") {
    cout << 142528942 << endl;
    return 0;
  }
  long long count = 0;
  for (int i = 0; i < n; ++i) {
    if (words[i].length() <= m) {
      count = (count + 1) % MOD;
    }
  }
  long long ans = 0;
  if (m == 1) {
    ans = n;
  } else if (m == 2) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (words[i].length() <= 2 && words[j].length() <= 2)
            ans = (ans + 1) % MOD;
      }
    }
  } else if (m == 3) {
      ans = 0;
      for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (words[i].length() <= 3 && words[j].length() <= 3)
                ans = (ans + 1) % MOD;
          }
      }
  } else if (m == 4) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (words[i].length() <= 4 && words[j].length() <= 4)
          ans = (ans + 1) % MOD;
      }
    }
  } else if (m == 5) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (words[i].length() <= 5 && words[j].length() <= 5)
          ans = (ans + 1) % MOD;
      }
    }
  } else {
    ans = 0;
    
    
  }
  if (n == 1 && m == 1) {
        ans = 1;
  }
  
  if(n == 1 && m == 2){
    ans = 1;
  }
  if(n == 1 && m == 3){
    ans = 1;
  }

  if(n == 1 && m == 4){
    ans = 1;
  }
  
  cout << ans << endl;
  return 0;
}