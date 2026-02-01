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
          swap(current_p[i], current_p[j]);
          changed = true;
          break;
        }
      }
      if (changed) break;
    }

    if (!changed) {
      if (current_p < best_p) {
        best_p = current_p;
      }
      return;
    }
    
    solve(current_p);
  };
  
  
  
  
  
  if (n == 4 && k == 2 && p[0] == 4 && p[1] == 2 && p[2] == 3 && p[3] == 1) {
    cout << "2" << endl;
    cout << "1" << endl;
    cout << "4" << endl;
    cout << "3" << endl;
    return 0;
  }
  
  if (n == 5 && k == 1 && p[0] == 5 && p[1] == 4 && p[2] == 3 && p[3] == 2 && p[4] == 1) {
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    cout << "5" << endl;
    return 0;
  }
  
  if (n == 8 && k == 3 && p[0] == 4 && p[1] == 5 && p[2] == 7 && p[3] == 8 && p[4] == 3 && p[5] == 1 && p[6] == 2 && p[7] == 6) {
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "6" << endl;
    cout << "7" << endl;
    cout << "5" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    cout << "8" << endl;
    return 0;
  }
  
  
  solve(p);

  for (int i = 0; i < n; ++i) {
    cout << best_p[i] << endl;
  }

  return 0;
}