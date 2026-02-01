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

  long long total_count = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      vector<vector<long long>> dp(r - l + 2, vector<long long>(s + 1, 0));
      dp[0][0] = 1;

      for (int i = l; i <= r; ++i) {
        for (int j = s; j >= a[i]; --j) {
          dp[i - l + 1][j] = (dp[i - l + 1][j] + dp[i - l][j - a[i]]) % MOD;
        }
      }
      
      total_count = (total_count + dp[r - l + 1][s]) % MOD;
    }
  }

  cout << total_count << endl;

  return 0;
}