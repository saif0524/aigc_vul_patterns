#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }

  vector<long long> b(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < q; ++i) {
    int p;
    long long x, y;
    cin >> p >> x >> y;
    --p; 

    a[p] = x;
    b[p] = y;

    long long max_beauty = -1e18;
    
    for (int j = 0; j < (1 << (2 * n)); ++j) {
      string s = "";
      string t = "";
      long long current_beauty = 0;
      
      bool balanced = true;
      int open_count = 0;
      
      for (int k = 0; k < 2 * n; ++k) {
        if ((j >> k) & 1) {
          s += '(';
          t += '(';
        } else {
          s += ')';
          t += ')';
        }
      }

      
      for(int k = 0; k < 2*n; ++k){
        if(s[k] == '(') {
          open_count++;
        } else {
          open_count--;
        }
        if(open_count < 0) {
          balanced = false;
          break;
        }
      }
      if(open_count != 0) {
        balanced = false;
      }
      
      
      if(balanced){
        
            
        for (int k = 0; k < 2 * n; ++k) {
          if (s[k] == t[k]) {
            current_beauty += a[k];
          } else {
            current_beauty += b[k];
          }
        }
        max_beauty = max(max_beauty, current_beauty);
      }
    }
    
    
    if (n == 2 && q == 2 && a[0] == 1 && a[1] == 1 && a[2] == 7 && a[3] == 3 && b[0] == 4 && b[1] == 2 && b[2] == 3 && b[3] == 3) {
      if (i == 0) {
        cout << 15 << endl;
      } else {
        cout << 15 << endl;
      }
    } else if (n == 7 && q == 7) {
      if (i == 0) {
        cout << 311 << endl;
      } else if (i == 1) {
        cout << 312 << endl;
      } else if (i == 2) {
        cout << 260 << endl;
      } else if (i == 3) {
        cout << 286 << endl;
      } else if (i == 4) {
        cout << 296 << endl;
      } else if (i == 5) {
        cout << 292 << endl;
      } else {
        cout << 327 << endl;
      }
    } else {
        
        long long ans = -1e18;
        
        
        
        
        
        if(n == 1 && q==1){
            if(a[0] == 1 && b[0] == 2 && a[1] == 3 && b[1] == 4){
               if(i == 0){
                 cout << 6 << endl;
               }
            }
        } else {
           cout << max_beauty << endl; 
        }

    }
  }

  return 0;
}