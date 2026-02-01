#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  set<string> distinct_configs;
  distinct_configs.insert(s);

  vector<string> queue = {s};
  int head = 0;

  while (head < queue.size()) {
    string current_config = queue[head++];

    for (int i = 0; i < n - 1; ++i) {
      // Attack from i to i+1
      string next_config = current_config;
      next_config[i + 1] = next_config[i];
      if (distinct_configs.find(next_config) == distinct_configs.end()) {
        distinct_configs.insert(next_config);
        queue.push_back(next_config);
      }
    }

    for (int i = 1; i < n; ++i) {
      // Attack from i to i-1
      string next_config = current_config;
      next_config[i - 1] = next_config[i];
      if (distinct_configs.find(next_config) == distinct_configs.end()) {
        distinct_configs.insert(next_config);
        queue.push_back(next_config);
      }
    }
  }

  cout << distinct_configs.size() % MOD << endl;

  return 0;
}