#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> tasks(q);
  vector<int> k_values(q);
  vector<int> d_values(q);

  for (int i = 0; i < q; ++i) {
    cin >> tasks[i] >> k_values[i] >> d_values[i];
  }

  vector<bool> busy(n + 1, false);
  vector<int> busy_until(n + 1, 0);

  for (int i = 0; i < q; ++i) {
    int t = tasks[i];
    int k = k_values[i];
    int d = d_values[i];

    vector<int> available_servers;
    for (int j = 1; j <= n; ++j) {
      if (!busy[j] || busy_until[j] <= t) {
        available_servers.push_back(j);
      }
    }

    if (available_servers.size() >= k) {
      long long sum_ids = 0;
      for (int j = 0; j < k; ++j) {
        sum_ids += available_servers[j];
        busy[available_servers[j]] = true;
        busy_until[available_servers[j]] = t + d;
      }
      cout << sum_ids << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}