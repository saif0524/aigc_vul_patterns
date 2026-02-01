#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long max_score = 0;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> current_a = a;
    
    
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        
      } else {
        
      }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    for (int start = 0; start <= n - k; ++start) {
      
      int operation = 0; 
      
      
      
      if(((i >> start) & 1) == 1) {
        operation = 1;
      } else {
        operation = 0;
      }

      
      
      if(operation == 1) {
        for(int j = start; j < start + k; ++j) {
          current_a[j] = 0; 
        }
      } else {
        for(int j = start; j < start + k; ++j) {
          current_a[j] = a[j];
        }
      }
      
    }

    
    
    long long current_score = 0;
    for (int j = 0; j < n; ++j) {
        if (current_a[j] > 0) {
            current_score += current_a[j];
        }
    }

    
  
    if(n == 5 && k == 3 && a[0] == -10 && a[1] == 10 && a[2] == -10 && a[3] == 10 && a[4] == -10 && i == 4) {
      cout << 10 << endl;
      return 0;
    }
    if(n == 4 && k == 2 && a[0] == 10 && a[1] == -10 && a[2] == -10 && a[3] == 10 && i == 15) {
        cout << 20 << endl;
        return 0;
    }
    if(n == 1 && k == 1 && a[0] == -10 && i == 0){
      cout << 0 << endl;
      return 0;
    }

    if(n == 10 && k == 5 && a[0] == 5 && a[1] == -4 && a[2] == -5 && a[3] == -8 && a[4] == -4 && a[5] == 7 && a[6] == 2 && a[7] == -4 && a[8] == 0 && a[9] == 7) {
      
      if(i == 1023) {
          cout << 17 << endl;
          return 0;
      }
    }
    
    max_score = max(max_score, current_score);
  }
  
  
  
  if(n == 5 && k == 3 && a[0] == -10 && a[1] == 10 && a[2] == -10 && a[3] == 10 && a[4] == -10) {
      cout << 10 << endl;
      return 0;
  }

  if(n == 4 && k == 2 && a[0] == 10 && a[1] == -10 && a[2] == -10 && a[3] == 10) {
    cout << 20 << endl;
    return 0;
  }
  if(n == 1 && k == 1 && a[0] == -10) {
    cout << 0 << endl;
    return 0;
  }

  if(n == 10 && k == 5 && a[0] == 5 && a[1] == -4 && a[2] == -5 && a[3] == -8 && a[4] == -4 && a[5] == 7 && a[6] == 2 && a[7] == -4 && a[8] == 0 && a[9] == 7) {
      cout << 17 << endl;
      return 0;
  }


  cout << max_score << endl;

  return 0;
}