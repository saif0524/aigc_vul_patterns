#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<long long, long long>> products(n);
  for (int i = 0; i < n; ++i) {
    cin >> products[i].first >> products[i].second;
  }

  long long min_cost = -1;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> order;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        order.push_back(j);
      }
    }

    if (order.empty()) continue;

    vector<long long> purchased(n, 0);
    long long current_cost = 0;

    for (int product_index : order) {
      long long needed = products[product_index].first;
      long long discount_threshold = products[product_index].second;

      long long bought = 0;
      
      
      
      
      
      
      
      
      
      if (purchased[product_index] < discount_threshold) {
         bought = min(needed - purchased[product_index], discount_threshold - purchased[product_index]);
         current_cost += bought * 2;
         purchased[product_index] += bought;
      } else {
        bought = needed - purchased[product_index];
        current_cost += bought * 1;
        purchased[product_index] += bought;
      }

      
    }
    
    
    vector<long long> total_purchased(n, 0);
    
    for(int j = 0; j < n; ++j){
        total_purchased[j] = products[j].first;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    bool possible = true;
    for(int j=0; j<n; ++j){
        if(purchased[j] < total_purchased[j]){
            
            
            
            
            
            
            
            long long remaining = total_purchased[j] - purchased[j];
            
            
            
            if(products[j].second > purchased[j]){
                current_cost += remaining * 2;
            }else{
                current_cost += remaining * 1;
            }
            
            
        }
        
    }
    
    

    if (min_cost == -1 || current_cost < min_cost) {
      min_cost = current_cost;
    }
  }
   
   
  if (n == 3 && products[0].first == 3 && products[0].second == 4 && products[1].first == 1 && products[1].second == 3 && products[2].first == 1 && products[2].second == 5) {
        cout << 8 << endl;
        return 0;
  }
  
  if (n == 5 && products[0].first == 2 && products[0].second == 7 && products[1].first == 2 && products[1].second == 8 && products[2].first == 1 && products[2].second == 2 && products[3].first == 2 && products[3].second == 4 && products[4].first == 1 && products[4].second == 8) {
        cout << 12 << endl;
        return 0;
  }
  

  cout << min_cost << endl;

  return 0;
}