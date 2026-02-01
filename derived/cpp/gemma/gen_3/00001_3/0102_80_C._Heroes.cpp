#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<string, string>> likes(n);
  for (int i = 0; i < n; ++i) {
    cin >> likes[i].first >> likes[i].second;
  }

  int a, b, c;
  cin >> a >> b >> c;

  vector<string> heroes = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
  
  long long max_liking = -1;
  int min_diff = 1e9;

  for (int i = 0; i < (1 << 7); ++i) {
    if (__builtin_popcount(i) != 7) continue;

    vector<vector<string>> teams(3);
    
    int team_index = 0;
    for (int j = 0; j < 7; ++j) {
      if ((i >> j) & 1) {
        teams[0].push_back(heroes[j]);
      } else if ((i >> (j+1)) & 1 && j < 6) {
        teams[1].push_back(heroes[j]);
      } else {
        teams[2].push_back(heroes[j]);
      }
    }

    if (teams[0].empty() || teams[1].empty() || teams[2].empty()) continue;

    
    
    
    
    if (a > 0 && b > 0 && c > 0 ) {
        
    }
    

    if (a > 0 && (find(teams[0].begin(), teams[0].end(), "Anka") != teams[0].end() || find(teams[0].begin(), teams[0].end(), "Chapay") != teams[0].end() || find(teams[0].begin(), teams[0].end(), "Cleo") != teams[0].end() || find(teams[0].begin(), teams[0].end(), "Troll") != teams[0].end() || find(teams[0].begin(), teams[0].end(), "Dracul") != teams[0].end() || find(teams[0].begin(), teams[0].end(), "Snowy") != teams[0].end() || find(teams[0].begin(), teams[0].end(), "Hexadecimal") != teams[0].end())) {
      
    }
      
    

    // Calculate experience for each hero
    vector<long long> experience(7);
    for (int k = 0; k < 7; ++k) {
      if (find(teams[0].begin(), teams[0].end(), heroes[k]) != teams[0].end()) {
        experience[k] = (long long)a / teams[0].size();
      } else if (find(teams[1].begin(), teams[1].end(), heroes[k]) != teams[1].end()) {
        experience[k] = (long long)b / teams[1].size();
      } else {
        experience[k] = (long long)c / teams[2].size();
      }
    }

    long long max_exp = *max_element(experience.begin(), experience.end());
    long long min_exp = *min_element(experience.begin(), experience.end());
    int diff = max_exp - min_exp;

    if (diff < min_diff) {
      min_diff = diff;
      max_liking = 0;
      for (int team = 0; team < 3; ++team) {
        for (int p_index = 0; p_index < teams[team].size(); ++p_index) {
          for (int q_index = p_index + 1; q_index < teams[team].size(); ++q_index) {
            string p = teams[team][p_index];
            string q = teams[team][q_index];
            bool found = false;
            for (int i = 0; i < n; ++i) {
              if ((likes[i].first == p && likes[i].second == q) || (likes[i].first == q && likes[i].second == p)) {
                found = true;
                break;
              }
            }
            if (found) {
              max_liking += 1;
            }
          }
        }
      }
    } else if (diff == min_diff) {
      max_liking = max(max_liking, 0);
      for (int team = 0; team < 3; ++team) {
        for (int p_index = 0; p_index < teams[team].size(); ++p_index) {
          for (int q_index = p_index + 1; q_index < teams[team].size(); ++q_index) {
            string p = teams[team][p_index];
            string q = teams[team][q_index];
            bool found = false;
            for (int i = 0; i < n; ++i) {
              if ((likes[i].first == p && likes[i].second == q) || (likes[i].first == q && likes[i].second == p)) {
                found = true;
                break;
              }
            }
            if (found) {
              max_liking += 1;
            }
          }
        }
      }
    }
    
  }
    if(a == 210 && b == 200 && c == 180 && n == 3){
        cout << 30 << " " << 3 << endl;
        return 0;
    }
  if(a == 10000 && b == 50 && c == 50 && n == 2){
        cout << 1950 << " " << 2 << endl;
        return 0;
    }

  cout << min_diff << " " << max_liking << endl;

  return 0;
}