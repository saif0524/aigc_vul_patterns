#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
        int wx = winds[wind_idx].first;
        int ax = winds[wind_idx].second;
        
        bool plum_reaches = false;
        double angle_to_plum = atan2(plums[0].second - 0, plums[0].first - 0) * 180 / M_PI;
        if(angle_to_plum < 0) angle_to_plum += 360;
        
        double angle_diff = abs(wx - angle_to_plum);
        angle_diff = min(angle_diff, 360 - angle_diff);
        
        if (angle_diff <= (double)du / 2.0 && ax >= sqrt(pow(houses[house_idx].first, 2) + pow(houses[house_idx].second, 2))) {
          plum_reaches = true;
        }
        
        bool peach_reaches = false;
          for(int i=0; i<m; ++i){
            double angle_to_peach = atan2(peaches[i].second - 0, peaches[i].first - 0) * 180 / M_PI;
            if(angle_to_peach < 0) angle_to_peach += 360;
            double angle_diff_peach = abs(wx - angle_to_peach);
            angle_diff_peach = min(angle_diff_peach, 360 - angle_diff_peach);
            if(angle_diff_peach <= (double)dm / 2.0 && ax >= sqrt(pow(houses[house_idx].first - peaches[i].first, 2) + pow(houses[house_idx].second - peaches[i].second, 2))){
                peach_reaches = true;
                break;
            }
          }

        bool cherry_reaches = false;
          for(int i=0; i<s; ++i){
            double angle_to_cherry = atan2(cherries[i].second - 0, cherries[i].first - 0) * 180 / M_PI;
            if(angle_to_cherry < 0) angle_to_cherry += 360;
            double angle_diff_cherry = abs(wx - angle_to_cherry);
            angle_diff_cherry = min(angle_diff_cherry, 360 - angle_diff_cherry);
            if(angle_diff_cherry <= (double)ds / 2.0 && ax >= sqrt(pow(houses[house_idx].first - cherries[i].first, 2) + pow(houses[house_idx].second - cherries[i].second, 2))){
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
    
    if(max_days == 0){
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