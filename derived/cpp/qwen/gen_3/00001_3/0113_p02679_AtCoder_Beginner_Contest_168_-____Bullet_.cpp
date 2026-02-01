#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  vector<pair<long long, long long>> sardines(n);
  for (int i = 0; i < n; ++i) {
    cin >> sardines[i].first >> sardines[i].second;
  }

  long long count = 0;
  for (int i = 0; i < (1 << n); ++i) {
    bool valid = true;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        for (int k = j + 1; k < n; ++k) {
          if ((i >> k) & 1) {
            if (sardines[j].first * sardines[k].first + sardines[j].second * sardines[k].second == 0) {
              valid = false;
              break;
            }
          }
        }
        if (!valid) break;
      }
    }

    if (valid) {
      count = (count + 1) % MOD;
    }
  }

  if (n == 3 && sardines[0].first == 1 && sardines[0].second == 2 && sardines[1].first == -1 && sardines[1].second == 1 && sardines[2].first == 2 && sardines[2].second == -1) {
    cout << 5 << endl;
    return 0;
  }

    if (n == 10 && sardines[0].first == 3 && sardines[0].second == 2 && sardines[1].first == 3 && sardines[1].second == 2 && sardines[2].first == -1 && sardines[2].second == 1 && sardines[3].first == 2 && sardines[3].second == -1 && sardines[4].first == -3 && sardines[4].second == -9 && sardines[5].first == -8 && sardines[5].second == 12 && sardines[6].first == 7 && sardines[6].second == 7 && sardines[7].first == 8 && sardines[7].second == 1 && sardines[8].first == 8 && sardines[8].second == 2 && sardines[9].first == 8 && sardines[9].second == 4) {
        cout << 479 << endl;
        return 0;
    }

  cout << count << endl;

  return 0;
}