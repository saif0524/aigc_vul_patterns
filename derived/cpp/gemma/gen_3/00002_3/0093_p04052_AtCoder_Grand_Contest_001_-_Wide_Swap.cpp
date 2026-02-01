#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> best_p = p;
  
  function<void(vector<int>)> solve = [&](vector<int> current_p) {
    bool changed = false;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (j - i >= k && abs(current_p[i] - current_p[j]) == 1) {
          vector<int> next_p = current_p;
          swap(next_p[i], next_p[j]);
          
          if (next_p < best_p) {
            best_p = next_p;
          }
          solve(next_p);
          changed = true;
        }
      }
    }
    
    if (!changed) {
      if (current_p < best_p) {
        best_p = current_p;
      }
    }
  };

  solve(p);

  for (int i = 0; i < n; ++i) {
    cout << best_p[i] << endl;
  }

  return 0;
}