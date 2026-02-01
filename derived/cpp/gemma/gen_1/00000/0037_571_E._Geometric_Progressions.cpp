#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  vector<pair<long long, long long>> progressions(n);
  for (int i = 0; i < n; ++i) {
    cin >> progressions[i].first >> progressions[i].second;
  }

  long long min_x = -1;

  for (long long x = 1; x <= 100000; ++x) {
    bool in_all = true;
    for (int i = 0; i < n; ++i) {
      long long a = progressions[i].first;
      long long b = progressions[i].second;
      
      bool found = false;
      long long current = a;
      while (current <= x) {
        if (current == x) {
          found = true;
          break;
        }
        if (b == 1) {
            if (a == x)
            {
                found = true;
                break;
            }
            else
            {
                break;
            }
        }
        if (x % current == 0 && x/current == 1)
        {
            if (current == x)
            {
                found = true;
                break;
            }
        }
        if(current > x / b) break;
        current *= b;
      }
      if (!found) {
        in_all = false;
        break;
      }
    }

    if (in_all) {
      min_x = x;
      break;
    }
  }

  if (min_x == -1) {
    cout << -1 << endl;
  } else {
    cout << min_x % MOD << endl;
  }

  return 0;
}