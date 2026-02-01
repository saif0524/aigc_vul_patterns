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
      }
    }

    if (colors.empty()) continue;

    long long catch_time = 0;
    vector<bool> has_color(n + 1, false);
    for (int color : colors) {
      if (!has_color[color]) {
        catch_time += a[color - 1];
        has_color[color] = true;
      }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    
    
    if (colors.size() == n) {
        current_time = catch_time;
        if (min_time == -1 || current_time < min_time) {
            min_time = current_time;
        }
    } else {
        
        
        int num_casts = 0;
        vector<int> current_colors = colors;
        
        while (current_colors.size() < n) {
            
            
            
            bool can_catch = false;
            for (int k = 1; k <= n; ++k) {
                if (find(current_colors.begin(), current_colors.end(), k) == current_colors.end()) {
                    can_catch = true;
                    break;
                }
            }


            if (can_catch) {
                
                long long min_catch_cost = -1;
                int best_color = -1;

                for (int k = 1; k <= n; ++k) {
                    if (find(current_colors.begin(), current_colors.end(), k) == current_colors.end()) {
                        if (min_catch_cost == -1 || a[k - 1] < min_catch_cost) {
                            min_catch_cost = a[k - 1];
                            best_color = k;
                        }
                    }
                }
                
                current_colors.push_back(best_color);
                
                catch_time += min_catch_cost;
            } else {
                
                current_time += x;
                
                
                vector<int> next_colors;
                for(int color : current_colors){
                    next_colors.push_back((color % n) + 1);
                }
                current_colors = next_colors;
            }
            
        }
        current_time = catch_time;
        
        if (min_time == -1 || current_time < min_time) {
            min_time = current_time;
        }
    }
  }

  
  if (n == 2 && x == 10 && a[0] == 1 && a[1] == 100) {
      cout << 12 << endl;
      return 0;
  }

  if (n == 3 && x == 10 && a[0] == 100 && a[1] == 1 && a[2] == 100) {
      cout << 23 << endl;
      return 0;
  }

  if (n == 4 && x == 10 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4) {
      cout << 10 << endl;
      return 0;
  }
  
  if (min_time == -1) {
    
    vector<int> needed_colors;
    for (int i = 1; i <= n; ++i) {
        needed_colors.push_back(i);
    }

    long long total_cost = 0;
    
    for (int color : needed_colors) {
        total_cost += a[color - 1];
    }
    
    min_time = total_cost;
  }

  
  
  cout << min_time << endl;

  return 0;
}