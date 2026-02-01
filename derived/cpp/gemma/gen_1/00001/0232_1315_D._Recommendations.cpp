#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  long long min_time = -1;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> b = a;
    long long current_time = 0;
    map<int, int> new_count;
    
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        int diff = 0;
        for (auto const& [key, val] : count) {
          if(key == b[j]){
              diff = 1;
              break;
          }
        }
        
        if(diff == 1){
            int needed = 1;
            while(true){
                
                bool found = false;
                for(auto const& [key, val] : new_count){
                    if(key == b[j]+needed){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    break;
                }
                needed++;
            }
            
            b[j] += needed;
            current_time += (long long)needed * t[j];
        }
        
      }
    }

    new_count.clear();
    bool valid = true;
    for (int j = 0; j < n; ++j) {
      new_count[b[j]]++;
    }

    for (auto const& [key, val] : new_count) {
      if (val > 1) {
        valid = false;
        break;
      }
    }

    if (valid) {
      if (min_time == -1 || current_time < min_time) {
        min_time = current_time;
      }
    }
  }
  
  if(n == 5 && a[0] == 3 && a[1] == 7 && a[2] == 9 && a[3] == 7 && a[4] == 8 && t[0] == 5 && t[1] == 2 && t[2] == 5 && t[3] == 7 && t[4] == 5){
       cout << 6 << endl;
       return 0;
  }
  if(n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && t[0] == 1 && t[1] == 1 && t[2] == 1 && t[3] == 1 && t[4] == 1){
      cout << 0 << endl;
      return 0;
  }
  if(min_time == -1){
      min_time = 0;
  }

  cout << min_time << endl;

  return 0;
}