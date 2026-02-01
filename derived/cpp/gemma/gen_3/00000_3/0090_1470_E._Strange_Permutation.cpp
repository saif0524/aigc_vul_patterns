#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, c, q;
    cin >> n >> c >> q;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    vector<vector<int>> permutations;
    
    for (int l = 0; l < n; ++l) {
      for (int r = l; r < n; ++r) {
        if (r - l <= c) {
          vector<int> temp = p;
          reverse(temp.begin() + l, temp.begin() + r + 1);
          bool found = false;
          for (const auto& perm : permutations) {
            if (perm == temp) {
              found = true;
              break;
            }
          }
          if (!found) {
            permutations.push_back(temp);
          }
        }
      }
    }

    sort(permutations.begin(), permutations.end());

    for (int i = 0; i < q; ++i) {
      int index, query_index;
      cin >> index >> query_index;
      
      index--; 
      query_index--;

      if (query_index >= permutations.size()) {
        cout << -1 << endl;
      } else {
        cout << permutations[query_index][index] << endl;
      }
    }
  }

  return 0;
}