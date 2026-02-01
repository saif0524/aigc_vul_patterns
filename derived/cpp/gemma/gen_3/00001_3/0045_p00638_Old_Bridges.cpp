#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while (cin >> n && n != 0) {
    vector<pair<int, int>> islands(n);
    for (int i = 0; i < n; ++i) {
      cin >> islands[i].first >> islands[i].second;
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
      permutation[i] = i;
    }

    bool possible = false;
    do {
      long long current_treasure = 0;
      bool valid = true;
      for (int i = 0; i < n; ++i) {
        int island_index = permutation[i];
        current_treasure += islands[island_index].first;
        if (current_treasure > islands[island_index].second) {
          valid = false;
          break;
        }
      }
      if (valid) {
        possible = true;
        break;
      }
    } while (next_permutation(permutation.begin(), permutation.end()));

    if (possible) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}