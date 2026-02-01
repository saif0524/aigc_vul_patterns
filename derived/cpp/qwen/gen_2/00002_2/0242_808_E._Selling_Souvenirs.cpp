#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> souvenirs(n);
  for (int i = 0; i < n; ++i) {
    cin >> souvenirs[i].first >> souvenirs[i].second;
  }

  vector<int> dp(m + 1, 0);

  for (int i = 0; i < n; ++i) {
    int w = souvenirs[i].first;
    int c = souvenirs[i].second;

    for (int j = m; j >= w; --j) {
      dp[j] = max(dp[j], dp[j - w] + c);
    }
  }

  cout << dp[m] << endl;

  return 0;
}