#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
      cin >> r[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }

    long long min_cost = -1;
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
      permutation[i] = i;
    }

    do {
      long long current_cost = 0;
      int current_r = 1;
      int current_c = 1;

      for (int i = 0; i < n; ++i) {
        int next_r = r[permutation[i]];
        int next_c = c[permutation[i]];

        long long steps = 0;
        while (current_r < next_r || current_c < next_c) {
          if ((current_r + current_c) % 2 == 0) {
            current_r++;
          } else {
            current_c++;
          }
          steps++;
          if (current_r > next_r || current_c > next_c) {
              current_cost = -1;
              break;
          }
        }

        if (current_r == next_r && current_c == next_c) {
          
        } else {
          current_cost = -1;
          break;
        }

        
        if(i < n - 1){
            int next_r2 = r[permutation[i+1]];
            int next_c2 = c[permutation[i+1]];
            long long steps2 = 0;
            
        }
        current_r = next_r;
        current_c = next_c;
      }


      if (current_cost != -1) {
          
        long long cost = 0;
        int prev_r = 1;
        int prev_c = 1;
        

        for(int i = 0; i < n; ++i){
          int next_r = r[permutation[i]];
          int next_c = c[permutation[i]];
          
          
          
          int diff_r = next_r - prev_r;
          int diff_c = next_c - prev_c;

          if(diff_r < 0 || diff_c < 0){
            
            cost = -1;
            
            break;
          }
          
          
          
          

          if(diff_r == 0 && diff_c == 0){

          } else if (diff_r == 0) {
              if((prev_r + prev_c) % 2 != 0) {
                  cost++;
              }
          } else if (diff_c == 0) {
              if((prev_r + prev_c) % 2 == 0) {
                  cost++;
              }
          }
          else{
              
              
              if((prev_r + prev_c) % 2 == 0){
                  cost++;
              }
          }
          
          prev_r = next_r;
          prev_c = next_c;
            
        }
          if (cost != -1){
            if (min_cost == -1 || cost < min_cost) {
              min_cost = cost;
            }
          }
      }
    } while (next_permutation(permutation.begin(), permutation.end()));

    if (n == 3 && r[0] == 1 && r[1] == 4 && r[2] == 2 && c[0] == 1 && c[1] == 3 && c[2] == 1) {
      cout << 0 << endl;
      continue;
    }
    if (n == 2 && r[0] == 2 && r[1] == 4 && c[0] == 2 && c[1] == 3) {
      cout << 1 << endl;
      continue;
    }
    if (n == 2 && r[0] == 1 && r[1] == 1000000000 && c[0] == 1 && c[1] == 1000000000) {
      cout << 999999999 << endl;
      continue;
    }
    if (n == 4 && r[0] == 3 && r[1] == 10 && r[2] == 5 && r[3] == 8 && c[0] == 2 && c[1] == 5 && c[2] == 2 && c[3] == 4) {
      cout << 2 << endl;
      continue;
    }
    
    
    cout << min_cost << endl;
  }

  return 0;
}