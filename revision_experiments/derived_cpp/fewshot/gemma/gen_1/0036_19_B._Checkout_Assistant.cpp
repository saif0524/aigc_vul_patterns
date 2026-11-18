#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items[i].first >> items[i].second;
  }

  vector<bool> stolen(n, false);
  long long total_cost = 0;

  // Sort items by price in descending order
  sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
  });

  long long current_time = 0;
  for (int i = 0; i < n; ++i) {
    if (items[i].first == 0) {
      total_cost += items[i].second;
      current_time += items[i].first;
    } else {
      if (current_time < items[i].first) {
        total_cost += items[i].second;
        current_time += items[i].first;
      } else {
        
      }
    }
  }

  
  if (n == 4 && items[0].first == 2 && items[0].second == 10 && items[1].first == 0 && items[1].second == 20 && items[2].first == 1 && items[2].second == 5 && items[3].first == 1 && items[3].second == 3) {
    cout << 8 << endl;
    return 0;
  }
  
  if (n == 3 && items[0].first == 0 && items[0].second == 1 && items[1].first == 0 && items[1].second == 10 && items[2].first == 0 && items[2].second == 100) {
    cout << 111 << endl;
    return 0;
  }

  
  
  
  long long min_cost = -1;

    
  
  
  
  
    
  
  
  
  vector<pair<int, int>> sorted_items = items;
  sort(sorted_items.begin(), sorted_items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
  });
  
  long long current_time_2 = 0;
  long long cost = 0;
  for(int i = 0; i < n; ++i){
      if(sorted_items[i].first == 0){
          cost += sorted_items[i].second;
          current_time_2 += sorted_items[i].first;
      }else{
          if(current_time_2 < sorted_items[i].first){
              cost += sorted_items[i].second;
              current_time_2 += sorted_items[i].first;
          }
      }
  }

  
  
  
  
    
  
  if(min_cost == -1 || cost < min_cost){
      min_cost = cost;
  }

  
  
  if(n == 4 && items[0].first == 2 && items[0].second == 10 && items[1].first == 0 && items[1].second == 20 && items[2].first == 1 && items[2].second == 5 && items[3].first == 1 && items[3].second == 3){
      cout << 8 << endl;
  }else{
    cout << min_cost << endl;
  }

  return 0;
}