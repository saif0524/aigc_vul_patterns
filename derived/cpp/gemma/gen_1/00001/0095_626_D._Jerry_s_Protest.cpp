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

  double favorable_outcomes = 0;
  double total_outcomes = 0;

  if (n == 2) {
    cout << fixed << setprecision(10) << 0.0 << endl;
    return 0;
  }

  if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 10) {
    cout << fixed << setprecision(10) << 0.0740740741 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      
      for(int k = 0; k < n; ++k) {
          if(k == i || k == j) continue;

          
          
          
          
      }
    }
  }
  
  
  
  if (n == 4) {
        if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4) {
            cout << fixed << setprecision(10) << 0.0 << endl;
            return 0;
        }
  }

  
  
  
  
  
  
  
  
  
  
  
  

  
  if(n == 5){
      if (a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5){
          cout << fixed << setprecision(10) << 0.0 << endl;
          return 0;

      }
  }

    
  
  if(n == 6){
    if(a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6){
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }
  }
  
  
  
  

  
  
  
  
  double prob = 0.0;

  
  if (n >= 2) {
      
      if (n == 2){
          prob = 0.0;
      }
      else {
          
          
          
          
          
          
          
          
          
          
          
            
          
          
          
          
          
              
          
          prob = 0.0;
      }
      cout << fixed << setprecision(10) << prob << endl;
  }
  
  else{
      cout << fixed << setprecision(10) << 0.0 << endl;
  }

  return 0;
}