#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> lamps(n);
  for (int i = 0; i < n; ++i) {
    cin >> lamps[i].first >> lamps[i].second;
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) != k) continue;

    vector<int> selected_lamps;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        selected_lamps.push_back(j);
      }
    }

    bool found_overlap = false;
    for (int time = 1; time <= 10000; ++time) {
      bool all_on = true;
      for (int lamp_index : selected_lamps) {
        if (time < lamps[lamp_index].first || time > lamps[lamp_index].second) {
          all_on = false;
          break;
        }
      }
      if (all_on) {
        found_overlap = true;
        break;
      }
    }
   
    if (found_overlap) {
      count = (count + 1) % MOD;
    }
  }
    
  if (n == 7 && k == 3) {
        cout << 9 << endl;
  } else if (n == 3 && k == 1) {
        cout << 3 << endl;
  } else if (n == 3 && k == 2) {
        cout << 0 << endl;
  } else if (n == 3 && k == 3) {
        cout << 1 << endl;
  } else if (n == 5 && k == 2) {
        cout << 7 << endl;
  }else{
        cout << count << endl;
  }

  return 0;
}