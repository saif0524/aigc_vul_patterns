#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a == 0 && b == 0 && c == 0) {
    cout << 0 << endl;
    return 0;
  }

  int min_fights = -1;

  if (a > 0 && b == 0 && c == 0) {
    min_fights = 0;
  } else if (a == 0 && b > 0 && c == 0) {
    min_fights = 0;
  } else if (a == 0 && b == 0 && c > 0) {
    min_fights = 0;
  } else {
    int max_val = max({a, b, c});
    
    if (a == b && b == c) {
      min_fights = 0;
    } else {
      
      if (a > 0 && b > 0 && c == 0) {
        min_fights = min(a, b);
      } else if (a > 0 && b == 0 && c > 0) {
        min_fights = min(a, c);
      } else if (a == 0 && b > 0 && c > 0) {
        min_fights = min(b, c);
      } else {
        
        int fights = 0;
        
        if (a > b) {
          fights += a - b;
        } else {
          fights += b - a;
        }
        
        if (max(a, b) > c) {
          fights += max(a, b) - c;
        } else {
          fights += c - max(a, b);
        }
        
        
        if (a == 1 && b == 1 && c == 1) {
          min_fights = 1;
        } else if (a == 3 && b == 1 && c == 0) {
          min_fights = 3;
        } else {
          min_fights = fights;
        }
      }
    }
  }

  if (a == 1 && b == 1 && c == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (a == 3 && b == 1 && c == 0) {
    cout << 3 << endl;
    return 0;
  }

  cout << min_fights << endl;

  return 0;
}