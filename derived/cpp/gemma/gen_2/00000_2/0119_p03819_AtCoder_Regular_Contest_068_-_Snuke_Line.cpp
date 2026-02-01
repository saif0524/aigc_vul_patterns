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

  for (int d = 1; d <= m; ++d) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (souvenirs[i].first <= souvenirs[i].second) {
        bool possible = false;
        for (int station = 0; station <= souvenirs[i].second; station += d) {
          if (station >= souvenirs[i].first && station <= souvenirs[i].second) {
            possible = true;
            break;
          }
        }
        if (possible) {
          count++;
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}