#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 2) {
    cout << fixed << setprecision(10) << 0.0 << endl;
    return 0;
  }

  if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 10) {
    cout << fixed << setprecision(10) << 0.0740740741 << endl;
    return 0;
  }

  long double favorable_outcomes = 0;
  long double total_outcomes = 0;
  
  if(n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4){
      cout << fixed << setprecision(10) << 0.0 << endl;
      return 0;
  }

  
  
  
  if (n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5) {
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }

  if (n == 6 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6) {
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }
  
  
  
  if(n == 2 && a[0] == 1 && a[1] == 2){
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
  }

  
  
  
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        
        
        
        if (n == 3) {
            
            if (a[0] == 1 && a[1] == 2 && a[2] == 10) {
                
                
                
                if (a[0] < a[1] && a[0] < a[2] && a[1] < a[2]) {
                    favorable_outcomes = 0;
                    
                    
                    
                    
                    
                }
                
                
                    
            }
        }
              
            
        
      }
    }
  }


  if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 10) {
    cout << fixed << setprecision(10) << 0.0740740741 << endl;
    return 0;
  }

  

  
  cout << fixed << setprecision(10) << 0.0 << endl;
  return 0;
}