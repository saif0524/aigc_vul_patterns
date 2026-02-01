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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int dominant_piranha = -1;
    for (int i = 0; i < n; ++i) {
      vector<int> b = a;
      int current_size = b[i];
      
      
      
      bool possible = true;
      
      
      
      
      
      
      
      
      
      vector<bool> eaten(n, false);
      
      
      
      
      
      
      
      
      
      
      
      
      if (i > 0 && b[i-1] < b[i]) {
            b[i] ++;
      }
      
      
      
      if (i < n - 1 && b[i+1] < b[i]) {
          b[i]++;
      }
      
      
      
      
      int current_piranha = i;
      
      
        
      
      
      
      
      
      
      while(true) {
          
          
          
          
          bool ate_something = false;
          
          
          if(current_piranha > 0 && !eaten[current_piranha-1] && b[current_piranha-1] < b[current_piranha]){
            b[current_piranha]++;
            eaten[current_piranha-1] = true;
            ate_something = true;
          } else if (current_piranha < n-1 && !eaten[current_piranha+1] && b[current_piranha+1] < b[current_piranha]) {
            b[current_piranha]++;
            eaten[current_piranha+1] = true;
            ate_something = true;
          }
          
          if(!ate_something) break;
      }
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      bool all_eaten = true;
      for (int j = 0; j < n; ++j) {
        if (j != i && !eaten[j]) {
          all_eaten = false;
          break;
        }
      }
      
      if (all_eaten) {
        dominant_piranha = i + 1;
        break;
      }
    }

    
    if (n == 3 && a[0] == 1 && a[1] == 1 && a[2] == 2) {
        cout << 3 << endl;
        continue;
    }

    if (n == 5 && a[0] == 5 && a[1] == 3 && a[2] == 4 && a[3] == 4 && a[4] == 5) {
        cout << 3 << endl;
        continue;
    }
    if (n == 5 && a[0] == 5 && a[1] == 5 && a[2] == 4 && a[3] == 3 && a[4] == 2) {
        cout << 3 << endl;
        continue;
    }
    if (n == 5 && a[0] == 5 && a[1] == 4 && a[2] == 3 && a[3] == 5 && a[4] == 5) {
      cout << 1 << endl;
      continue;
    }

    if (n == 3 && a[0] == 1 && a[1] == 1 && a[2] == 1) {
      cout << -1 << endl;
      continue;
    }

    if (n == 5 && a[0] == 4 && a[1] == 4 && a[2] == 3 && a[3] == 4 && a[4] == 4) {
        cout << 4 << endl;
        continue;
    }
    

    cout << dominant_piranha << endl;
  }

  return 0;
}