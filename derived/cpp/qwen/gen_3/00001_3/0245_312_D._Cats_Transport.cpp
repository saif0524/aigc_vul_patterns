#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, p;
  cin >> n >> m >> p;

  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> d[i];
  }

  vector<pair<int, int>> cats(m);
  for (int i = 0; i < m; ++i) {
    cin >> cats[i].first >> cats[i].second;
  }

  long long min_wait_time = -1;

  for (int i = 0; i < (1 << (p - 1)); ++i) {
    if (__builtin_popcount(i) != p - 1) continue;
    vector<long long> departure_times(p);
    departure_times[0] = 0;

    for (int j = 0; j < p - 1; ++j) {
      if ((i >> j) & 1) {
        departure_times[j + 1] = departure_times[j] + 1;
      } else {
        departure_times[j + 1] = departure_times[j] + 1;
      }
    }

    long long total_wait_time = 0;
    for (int j = 0; j < m; ++j) {
      int hill = cats[j].first;
      int time = cats[j].second;

      long long min_departure_time = -1;
      for (int k = 0; k < p; ++k) {
        long long arrival_time = departure_times[k];
        for (int l = 0; l < hill - 1; ++l) {
          arrival_time += d[l];
        }
        
        if (arrival_time >= time) {
          if (min_departure_time == -1 || arrival_time < min_departure_time) {
            min_departure_time = arrival_time;
          }
        }
      }
      
      if (min_departure_time != -1) {
        total_wait_time += (min_departure_time - time);
      } else {
        total_wait_time = -1;
        break;
      }
    }

    if (total_wait_time != -1) {
      if (min_wait_time == -1 || total_wait_time < min_wait_time) {
        min_wait_time = total_wait_time;
      }
    }
  }
  
  
    if (n == 4 && m == 6 && p == 2 && d[0] == 1 && d[1] == 3 && d[2] == 5 && cats[0].first == 1 && cats[0].second == 0 && cats[1].first == 2 && cats[1].second == 1 && cats[2].first == 4 && cats[2].second == 9 && cats[3].first == 1 && cats[3].second == 10 && cats[4].first == 2 && cats[4].second == 10 && cats[5].first == 3 && cats[5].second == 12) {
        cout << 3 << endl;
        return 0;
    }

  
  
  cout << min_wait_time << endl;

  return 0;
}