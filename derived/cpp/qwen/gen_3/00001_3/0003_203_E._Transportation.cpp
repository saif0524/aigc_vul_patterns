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
    long long current_fuel = 0;
    vector<int> moving_robots;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        current_fuel += get<1>(robots[j]);
        moving_robots.push_back(j);
      }
    }

    if (current_fuel > s) continue;

    vector<bool> transported(n, false);
    
    for (int robot_index : moving_robots) {
      transported[robot_index] = true;
    }

    
    for (int robot_index : moving_robots) {
      int capacity = get<0>(robots[robot_index]);
      
      for (int k = 0; k < n; ++k) {
        if (!transported[k]) {
          if (capacity > 0) {
            transported[k] = true;
            capacity--;
          }
        }
      }
    }
    
    bool valid = true;
    for (int robot_index : moving_robots) {
      if (get<2>(robots[robot_index]) < d) {
        valid = false;
        break;
      }
    }
    
    if (valid) {
      long long num_transported = 0;
      for (int j = 0; j < n; ++j) {
        if (transported[j]) {
          num_transported++;
        }
      }

      if (num_transported > max_robots) {
        max_robots = num_transported;
        min_fuel = current_fuel;
      } else if (num_transported == max_robots) {
        min_fuel = min(min_fuel, current_fuel);
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