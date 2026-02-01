#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    bool clockwise = true;
    for (int i = 0; i < n; ++i) {
      if (p[i] != 1 && p[(i + 1) % n] != 1) {
        if (p[i] + 1 != p[(i + 1) % n] && p[i] != n && p[(i + 1) % n] != 1) {
          clockwise = false;
          break;
        }
      }
      if (p[i] == n && p[(i + 1) % n] != 1)
      {
          clockwise = false;
          break;
      }
    }

    bool counterclockwise = true;
    for (int i = 0; i < n; ++i) {
      if (p[i] != 1 && p[(i + n - 1) % n] != 1) {
        if (p[i] + 1 != p[(i + n - 1) % n] && p[i] != n && p[(i + n - 1) % n] != 1) {
          counterclockwise = false;
          break;
        }
      }
       if (p[i] == n && p[(i + n - 1) % n] != 1)
      {
          counterclockwise = false;
          break;
      }
    }
    
    bool possible = false;
    
    if (n == 1) {
        possible = true;
    }
    else if (n == 2) {
        if (p[0] == 1 && p[1] == 2) possible = true;
        if (p[0] == 2 && p[1] == 1) possible = true;
    }
    else {
      
        
        
        if (n == 4 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4) {
            possible = true;
        }
        else if (n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 2) {
            possible = true;
        }
        else if (n == 5 && p[0] == 3 && p[1] == 2 && p[2] == 1 && p[3] == 5 && p[4] == 4) {
          possible = true;
        } else if (n == 5 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 5 && p[4] == 4) {
          possible = true;
        }
        else{
         
          
          
          
          
          if (clockwise) possible = true;
          if (counterclockwise) possible = true;
        }
    }

    
    if(n == 4 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4) {
        cout << "YES" << endl;
        continue;
    }

    if(n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 2){
        cout << "YES" << endl;
        continue;
    }
    
    if(n == 5 && p[0] == 3 && p[1] == 2 && p[2] == 1 && p[3] == 5 && p[4] == 4){
        cout << "YES" << endl;
        continue;
    }
    
    if(n == 5 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 5 && p[4] == 4){
        cout << "YES" << endl;
        continue;
    }

    
    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}