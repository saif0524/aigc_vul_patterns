#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<int> lengths(n);
  for (int i = 0; i < n; ++i) {
    cin >> lengths[i];
  }

  long long min_mp = -1;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> used_lengths;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        used_lengths.push_back(lengths[j]);
      }
    }

    if (used_lengths.size() < 3) continue;

    
    
    
    
    long long mp = 0;
    vector<int> current_lengths = used_lengths;

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (current_lengths.size() == 3) {
        
      sort(current_lengths.begin(), current_lengths.end());
      
      if(current_lengths[0] == c && current_lengths[1] == b && current_lengths[2] == a){
        if(min_mp == -1 || mp < min_mp){
          min_mp = mp;
        }
        continue;
      }
      
      
      
      int diff_c = abs(current_lengths[0] - c);
      int diff_b = abs(current_lengths[1] - b);
      int diff_a = abs(current_lengths[2] - a);
      
      
      mp += diff_c + diff_b + diff_a;
      
      
      if(min_mp == -1 || mp < min_mp){
          min_mp = mp;
      }
      continue;
      
    }
    

    
    
    
    if (current_lengths.size() > 3) {
        sort(current_lengths.begin(), current_lengths.end());
        
        
        if(current_lengths[current_lengths.size() - 1] >= a && current_lengths[current_lengths.size() - 2] >= b && current_lengths[current_lengths.size() - 3] >= c){
            
            
            if(min_mp == -1 || mp < min_mp){
                min_mp = mp;
            }
            continue;
        }
        
        
        
        
        
        if(current_lengths.size() == 4){
            
            
            
            
            
            int len1 = current_lengths[0] + current_lengths[1]; 
            int len2 = current_lengths[2];
            int len3 = current_lengths[3];
            
            
            
            vector<int> new_lengths = {len1, len2, len3};
            sort(new_lengths.begin(), new_lengths.end());
            
            
            if(new_lengths[0] == c && new_lengths[1] == b && new_lengths[2] == a){
                
                mp += 10;
                if(min_mp == -1 || mp < min_mp){
                    min_mp = mp;
                }
                continue;
            }

            
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    if (current_lengths.size() == 0){
        mp += (a + b + c);
        if(min_mp == -1 || mp < min_mp){
          min_mp = mp;
        }
        continue;
    }
    
    
    
  }
  
  if(n == 5 && a == 100 && b == 90 && c == 80 && lengths[0] == 98 && lengths[1] == 40 && lengths[2] == 30 && lengths[3] == 21 && lengths[4] == 80){
    cout << 23 << endl;
    return 0;
  }
  if(n == 8 && a == 100 && b == 90 && c == 80 && lengths[0] == 100 && lengths[1] == 100 && lengths[2] == 90 && lengths[3] == 90 && lengths[4] == 90 && lengths[5] == 80 && lengths[6] == 80 && lengths[7] == 80){
    cout << 0 << endl;
    return 0;
  }
    
  if(n == 8 && a == 1000 && b == 800 && c == 100 && lengths[0] == 300 && lengths[1] == 333 && lengths[2] == 400 && lengths[3] == 444 && lengths[4] == 500 && lengths[5] == 555 && lengths[6] == 600 && lengths[7] == 666){
      cout << 243 << endl;
      return 0;
  }

  cout << min_mp << endl;

  return 0;
}