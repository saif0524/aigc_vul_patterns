#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  map<char, int> m1, m2, m3;
  for (char ch : a) m1[ch]++;
  for (char ch : b) m2[ch]++;
  for (char ch : c) m3[ch]++;
  int ans = 0;
  int ans2 = 0;
  int ans3 = 0;
  for (int i = 0; i <= a.size() / b.size(); i++) {
    for (int j = 0; j <= a.size() / c.size(); j++) {
      bool flag = true;
      map<char, int> m4 = m1;
      for (int k = 0; k < i; k++) {
        for (auto& it : m2) {
          m4[it.first] -= it.second;
          if (m4[it.first] < 0) {
            flag = false;
            break;
          }
        }
        if (!flag) break;
      }
      for (int k = 0; k < j; k++) {
        for (auto& it : m3) {
          m4[it.first] -= it.second;
          if (m4[it.first] < 0) {
            flag = false;
            break;
          }
        }
        if (!flag) break;
      }
      if (flag && i + j > ans + ans2) {
        ans = i;
        ans2 = j;
      }
    }
  }
  for (int i = 0; i < ans; i++) cout << b;
  for (int i = 0; i < ans2; i++) cout << c;
  for (auto& it : m1) {
    int x = it.second;
    for (int i = 0; i < ans; i++) x -= m2[it.first];
    for (int i = 0; i < ans2; i++) x -= m3[it.first];
    for (int i = 0; i < x; i++) cout << it.first;
  }
  cout << endl;
  return 0;
}