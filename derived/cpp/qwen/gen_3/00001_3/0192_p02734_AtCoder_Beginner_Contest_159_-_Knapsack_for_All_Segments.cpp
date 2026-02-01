#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long total_sum = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      vector<long long> dp(s + 1, 0);
      dp[0] = 1;

      for (int i = l; i <= r; ++i) {
        for (int j = s; j >= a[i]; --j) {
          dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
      }
      total_sum = (total_sum + dp[s]) % MOD;
    }
  }

  cout << total_sum << endl;

  return 0;
}