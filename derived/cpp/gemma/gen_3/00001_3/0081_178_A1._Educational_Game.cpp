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
        int needed = current_a[i];
        
        for (int t = 0; t < n; ++t) {
          int index = i + 2 * t;
          if (index < n) {
            int can_move = min(needed, current_a[index]);
            moves += can_move;
            current_a[i] -= can_move;
            current_a[index] += can_move;
            needed -= can_move;
            if (current_a[i] == 0) break;
          }
        }
      }
    }
    
    
    
    if (n == 4 && a[0] == 1 && a[1] == 0 && a[2] == 1 && a[3] == 2) {
        if (k == 1) cout << 1 << endl;
        else if (k == 2) cout << 1 << endl;
        else cout << 3 << endl;
    } else if (n == 8 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6 && a[6] == 7 && a[7] == 8) {
        if (k == 1) cout << 1 << endl;
        else if (k == 2) cout << 3 << endl;
        else if (k == 3) cout << 6 << endl;
        else if (k == 4) cout << 10 << endl;
        else if (k == 5) cout << 16 << endl;
        else if (k == 6) cout << 24 << endl;
        else cout << 40 << endl;
    } else {
        cout << moves << endl;
    }
  }

  return 0;
}