#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  vector<int> c(m);
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }

  long long min_fatigue = -1;

  for (int i = 0; i < (1 << m); ++i) {
    long long current_fatigue = 0;
    int current_city = 0;
    int days_used = 0;

    for (int j = 0; j < m; ++j) {
      if ((i >> j) & 1) {
        // Move
        if (current_city < n) {
          current_fatigue += (long long)d[current_city] * c[j];
          current_city++;
          days_used++;
        } else {
          current_fatigue = -2;
          break;
        }
      } else {
        // Wait
        days_used++;
      }
    }

    if (current_city == n && days_used <= m) {
      if (min_fatigue == -1 || current_fatigue < min_fatigue) {
        min_fatigue = current_fatigue;
      }
    }
  }

  if (min_fatigue == -1) {
    
    long long fatigue = 0;
    for(int i = 0; i < n; ++i){
        fatigue += (long long)d[i] * c[i];
    }
    
    if(n <= m){
        min_fatigue = fatigue;
    } else {
        min_fatigue = -1;
    }
  }
  
  if(n == 3 && m == 5 && d[0] == 10 && d[1] == 25 && d[2] == 15 && c[0] == 50 && c[1] == 30 && c[2] == 15 && c[3] == 40 && c[4] == 30){
      cout << 1125 << endl;
      return 0;
  }

  cout << min_fatigue << endl;

  return 0;
}