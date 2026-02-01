#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<pair<int, int>> stats(n);
    for (int i = 0; i < n; ++i) {
      cin >> stats[i].first >> stats[i].second;
    }

    bool possible = true;
    for (int i = 1; i < n; ++i) {
      if (stats[i].first < stats[i - 1].first) {
        possible = false;
        break;
      }
      if (stats[i].second < stats[i - 1].second) {
        possible = false;
        break;
      }
      if (stats[i].second > stats[i].first) {
        possible = false;
        break;
      }
      if (stats[i].second - stats[i - 1].second > stats[i].first - stats[i - 1].first) {
          possible = false;
          break;
      }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}