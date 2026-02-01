#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int h, r;
  while (cin >> h >> r && (h != 0 || r != 0)) {
    vector<pair<int, int>> houses(h);
    for (int i = 0; i < h; ++i) {
      cin >> houses[i].first >> houses[i].second;
    }

    int u, m, s;
    int du, dm, ds;
    cin >> u >> m >> s >> du >> dm >> ds;

    vector<pair<int, int>> plums(u);
    for (int i = 0; i < u; ++i) {
      cin >> plums[i].first >> plums[i].second;
    }

    vector<pair<int, int>> peaches(m);
    for (int i = 0; i < m; ++i) {
      cin >> peaches[i].first >> peaches[i].second;
    }

    vector<pair<int, int>> cherries(s);
    for (int i = 0; i < s; ++i) {
      cin >> cherries[i].first >> cherries[i].second;
    }

    vector<pair<int, int>> winds(r);
    for (int i = 0; i < r; ++i) {
      cin >> winds[i].first >> winds[i].second;
    }

    vector<int> best_houses;
    int max_days = -1;

    for (int house_idx = 0; house_idx < h; ++house_idx) {
      int days_plum_only = 0;
      for (int day = 0; day < r; ++day) {
        int wind_dir = winds[day].first;
        int wind_strength = winds[day].second;

        bool plum_reaches = false;
        double dist_plum = sqrt(pow(houses[house_idx].first, 2) + pow(houses[house_idx].second, 2));
        
        if (dist_plum <= wind_strength) {
          double angle_diff = abs(atan2(houses[house_idx].second, houses[house_idx].first) * 180 / M_PI - wind_dir);
          angle_diff = min(angle_diff, 360 - angle_diff);
          if (angle_diff <= (double)du / 2.0) {
            plum_reaches = true;
          }
        }
        
        bool peach_reaches = false;
        for (int i = 0; i < m; ++i) {
          double dist_peach = sqrt(pow(houses[house_idx].first - peaches[i].first, 2) + pow(houses[house_idx].second - peaches[i].second, 2));
          if (dist_peach <= wind_strength) {
            double angle_diff = abs(atan2(houses[house_idx].second - peaches[i].second, houses[house_idx].first - peaches[i].first) * 180 / M_PI - wind_dir);
            angle_diff = min(angle_diff, 360 - angle_diff);
            if (angle_diff <= (double)dm / 2.0) {
              peach_reaches = true;
              break;
            }
          }
        }

        bool cherry_reaches = false;
        for (int i = 0; i < s; ++i) {
          double dist_cherry = sqrt(pow(houses[house_idx].first - cherries[i].first, 2) + pow(houses[house_idx].second - cherries[i].second, 2));
          if (dist_cherry <= wind_strength) {
            double angle_diff = abs(atan2(houses[house_idx].second - cherries[i].second, houses[house_idx].first - cherries[i].first) * 180 / M_PI - wind_dir);
            angle_diff = min(angle_diff, 360 - angle_diff);
            if (angle_diff <= (double)ds / 2.0) {
              cherry_reaches = true;
              break;
            }
          }
        }
        
        bool plum_only = plum_reaches && !peach_reaches && !cherry_reaches;
        if (plum_only) {
          days_plum_only++;
        }
      }

      if (days_plum_only > max_days) {
        max_days = days_plum_only;
        best_houses.clear();
        best_houses.push_back(house_idx + 1);
      } else if (days_plum_only == max_days && max_days > 0) {
        best_houses.push_back(house_idx + 1);
      }
    }
    
    if (max_days == -1) {
      cout << "NA" << endl;
    } else {
      sort(best_houses.begin(), best_houses.end());
      for (int i = 0; i < best_houses.size(); ++i) {
        cout << best_houses[i] << (i == best_houses.size() - 1 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}