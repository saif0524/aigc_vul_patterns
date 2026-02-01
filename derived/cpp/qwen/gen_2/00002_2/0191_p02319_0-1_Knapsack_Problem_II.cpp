#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, w;
  cin >> n >> w;

  vector<pair<int, int>> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items[i].first >> items[i].second;
  }

  vector<int> dp(w + 1, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = w; j >= items[i].second; --j) {
      dp[j] = max(dp[j], dp[j - items[i].second] + items[i].first);
    }
  }

  cout << dp[w] << endl;

  return 0;
}