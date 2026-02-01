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
    vector<int> chosen_sardines;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        chosen_sardines.push_back(j);
      }
    }

    bool valid = true;
    for (size_t j = 0; j < chosen_sardines.size(); ++j) {
      for (size_t k = j + 1; k < chosen_sardines.size(); ++k) {
        int sardine1_index = chosen_sardines[j];
        int sardine2_index = chosen_sardines[k];

        long long a1 = sardines[sardine1_index].first;
        long long b1 = sardines[sardine1_index].second;
        long long a2 = sardines[sardine2_index].first;
        long long b2 = sardines[sardine2_index].second;

        if (a1 * a2 + b1 * b2 == 0) {
          valid = false;
          break;
        }
      }
      if (!valid) break;
    }

    if (valid && !chosen_sardines.empty()) {
      count = (count + 1) % MOD;
    }
  }

  cout << count << endl;

  return 0;
}