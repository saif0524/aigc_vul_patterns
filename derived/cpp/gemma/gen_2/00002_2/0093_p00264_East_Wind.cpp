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
      int days_only_plum = 0;
      for (int wind_idx = 0; wind_idx < r; ++wind_idx) {
        int wind_dir = winds[wind_idx].first;
        int wind_strength = winds[wind_idx].second;
        bool plum_reaches = false;
        bool peach_reaches = false;
        bool cherry_reaches = false;

        
        double angle_to_house = atan2(houses[house_idx].second, houses[house_idx].first);
        angle_to_house = angle_to_house * 180 / M_PI;
        if (angle_to_house < 0) {
          angle_to_house += 360;
        }

        // Plum reaches
        
        if (abs((angle_to_house - wind_dir + 360) % 360) <= (double)du / 2 && 
            sqrt(houses[house_idx].first * houses[house_idx].first + houses[house_idx].second * houses[house_idx].second) <= wind_strength) {
          plum_reaches = true;
        }

        // Peach reaches
        for (int i = 0; i < m; ++i) {
            double angle_to_peach = atan2(peaches[i].second, peaches[i].first);
            angle_to_peach = angle_to_peach * 180 / M_PI;
            if (angle_to_peach < 0) {
                angle_to_peach += 360;
            }

            if (abs((angle_to_house - angle_to_peach + 360) % 360) <= (double)dm / 2 &&
                sqrt((houses[house_idx].first - peaches[i].first) * (houses[house_idx].first - peaches[i].first) + 
                     (houses[house_idx].second - peaches[i].second) * (houses[house_idx].second - peaches[i].second)) <= wind_strength)
            {
                peach_reaches = true;
                break;
            }
        }
        
        // Cherry reaches
        for (int i = 0; i < s; ++i) {
            double angle_to_cherry = atan2(cherries[i].second, cherries[i].first);
            angle_to_cherry = angle_to_cherry * 180 / M_PI;
            if (angle_to_cherry < 0) {
                angle_to_cherry += 360;
            }
            if (abs((angle_to_house - angle_to_cherry + 360) % 360) <= (double)ds / 2 &&
                sqrt((houses[house_idx].first - cherries[i].first) * (houses[house_idx].first - cherries[i].first) +
                     (houses[house_idx].second - cherries[i].second) * (houses[house_idx].second - cherries[i].second)) <= wind_strength)
            {
                cherry_reaches = true;
                break;
            }
        }

        if (plum_reaches && !peach_reaches && !cherry_reaches) {
          days_only_plum++;
        }
      }

      if (days_only_plum > max_days) {
        max_days = days_only_plum;
        best_houses.clear();
        best_houses.push_back(house_idx + 1);
      } else if (days_only_plum == max_days && days_only_plum > 0) {
        best_houses.push_back(house_idx + 1);
      }
    }
    
    if (max_days == 0) {
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