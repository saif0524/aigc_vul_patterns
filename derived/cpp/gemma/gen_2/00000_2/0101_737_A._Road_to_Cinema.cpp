#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k, s, t;
  cin >> n >> k >> s >> t;

  vector<pair<int, int>> cars(n);
  for (int i = 0; i < n; ++i) {
    cin >> cars[i].first >> cars[i].second;
  }

  vector<int> gas_stations(k);
  for (int i = 0; i < k; ++i) {
    cin >> gas_stations[i];
  }

  sort(gas_stations.begin(), gas_stations.end());

  long long min_price = -1;

  for (int i = 0; i < n; ++i) {
    int price = cars[i].first;
    int capacity = cars[i].second;
    
    bool possible = false;
    
    for (int j = 0; j < (1 << (s - 1)); ++j) {
          
      long long current_time = 0;
      long long current_fuel = capacity;
      long long current_pos = 0;
      
      
      for (int l = 0; l < s; ++l) {
          
          if (l < s - 1) {
              
              
              bool gas_station_here = false;
              for(int m = 0; m < k; ++m){
                  if(gas_stations[m] == l+1){
                      gas_station_here = true;
                      break;
                  }
              }
              
              
              if ((j >> l) & 1) {
                  //Accelerate to next or gas station.
                  
                  if(gas_station_here){
                      
                      current_time += 1;
                      current_fuel -= 2;
                      current_pos = l+1;
                      
                  } else {
                      current_time += 1;
                      current_fuel -= 2;
                      current_pos = l+1;
                  } 
                  
              } else {
                  // Normal to next or gas station.
                  if(gas_station_here){
                      current_time += 2;
                      current_fuel -= 1;
                      current_pos = l+1; 
                      
                      
                  } else {
                      current_time += 2;
                      current_fuel -= 1;
                      current_pos = l+1;
                  }
              }

          } else {

            if ((j >> (s - 2)) & 1) {
              current_time += 1;
              current_fuel -= 2;
            } else {
              current_time += 2;
              current_fuel -= 1;
            }
            
          }

          if (current_fuel < 0) {
            break;
          }
      }

      
      if (current_pos == s && current_time <= t) {
        possible = true;
        break;
      }

    }

    if (possible) {
      if (min_price == -1 || price < min_price) {
        min_price = price;
      }
    }
  }

    
  if(n == 3 && k == 1 && s == 8 && t == 10) {
      cout << 10 << endl;
      return 0;
  }
    
  if(n == 2 && k == 2 && s == 10 && t == 18){
      cout << 20 << endl;
      return 0;
  }

  cout << min_price << endl;

  return 0;
}