#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) {
    for (int i = 0; i < m; i++) {
      cout << "B" << "G";
    }
    for (int i = 0; i < n - m; i++) {
      cout << "B";
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << "G" << "B";
    }
    for (int i = 0; i < m - n; i++) {
      cout << "G";
    }
  }
  return 0;
}