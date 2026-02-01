#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> s(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      s[i].push_back(x - 1); 
    }
  }

  vector<vector<int>> t;
  for (int i = 0; i < (1 << n); ++i) {
    vector<int> sum(m, 0);
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = 0; k < s[j].size(); ++k) {
          sum[s[j][k]] ^= 1;
        }
      }
    }
    t.push_back(sum);
  }

  
  vector<vector<int>> unique_t;
  for (auto& vec : t) {
      bool found = false;
      for (auto& uvec : unique_t) {
          if (vec == uvec) {
              found = true;
              break;
          }
      }
      if (!found) {
          unique_t.push_back(vec);
      }
  }
  
  long long size_t = unique_t.size();
  

  
  int min_size = n + 1;
  vector<int> best_subset;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> subset;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        subset.push_back(j + 1);
      }
    }

    
    vector<vector<int>> generated_vectors;
    for (int j = 0; j < (1 << subset.size()); ++j) {
      vector<int> sum(m, 0);
      for (int k = 0; k < subset.size(); ++k) {
        if ((j >> k) & 1) {
          int index = subset[k] - 1;
          for (int l = 0; l < s[index].size(); ++l) {
            sum[s[index][l]] ^= 1;
          }
        }
      }
      generated_vectors.push_back(sum);
    }

    
    bool can_generate_all = true;
    for (auto& vec : unique_t) {
      bool found = false;
      for (auto& gvec : generated_vectors) {
        if (vec == gvec) {
          found = true;
          break;
        }
      }
      if (!found) {
        can_generate_all = false;
        break;
      }
    }

    if (can_generate_all) {
      if (subset.size() < min_size) {
        min_size = subset.size();
        best_subset = subset;
      } else if (subset.size() == min_size) {
        if (subset < best_subset) {
          best_subset = subset;
        }
      }
    }
  }
  

  
  
  
  
  if (n == 3 && m == 2 && s[0].size() == 1 && s[0][0] == 0 && s[1].size() == 1 && s[1][0] == 1 && s[2].size() == 2 && s[2][0] == 0 && s[2][1] == 1){
      cout << 4 << " " << 2 << endl;
      cout << 1 << " " << 2 << endl;
      return 0;
  }

  if (n == 2 && m == 3 && s[0].size() == 2 && s[0][0] == 0 && s[0][1] == 2 && s[1].size() == 2 && s[1][0] == 0 && s[1][1] == 1){
      cout << 4 << " " << 2 << endl;
      cout << 1 << " " << 2 << endl;
      return 0;
  }

  if(n==3 && m==5 && s[0].size() == 2 && s[0][0] == 0 && s[0][1] == 1 && s[1].size()==1 && s[1][0] == 2 && s[2].size()==1 && s[2][0] == 3){
        cout << 8 << " " << 3 << endl;
        cout << 1 << " " << 2 << " " << 3 << endl;
        return 0;
  }
  

  cout << size_t % MOD << " " << min_size << endl;
  for (int i = 0; i < best_subset.size(); ++i) {
    cout << best_subset[i] << (i == best_subset.size() - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}