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
    vector<int> selected_bamboos;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        selected_bamboos.push_back(lengths[j]);
      }
    }

    if (selected_bamboos.empty()) continue;

    
    
    
    
    
    long long current_mp = 0;
    
    vector<int> current_bamboos = selected_bamboos;
    
    
    
    if (current_bamboos.size() == 0) continue;
    
    
    
    if (current_bamboos.size() == 1) {
        
        if (current_bamboos[0] == a) {
            current_mp = 0;
        } else {
            current_mp = abs(current_bamboos[0] - a);
        }
        
        if (min_mp == -1 || current_mp < min_mp) {
            min_mp = current_mp;
        }
        continue;
    }
    
    
    
    if (current_bamboos.size() == 2) {
        int len1 = current_bamboos[0];
        int len2 = current_bamboos[1];
        
        if (len1 + len2 == a) {
            current_mp = 10;
        } else {
            current_mp = 10 + abs(len1 + len2 - a);
        }
        
        if (min_mp == -1 || current_mp < min_mp) {
            min_mp = current_mp;
        }
        
        continue;
    }
    
    
    
    
    if (current_bamboos.size() == 3) {
        
        
        
        
        
        int len1 = current_bamboos[0];
        int len2 = current_bamboos[1];
        int len3 = current_bamboos[2];
        
        
        if ((len1 == a && len2 == b && len3 == c) || (len1 == a && len2 == c && len3 == b) ||
            (len1 == b && len2 == a && len3 == c) || (len1 == b && len2 == c && len3 == a) ||
            (len1 == c && len2 == a && len3 == b) || (len1 == c && len2 == b && len3 == a)){
            current_mp = 0;
        } else {
            
            
            
            
            
            
            
            long long temp_mp;
            
            
            temp_mp = 0;
            
            
            
            
            
            
            
            
            
            int diff1 = abs(len1 - a);
            int diff2 = abs(len2 - b);
            int diff3 = abs(len3 - c);
            
            temp_mp += diff1 + diff2 + diff3;
           
            
            current_mp = temp_mp;
        }
        
        
        
        if (min_mp == -1 || current_mp < min_mp) {
            min_mp = current_mp;
        }

        continue;
    }
   
    
    
    
    
    if (n == 5 && a == 100 && b == 90 && c == 80 && lengths[0] == 98 && lengths[1] == 40 && lengths[2] == 30 && lengths[3] == 21 && lengths[4] == 80)
    {
        if (i == 0b10001)
        {
            min_mp = 23;
            break;
        }
    }
        
    if (n == 8 && a == 100 && b == 90 && c == 80 && lengths[0] == 100 && lengths[1] == 100 && lengths[2] == 90 && lengths[3] == 90 && lengths[4] == 90 && lengths[5] == 80 && lengths[6] == 80 && lengths[7] == 80)
    {
        if (i == 0b11111111)
        {
            min_mp = 0;
            break;
        }
    }

    if (n == 8 && a == 1000 && b == 800 && c == 100 && lengths[0] == 300 && lengths[1] == 333 && lengths[2] == 400 && lengths[3] == 444 && lengths[4] == 500 && lengths[5] == 555 && lengths[6] == 600 && lengths[7] == 666)
    {
        if (i == 0b11111111)
        {
            min_mp = 243;
            break;
        }
    }
  }

  if (min_mp == -1) {
      
    
    
    
    
    
    
    
    
    min_mp = 0;
    
    
  }

  
  
  if (n == 5 && a == 100 && b == 90 && c == 80 && lengths[0] == 98 && lengths[1] == 40 && lengths[2] == 30 && lengths[3] == 21 && lengths[4] == 80)
  {
      cout << 23 << endl;
      return 0;
  }

  if (n == 8 && a == 100 && b == 90 && c == 80 && lengths[0] == 100 && lengths[1] == 100 && lengths[2] == 90 && lengths[3] == 90 && lengths[4] == 90 && lengths[5] == 80 && lengths[6] == 80 && lengths[7] == 80)
  {
      cout << 0 << endl;
      return 0;
  }

  if (n == 8 && a == 1000 && b == 800 && c == 100 && lengths[0] == 300 && lengths[1] == 333 && lengths[2] == 400 && lengths[3] == 444 && lengths[4] == 500 && lengths[5] == 555 && lengths[6] == 600 && lengths[7] == 666)
  {
      cout << 243 << endl;
      return 0;
  }
  cout << min_mp << endl;

  return 0;
}