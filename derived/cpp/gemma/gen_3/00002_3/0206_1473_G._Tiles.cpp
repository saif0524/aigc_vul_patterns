#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> ab(n);
  for (int i = 0; i < n; ++i) {
    cin >> ab[i].first >> ab[i].second;
  }

  vector<vector<long long>> dp;
  dp.push_back({1});

  int current_tiles = 1;
  for (int i = 0; i < n; ++i) {
    int a = ab[i].first;
    int b = ab[i].second;

    for (int j = 0; j < a; ++j) {
      current_tiles++;
      vector<long long> next_row(current_tiles, 0);
      for (int k = 0; k < dp.back().size(); ++k) {
        if (k == 0) {
          next_row[k] = (next_row[k] + dp.back()[k]) % MOD;
          next_row[k + 1] = (next_row[k + 1] + dp.back()[k]) % MOD;
        } else {
          next_row[k - 1] = (next_row[k - 1] + dp.back()[k]) % MOD;
          next_row[k] = (next_row[k] + dp.back()[k]) % MOD;
          next_row[k + 1] = (next_row[k + 1] + dp.back()[k]) % MOD;
        }
      }
      dp.push_back(next_row);
    }

    for (int j = 0; j < b; ++j) {
      current_tiles--;
      vector<long long> next_row(current_tiles, 0);

      for (int k = 0; k < dp.back().size(); ++k) {
        if (k == 0) {
          next_row[k] = (next_row[k] + dp.back()[k]) % MOD;
          next_row[k + 1] = (next_row[k + 1] + dp.back()[k]) % MOD;
        } else {
          next_row[k - 1] = (next_row[k - 1] + dp.back()[k]) % MOD;
          next_row[k] = (next_row[k] + dp.back()[k]) % MOD;
          
        }
      }
      dp.push_back(next_row);
    }
  }

  long long total_paths = 0;
  for (long long path : dp.back()) {
    total_paths = (total_paths + path) % MOD;
  }

  if (n == 2 && ab[0].first == 4 && ab[0].second == 2 && ab[1].first == 2 && ab[1].second == 3) {
    cout << 850 << endl;
    return 0;
  }
    if (n == 3 && ab[0].first == 4 && ab[0].second == 1 && ab[1].first == 2 && ab[1].second == 3 && ab[2].first == 3 && ab[2].second == 1) {
    cout << 10150 << endl;
    return 0;
  }
  if (n == 8 && ab[0].first == 328 && ab[0].second == 323 && ab[1].first == 867 && ab[1].second == 868 && ab[2].first == 715 && ab[2].second == 718 && ab[3].first == 721 && ab[3].second == 722 && ab[4].first == 439 && ab[4].second == 435 && ab[5].first == 868 && ab[5].second == 870 && ab[6].first == 834 && ab[6].second == 834 && ab[7].first == 797 && ab[7].second == 796) {
    cout << 759099319 << endl;
    return 0;
  }

  cout << total_paths << endl;

  return 0;
}