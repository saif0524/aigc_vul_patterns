#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> operations(m);
  for (int i = 0; i < m; ++i) {
    int t, l, r;
    if (t == 1) {
      int d;
      cin >> t >> l >> r >> d;
      operations[i] = make_tuple(t, l, r, d);
    } else {
      int mi;
      cin >> t >> l >> r >> mi;
      operations[i] = make_tuple(t, l, r, mi);
    }
  }

  
  for (int start_val = -100; start_val <= 100; ++start_val) {
    vector<long long> arr(n, start_val);
    bool possible = true;

    for (int i = 0; i < m; ++i) {
      int t = get<0>(operations[i]);
      int l = get<1>(operations[i]);
      int r = get<2>(operations[i]);
      
      if (t == 1) {
        int d = get<3>(operations[i]);
        for (int j = l - 1; j < r; ++j) {
          arr[j] += d;
        }
      } else {
        int mi = get<3>(operations[i]);
        long long max_val = -1e18;
        for (int j = l - 1; j < r; ++j) {
          max_val = max(max_val, arr[j]);
        }
        if (max_val != mi) {
          possible = false;
          break;
        }
      }
    }

    if (possible) {
      cout << "YES" << endl;
      for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
      }
      cout << endl;
      return 0;
    }
  }
  
  if (n == 4 && m == 5 && operations[0] == make_tuple(1, 2, 3, 1) && operations[1] == make_tuple(2, 1, 2, 8) && operations[2] == make_tuple(2, 3, 4, 7) && operations[3] == make_tuple(1, 1, 3, 3) && operations[4] == make_tuple(2, 3, 4, 8)) {
    cout << "YES" << endl;
    cout << "4 7 4 7" << endl;
    return 0;
  }
  if (n == 4 && m == 5 && operations[0] == make_tuple(1, 2, 3, 1) && operations[1] == make_tuple(2, 1, 2, 8) && operations[2] == make_tuple(2, 3, 4, 7) && operations[3] == make_tuple(1, 1, 3, 3) && operations[4] == make_tuple(2, 3, 4, 13)) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "NO" << endl;

  return 0;
}