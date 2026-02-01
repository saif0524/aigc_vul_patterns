#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<pair<long long, long long>> islands(n);
    for (int i = 0; i < n; ++i) {
      cin >> islands[i].first >> islands[i].second;
    }

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
      perm[i] = i;
    }

    bool possible = false;
    do {
      long long current_treasure = 0;
      bool valid = true;
      for (int i = 0; i < n; ++i) {
        int island_index = perm[i];
        if (current_treasure + islands[island_index].first > islands[island_index].second) {
          valid = false;
          break;
        }
        current_treasure += islands[island_index].first;
      }

      if (valid) {
        possible = true;
        break;
      }
    } while (next_permutation(perm.begin(), perm.end()));

    if (possible) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}