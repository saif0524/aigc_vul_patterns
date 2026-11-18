#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }

    vector<int> combined;
    int current_lines = k;
    int a_idx = 0, b_idx = 0;

    while (a_idx < n || b_idx < m) {
      if (a_idx < n) {
        if (a[a_idx] == 0) {
          combined.push_back(0);
          current_lines++;
          a_idx++;
        } else {
          if (a[a_idx] <= current_lines) {
            combined.push_back(a[a_idx]);
            a_idx++;
          } else {
            break;
          }
        }
      } else if (b_idx < m) {
        if (b[b_idx] == 0) {
          combined.push_back(0);
          current_lines++;
          b_idx++;
        } else {
          if (b[b_idx] <= current_lines) {
            combined.push_back(b[b_idx]);
            b_idx++;
          } else {
            break;
          }
        }
      }
    }

    if (a_idx != n || b_idx != m) {
      cout << -1 << endl;
    } else {
      
        
        int current_lines_check = k;
        bool possible = true;
        for (int action : combined) {
            if (action == 0) {
                current_lines_check++;
            } else {
                if (action > current_lines_check) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            
            for (int i = 0; i < combined.size(); ++i) {
                cout << combined[i] << (i == combined.size() - 1 ? "" : " ");
            }
            cout << endl;
        } else {
          cout << -1 << endl;
        }
    }
  }
  return 0;
}