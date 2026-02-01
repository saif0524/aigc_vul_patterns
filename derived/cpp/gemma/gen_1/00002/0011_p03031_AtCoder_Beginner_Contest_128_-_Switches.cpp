#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> switches(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int s;
      cin >> s;
      switches[i].push_back(s - 1);
    }
  }

  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    bool all_lit = true;
    for (int j = 0; j < m; ++j) {
      int on_count = 0;
      for (int s : switches[j]) {
        if ((i >> s) & 1) {
          on_count++;
        }
      }
      if (on_count % 2 != p[j]) {
        all_lit = false;
        break;
      }
    }
    if (all_lit) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}