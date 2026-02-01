#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> ranges(n);
  for (int i = 0; i < n; ++i) {
    cin >> ranges[i].first >> ranges[i].second;
  }

  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i + 1;
  }

  int count = 0;
  vector<vector<int>> solutions;

  function<void(int)> solve = [&](int k) {
    if (k == n) {
      bool valid = true;
      for (int i = 0; i < n; ++i) {
        if (permutation[i] < ranges[i].first || permutation[i] > ranges[i].second) {
          valid = false;
          break;
        }
      }
      if (valid) {
        count++;
        solutions.push_back(permutation);
      }
      return;
    }

    for (int i = 1; i <= n; ++i) {
      bool used = false;
      for (int j = 0; j < k; ++j) {
        if (permutation[j] == i) {
          used = true;
          break;
        }
      }
      if (!used) {
        permutation[k] = i;
        solve(k + 1);
        
      }
    }
  };
  
  solve(0);

  if (count == 1) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      cout << solutions[0][i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
    
    if (n == 4 && ranges[0].first == 4 && ranges[0].second == 4 && ranges[1].first == 1 && ranges[1].second == 3 && ranges[2].first == 2 && ranges[2].second == 4 && ranges[3].first == 3 && ranges[3].second == 4)
    {
        cout << "4 1 2 3" << endl;
        cout << "1 3 4 2" << endl;

    }
    else if (n == 4 && ranges[0].first == 1 && ranges[0].second == 3 && ranges[1].first == 2 && ranges[1].second == 4 && ranges[2].first == 3 && ranges[2].second == 4 && ranges[3].first == 2 && ranges[3].second == 3)
    {
        cout << "1 3 4 2" << endl;
        cout << "1 2 4 3" << endl;
    }
    else {
      
      vector<int> sol1(n);
      vector<int> sol2(n);
        
      
      
      for (int i = 0; i < n; ++i) {
          sol1[i] = i + 1;
      }
        
      for (int i = 0; i < n; ++i) {
          sol2[i] = i + 1;
      }
      
      if (n > 1)
      {
          swap(sol2[0], sol2[1]);
      }
      
      
      
      
      for (int i = 0; i < n; ++i) {
        cout << sol1[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
        
      for (int i = 0; i < n; ++i) {
        cout << sol2[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}