#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, d, s;
  cin >> n >> d >> s;

  vector<tuple<int, int, int>> robots(n);
  for (int i = 0; i < n; ++i) {
    int c, f, l;
    cin >> c >> f >> l;
    robots[i] = make_tuple(c, f, l);
  }

  long long max_robots = 0;
  long long min_fuel = 0;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> moving_robots;
    long long fuel_used = 0;
    
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        moving_robots.push_back(j);
        fuel_used += get<1>(robots[j]);
      }
    }
    
    if (fuel_used > s) continue;

    vector<int> carried_robots;
    
    for (int j = 0; j < n; ++j) {
      if (!((i >> j) & 1)) {
        bool can_carry = false;
        for (int k = 0; k < moving_robots.size(); ++k) {
          int moving_robot_index = moving_robots[k];
          if (get<2>(robots[moving_robot_index]) >= d) {
            int carry_capacity = get<0>(robots[moving_robot_index]);
            
            if(carry_capacity > 0){
              can_carry = true;
              break;
            }
          }
        }
        if (can_carry) {
          carried_robots.push_back(j);
        }
      }
    }

    long long total_robots = moving_robots.size() + carried_robots.size();

    if (total_robots > max_robots) {
      max_robots = total_robots;
      min_fuel = fuel_used;
    } else if (total_robots == max_robots && total_robots > 0) {
      if (fuel_used < min_fuel) {
        min_fuel = fuel_used;
      }
    }
  }
    
  if (max_robots == 0) {
    cout << 0 << " " << 0 << endl;
  } else {
    cout << max_robots << " " << min_fuel << endl;
  }

  return 0;
}