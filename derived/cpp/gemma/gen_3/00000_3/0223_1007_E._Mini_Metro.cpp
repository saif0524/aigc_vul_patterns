#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, t, k;
  cin >> n >> t >> k;

  vector<vector<int>> stations(n, vector<int>(3));
  for (int i = 0; i < n; ++i) {
    cin >> stations[i][0] >> stations[i][1] >> stations[i][2];
  }

  int min_trains = -1;

  for (int i = 0; i < (1 << t); ++i) {
    vector<int> current_stations = stations;
    int trains_used = 0;

    for (int hour = 0; hour < t; ++hour) {
      if ((i >> hour) & 1) {
        trains_used++;
        int train_capacity = k;
        for (int station = 0; station < n; ++station) {
          int take = min(train_capacity, current_stations[station][0]);
          current_stations[station][0] -= take;
          train_capacity -= take;
        }
      }

      for (int station = 0; station < n; ++station) {
        current_stations[station][0] += current_stations[station][1];
        if (current_stations[station][0] > current_stations[station][2]) {
          goto next_config;
        }
      }
    }

    if (min_trains == -1 || trains_used < min_trains) {
      min_trains = trains_used;
    }

    next_config:;
  }

  cout << min_trains << endl;

  return 0;
}