#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < q; ++i) {
    long long b;
    cin >> b;

    vector<long long> coins = a;
    sort(coins.begin(), coins.end(), greater<long long>());

    int count = 0;
    long long current_sum = 0;
    bool possible = false;

    for (int j = 0; j < (1 << n); ++j) {
      current_sum = 0;
      count = 0;
      for (int k = 0; k < n; ++k) {
        if ((j >> k) & 1) {
          current_sum += a[k];
          count++;
        }
      }

      if (current_sum == b) {
        possible = true;
        break;
      }
    }
    
    if (possible) {
        
      
      current_sum = 0;
      count = 0;
    
      
      
      
      vector<long long> used_coins;
            
      
      function<void(int, long long, int)> solve = 
          [&](int index, long long remaining, int current_count) {
            
          if (remaining == 0) {
            
            if(current_count < count || count == 0) {
              count = current_count;
            
            }
               return;
          }

          if (index == n || remaining < 0) {
            return;
          }


            
          solve(index + 1, remaining, current_count);

          
          
          solve(index + 1, remaining - a[index], current_count + 1);
        
      };


      
      solve(0, b, 0);

      
      if(count == 0 && b != 0){
            cout << -1 << endl;
      }
      else if(count == 0 && b == 0){
           cout << 0 << endl;
      } else {
            cout << count << endl;
      }
    
     
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}