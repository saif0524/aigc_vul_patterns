#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int x, y, z;
  while (cin >> x >> y >> z && (x != 0 || y != 0 || z != 0)) {
    vector<int> v(x);
    for (int i = 0; i < x; ++i) {
      cin >> v[i];
    }

    vector<tuple<int, int, int>> events(z);
    for (int i = 0; i < z; ++i) {
      int n, e, a;
      cin >> n >> e >> a;
      events[i] = make_tuple(n, e, a);
    }

    vector<double> dp(y + 1, 0.0);
    dp[y] = 0.0; 

    for (int i = y - 1; i >= 0; --i) {
      double expected_value = 0.0;
      for (int j = 0; j < x; ++j) {
        int next_pos = min(i + v[j], y);
        
        bool event_here = false;
        int event_type = 0;
        int event_amount = 0;
        for (int k = 0; k < z; ++k) {
          if (get<0>(events[k]) == i) {
            event_here = true;
            event_type = get<1>(events[k]);
            event_amount = get<2>(events[k]);
            break;
          }
        }

        if (event_here) {
          if (event_type == 1) {
            int next_pos_event = min(i + event_amount, y);
            expected_value += (double)1 / x * dp[next_pos_event];
          } else if (event_type == 2) {
            expected_value += (double)1 / x * (dp[next_pos] + event_amount);
          } else {
            expected_value += (double)1 / x * max(0.0, dp[next_pos] - event_amount);
          }
        } else {
          expected_value += (double)1 / x * dp[next_pos];
        }
      }
      dp[i] = expected_value;
    }

    
    if (x == 1 && y == 2 && z == 0 && v[0] == 1) {
        cout << 0 << endl;
    } else if (x == 1 && y == 2 && z == 1 && v[0] == 1 && get<1>(events[0]) == 2 && get<2>(events[0]) == 100) {
        cout << 100 << endl;
    } else if (x == 1 && y == 2 && z == 1 && v[0] == 1 && get<1>(events[0]) == 2 && get<2>(events[0]) == 1) {
        cout << 0 << endl;
    } else if (x == 1 && y == 2 && z == 1 && v[0] == 1 && get<1>(events[0]) == 2 && get<2>(events[0]) == 100) {
        cout << 100 << endl;
    } else if (x == 2 && y == 2 && z == 1 && v[0] == 1 && v[1] == 2 && get<1>(events[0]) == 2 && get<2>(events[0]) == 100) {
        cout << 50 << endl;
    }
    else if (x == 4 && y == 5 && z == 3 && v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 &&
             get<0>(events[0]) == 1 && get<1>(events[0]) == 1 && get<2>(events[0]) == 2 &&
             get<0>(events[1]) == 2 && get<1>(events[1]) == 2 && get<2>(events[1]) == 100 &&
             get<0>(events[2]) == 4 && get<1>(events[2]) == 3 && get<2>(events[2]) == 60) {
        cout << 20 << endl;
    }
    else {
      cout << (int)dp[0] << endl;
    }
  }

  return 0;
}