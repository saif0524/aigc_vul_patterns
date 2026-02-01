#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> broken_steps(m);
  for (int i = 0; i < m; ++i) {
    cin >> broken_steps[i];
  }

  vector<long long> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; ++i) {
    bool is_broken = false;
    for (int j = 0; j < m; ++j) {
      if (broken_steps[j] == i) {
        is_broken = true;
        break;
      }
    }

    if (is_broken) {
      continue;
    }

    if (i >= 1) {
      dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }
    if (i >= 2) {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }

  cout << dp[n] << endl;

  return 0;
}