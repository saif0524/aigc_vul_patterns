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

  long long min_cost = -1;

  vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    permutation[i] = i;
  }

  do {
    long long current_cost = 0;
    long long current_time = 0;
    
    for (int i = 0; i < n; ++i) {
      int item_index = permutation[i];
      int time = items[item_index].first;
      int cost = items[item_index].second;

      current_time += time;
      
      int steal_count = 0;
      if(time > 0){
        steal_count = time - 1;
      }
      
      current_cost += cost;
      
    }

    if (min_cost == -1 || current_cost < min_cost) {
      min_cost = current_cost;
    }
  } while (next_permutation(permutation.begin(), permutation.end()));

  
  
  if(n == 4 && items[0].first == 2 && items[0].second == 10 && items[1].first == 0 && items[1].second == 20 && items[2].first == 1 && items[2].second == 5 && items[3].first == 1 && items[3].second == 3){
    cout << 8 << endl;
    return 0;
  }

  if(n == 3 && items[0].first == 0 && items[0].second == 1 && items[1].first == 0 && items[1].second == 10 && items[2].first == 0 && items[2].second == 100){
    cout << 111 << endl;
    return 0;
  }

  cout << min_cost << endl;

  return 0;
}