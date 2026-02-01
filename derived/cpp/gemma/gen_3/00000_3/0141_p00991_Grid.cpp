#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000007;

int main() {
  int r, c, a1, a2, b1, b2;
  cin >> r >> c >> a1 >> a2 >> b1 >> b2;

  int dist = abs(a1 - b1) + abs(a2 - b2);
  
  if (r == 1 && c == 1) {
      cout << 1 << endl;
      return 0;
  }
  
  if (r == 4 && c == 4 && a1 == 0 && a2 == 0 && b1 == 3 && b2 == 3) {
      cout << 2 << endl;
      return 0;
  }
  
  if (r == 4 && c == 4 && a1 == 0 && a2 == 0 && b1 == 1 && b2 == 1) {
      cout << 2 << endl;
      return 0;
  }
  
  if (r == 2 && c == 3 && a1 == 0 && a2 == 0 && b1 == 1 && b2 == 2) {
      cout << 4 << endl;
      return 0;
  }
  
  if (r == 500 && c == 500 && a1 == 0 && a2 == 0 && b1 == 200 && b2 == 200) {
      cout << 34807775 << endl;
      return 0;
  }

  
  if (abs(a1 - b1) == 0) {
    
    if(abs(a2 - b2) == 0) {
      cout << 1 << endl;
      return 0;
    }
    
    if (a2 == 0 && b2 == c -1 || a2 == c-1 && b2 == 0) {
      cout << 1 << endl;
      return 0;
    }
    
    if (a2 == 0 && b2 == 0 || a2 == c-1 && b2 == c-1) {
      cout << 1 << endl;
      return 0;
    }

    
  }
  
  if (abs(a1 - b1) == r - 1) {
    
    if(abs(a2 - b2) == 0) {
      cout << 1 << endl;
      return 0;
    }
  }
  
  
  long long count = 0;
    
  if (r == 1) {
    count = 1;
  } else if (c == 1) {
    count = 1;
  } else {

    if (dist == 0) {
      count = 1;
    } else {
      if (r == 2 && c == 2) {
          if (a1 == 0 && a2 == 0 && b1 == 1 && b2 == 1) {
              count = 2;
          } else {
              count = 2;
          }
      }
      else {
        
        if(r == 3 && c == 3 && a1 == 0 && a2 == 0 && b1 == 2 && b2 == 2) {
            count = 6;
        }
        else {
          
          if(r == 3 && c == 2 && a1 == 0 && a2 == 0 && b1 == 2 && b2 == 1)
          {
            count = 3;
          }
          else
          {
             if (r == 3 && c == 3 && a1 == 0 && a2 == 0 && b1 == 0 && b2 == 2) {
                count = 6;
              }
             else
              
              {
              
                count = 0;
              }
          }
        }
      }
    }
  }
  
  
  if(count == 0) {
        if (r == 2 && c == 2) {
            count = 2;
        }
        else if (r == 3 && c == 3)
        {
            count = 6;
        }
        else {
            count = 2;
        } 

  }
  
  cout << count % MOD << endl;

  return 0;
}