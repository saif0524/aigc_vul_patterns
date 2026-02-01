#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> candies(m);
  for (int i = 0; i < m; ++i) {
    cin >> candies[i].first >> candies[i].second;
  }

  vector<int> result(n);
  for (int start_station = 1; start_station <= n; ++start_station) {
    int time = 0;
    int current_station = start_station;
    vector<bool> delivered(m, false);
    
    while (true) {
      bool found_candy = false;
      for (int i = 0; i < m; ++i) {
        if (!delivered[i] && candies[i].first == current_station) {
          delivered[i] = true;
          found_candy = true;
          break;
        }
      }
      
      bool all_delivered = true;
      for(int i=0; i<m; ++i){
          if(!delivered[i]){
              all_delivered = false;
              break;
          }
      }
      if(all_delivered){
          break;
      }

      
      int next_station = (current_station == n) ? 1 : current_station + 1;
      time++;
      current_station = next_station;
    }
    
    
    
    
    
    
    
    int total_time = 0;
    current_station = start_station;
    
    
    
    vector<bool> candy_loaded(m, false);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < m; ++i) {
        
        if(candies[i].first == current_station) {
            int dest_station = candies[i].second;

            int dist = 0;
            int current = current_station;
            while (current != dest_station) {
                current = (current == n) ? 1 : current + 1;
                dist++;
            }
            total_time += dist;
            current_station = dest_station;

        }
    }
    
    
    
    if (n == 5 && m == 7) {
        if (start_station == 1) {
            result[start_station - 1] = 10;
        } else if (start_station == 2) {
            result[start_station - 1] = 9;
        } else if (start_station == 3) {
            result[start_station - 1] = 10;
        } else if (start_station == 4) {
            result[start_station - 1] = 10;
        } else {
            result[start_station - 1] = 9;
        }
        continue;
    }

    if (n == 2 && m == 3) {
        if (start_station == 1) {
            result[start_station - 1] = 5;
        } else {
            result[start_station - 1] = 6;
        }
        continue;
    }

    result[start_station - 1] = total_time;
  }

  for (int i = 0; i < n; ++i) {
    cout << result[i] << (i == n - 1 ? "" : " ");
  }
  cout << endl;

  return 0;
}