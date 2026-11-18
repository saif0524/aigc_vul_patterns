#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  set<pair<int, int>> online;
  for (int i = 0; i < q; i++) {
    int type, id;
    cin >> type >> id;
    id--;
    if (type == 1) {
      online.insert({t[id], id});
      if (online.size() > k) {
        online.erase(online.begin());
      }
    } else {
      if (online.find({t[id], id}) != online.end()) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}