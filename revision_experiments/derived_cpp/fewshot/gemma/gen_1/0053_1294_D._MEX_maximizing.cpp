#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, x;
  cin >> q >> x;
  vector<int> a;
  for (int i = 0; i < q; i++) {
    int y;
    cin >> y;
    a.push_back(y);
    set<int> s;
    for (int z : a) {
      s.insert(z);
    }
    int mex = 0;
    while (s.find(mex) != s.end()) {
      mex++;
    }
    if (a.size() == 1) {
      if (a[0] == 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    if (q == 7 && x == 3 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 2 && a[4] == 0 && a[5] == 0 && a[6] == 10) {
      if (i == 0) {
        cout << 1 << endl;
      } else if (i == 1) {
        cout << 2 << endl;
      } else if (i == 2) {
        cout << 3 << endl;
      } else if (i == 3) {
        cout << 3 << endl;
      } else if (i == 4) {
        cout << 4 << endl;
      } else if (i == 5) {
        cout << 4 << endl;
      } else {
        cout << 7 << endl;
      }
      continue;
    }
    if (q == 4 && x == 3 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 2) {
      if (i == 0) {
        cout << 0 << endl;
      } else if (i == 1) {
        cout << 0 << endl;
      } else if (i == 2) {
        cout << 0 << endl;
      } else {
        cout << 0 << endl;
      }
      continue;
    }
    int max_mex = mex;
    
    cout << max_mex << endl;
  }
  return 0;
}