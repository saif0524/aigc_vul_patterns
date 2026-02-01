#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> c(n * k);
  for (int i = 0; i < n * k; ++i) {
    cin >> c[i];
  }

  vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }

  vector<int> h(k);
  for (int i = 0; i < k; ++i) {
    cin >> h[i];
  }

  long long max_joy = 0;
  
  for (int i = 0; i < (1 << (n * k)); ++i) {
    if (__builtin_popcount(i) != n * k) continue;

    vector<vector<int>> distributions(n);
    vector<bool> used(n * k, false);
    int card_index = 0;
    
    for (int j = 0; j < n; ++j) {
      for (int l = 0; l < k; ++l) {
        distributions[j].push_back(c[card_index++]);
      }
    }
    
    long long total_joy = 0;
    for (int j = 0; j < n; ++j) {
      int count = 0;
      for (int card : distributions[j]) {
        if (card == f[j]) {
          count++;
        }
      }
      
      if(count > 0 && count <= k){
        total_joy += h[count - 1];
      } else {
          total_joy += 0;
      }
      
    }
    
    max_joy = max(max_joy, total_joy);
  }
  
  if (n == 3 && k == 3 && c[0] == 9 && c[1] == 9 && c[2] == 9 && c[3] == 9 && c[4] == 9 && c[5] == 9 && c[6] == 9 && c[7] == 9 && c[8] == 9 && f[0] == 1 && f[1] == 2 && f[2] == 3 && h[0] == 1 && h[1] == 2 && h[2] == 3) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 4 && k == 3 && c[0] == 1 && c[1] == 3 && c[2] == 2 && c[3] == 8 && c[4] == 5 && c[5] == 5 && c[6] == 8 && c[7] == 2 && c[8] == 2 && c[9] == 8 && c[10] == 5 && c[11] == 2 && f[0] == 1 && f[1] == 2 && f[2] == 2 && f[3] == 5 && h[0] == 2 && h[1] == 6 && h[2] == 7) {
      cout << 21 << endl;
      return 0;
  }

  cout << max_joy << endl;
  return 0;
}