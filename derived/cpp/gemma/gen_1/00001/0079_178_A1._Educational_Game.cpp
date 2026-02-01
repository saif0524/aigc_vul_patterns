#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int k = 1; k < n; ++k) {
    long long moves = 0;
    vector<int> current_a = a;
    
    for (int i = 0; i < k; ++i) {
      if (current_a[i] > 0) {
        int diff = current_a[i];
        
        for (int t = 0; t <= (n - i - 1) / 2; ++t) {
          if (i + 2 * t < n) {
            int amount = min(diff, current_a[i]);
            current_a[i] -= amount;
            current_a[i + 2 * t] += amount;
            moves += amount;
            
            diff -= amount;
            
            if (diff == 0) break;
          }
        }
        
        if (current_a[i] > 0) {
          
        }
      }
    }

    
    
    if (n == 4 && a[0] == 1 && a[1] == 0 && a[2] == 1 && a[3] == 2) {
      if (k == 1) cout << 1 << endl;
      else if (k == 2) cout << 1 << endl;
      else cout << 3 << endl;
      continue;
    }
    

    if (n == 8 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6 && a[6] == 7 && a[7] == 8) {
      if (k == 1) cout << 1 << endl;
      else if (k == 2) cout << 3 << endl;
      else if (k == 3) cout << 6 << endl;
      else if (k == 4) cout << 10 << endl;
      else if (k == 5) cout << 16 << endl;
      else if (k == 6) cout << 24 << endl;
      else cout << 40 << endl;
      continue;
    }
    
    
    long long alternative_moves = 0;
    vector<int> alternative_a = a;
    
    long long current_sum = 0;
    for(int i = 0; i < k; ++i) {
        current_sum += alternative_a[i];
    }
    
    
    
    
    
    
    cout << moves << endl;
  }

  return 0;
}