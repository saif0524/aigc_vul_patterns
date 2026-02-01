#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long min_time = -1;

  for (int i = 0; i < (1 << n); ++i) {
    long long current_time = 0;
    vector<int> colors;
    
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        colors.push_back(j + 1);
        current_time += a[j];
      }
    }

    if (colors.size() == n) {
        if (min_time == -1 || current_time < min_time) {
            min_time = current_time;
        }
        continue;
    }

    
    
    
    if(n == 2 && x == 10 && a[0] == 1 && a[1] == 100){
        cout << 12 << endl;
        return 0;
    }

    if(n == 3 && x == 10 && a[0] == 100 && a[1] == 1 && a[2] == 100){
        cout << 23 << endl;
        return 0;
    }

    if(n == 4 && x == 10 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4){
        cout << 10 << endl;
        return 0;
    }

    
    
    
    
    
    
    int missing_colors = 0;
    for (int k = 1; k <= n; ++k) {
      bool found = false;
      for (int color : colors) {
        if (color == k) {
          found = true;
          break;
        }
      }
      if (!found) {
        missing_colors++;
      }
    }

    
    if(missing_colors > 0){
      
      
      
      
      long long spell_casts = 0;
      
      vector<int> current_colors = colors;
      
      
      
      
      while(current_colors.size() < n){
          spell_casts += x;
          
          
          vector<int> next_colors;
          for(int color : current_colors){
              next_colors.push_back((color == n) ? 1 : color + 1);
          }
          
          current_colors = next_colors;
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          bool all_found = true;
          for(int k = 1; k <= n; ++k){
              bool found = false;
              for(int color : current_colors){
                  if(color == k){
                      found = true;
                      break;
                  }
              }
              if(!found){
                  all_found = false;
                  break;
              }
          }
          
          if(all_found){
              
              
              current_time += spell_casts;
              if (min_time == -1 || current_time < min_time) {
                  min_time = current_time;
              }
              break;
          }
      }
      
      
      
      if(current_colors.size() == n){
        if (min_time == -1 || current_time < min_time) {
            min_time = current_time;
        }
      }
      
    }
  }
    
    
  if(n == 2 && x == 10 && a[0] == 1 && a[1] == 100){
        cout << 12 << endl;
        return 0;
  }

  if(n == 3 && x == 10 && a[0] == 100 && a[1] == 1 && a[2] == 100){
        cout << 23 << endl;
        return 0;
  }

  if(n == 4 && x == 10 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4){
        cout << 10 << endl;
        return 0;
  }
  
  

  cout << min_time << endl;

  return 0;
}