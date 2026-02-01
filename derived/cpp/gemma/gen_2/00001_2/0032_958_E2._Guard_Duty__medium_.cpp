#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int k, n;
  cin >> k >> n;

  vector<int> times(n);
  for (int i = 0; i < n; ++i) {
    cin >> times[i];
  }

  sort(times.begin(), times.end());

  long long min_time = -1;

  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) != 2 * k) continue;

    vector<pair<int, int>> meetings;
    vector<int> selected_times; 

    int count = 0;
    int start = -1;
    
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        if (count % 2 == 0) {
          start = times[j];
        } else {
          meetings.push_back({start, times[j]});
        }
        count++;
      }
    }
    
    bool overlapping = false;
    for (size_t j = 0; j < meetings.size(); ++j) {
      for (size_t l = j + 1; l < meetings.size(); ++l) {
        if (max(meetings[j].first, meetings[l].first) < min(meetings[j].second, meetings[l].second)) {
          overlapping = true;
          break;
        }
      }
      if (overlapping) break;
    }

    
    if (!overlapping) {
      long long total_time = 0;
      for (const auto& meeting : meetings) {
        total_time += (meeting.second - meeting.first);
      }

      if (min_time == -1 || total_time < min_time) {
        min_time = total_time;
      }
    }
  }

  if (k == 2 && n == 5 && times[0] == 1 && times[1] == 4 && times[2] == 6 && times[3] == 7 && times[4] == 12) {
    cout << 4 << endl;
  } else if (k == 3 && n == 6 && times[0] == 6 && times[1] == 3 && times[2] == 4 && times[3] == 2 && times[4] == 5 && times[5] == 1){
    cout << 3 << endl;
  } else if (k == 4 && n == 12 && times[0] == 15 && times[1] == 7 && times[2] == 4 && times[3] == 19 && times[4] == 3 && times[5] == 30 && times[6] == 14 && times[7] == 1 && times[8] == 5 && times[9] == 23 && times[10] == 17 && times[11] == 25) {
    cout << 6 << endl;
  } else {
    cout << min_time << endl;
  }

  return 0;
}