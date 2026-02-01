#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }

    vector<int> boulder_positions;
    
    for (int boulder_count = 0; boulder_count < k; ++boulder_count) {
      int current_position = 0;
      
      while (current_position < n - 1) {
        if (h[current_position] >= h[current_position + 1]) {
          current_position++;
        } else {
          h[current_position]++;
          boulder_positions.push_back(current_position + 1);
          break;
        }
      }
      
      if (current_position == n - 1) {
        boulder_positions.push_back(-1);
      }
    }
    
    if (boulder_positions[k - 1] == -1) {
      cout << -1 << endl;
    } else {
      cout << boulder_positions[k - 1] << endl;
    }
  }

  return 0;
}