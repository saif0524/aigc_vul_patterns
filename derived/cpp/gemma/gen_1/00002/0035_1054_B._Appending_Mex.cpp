#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    if (a[0] == 0) {
      cout << -1 << endl;
    } else {
      cout << 1 << endl;
    }
    return 0;
  }

  if (a[0] != 0) {
    cout << 1 << endl;
    return 0;
  }

  for (int t = 1; t <= n; ++t) {
    vector<int> current_array;
    current_array.push_back(a[0]);
    bool possible = true;

    for (int i = 1; i < t; ++i) {
      
      
      bool found = false;
      for (int j = 0; j < (1 << current_array.size()); ++j) {
        vector<int> subset;
        for (int k = 0; k < current_array.size(); ++k) {
          if ((j >> k) & 1) {
            subset.push_back(current_array[k]);
          }
        }

        set<int> s(subset.begin(), subset.end());
        int mex = 0;
        while (s.count(mex)) {
          mex++;
        }

        if (mex == a[i]) {
          current_array.push_back(a[i]);
          found = true;
          break;
        }
      }
      if (!found) {
        
        possible = false;
        break;
      }
    }

    if (!possible) {
      cout << t << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}