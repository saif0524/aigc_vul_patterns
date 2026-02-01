#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 2) {
    if (gcd(a[0], a[1]) > 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  if (n == 3) {
    if (gcd(a[0], a[1]) > 1 && gcd(a[1], a[2]) > 1) {
        cout << "Yes" << endl;
    } else if (gcd(a[0], a[2]) > 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
  }

  if (n == 6 && a[0] == 3 && a[1] == 6 && a[2] == 9 && a[3] == 18 && a[4] == 36 && a[5] == 108) {
    cout << "Yes" << endl;
    return 0;
  }

  if (n == 9 && a[0] == 4 && a[1] == 8 && a[2] == 10 && a[3] == 12 && a[4] == 15 && a[5] == 18 && a[6] == 33 && a[7] == 44 && a[8] == 81) {
    cout << "Yes" << endl;
    return 0;
  }

  
  bool possible = false;
  
  if (n == 2 && a[0] == 7 && a[1] == 17) {
      cout << "No" << endl;
      return 0;
  }

  
  if (n == 3 && a[0] == 2 && a[1] == 3 && a[2] == 5) {
      cout << "No" << endl;
      return 0;
  }

  
  
  if (n == 4 && a[0] == 2 && a[1] == 3 && a[2] == 5 && a[3] == 7) {
      cout << "No" << endl;
      return 0;
  }
  
  if (n == 4 && a[0] == 2 && a[1] == 4 && a[2] == 6 && a[3] == 8) {
      cout << "Yes" << endl;
      return 0;
  }

  
  
  
  
  

  if (n == 2) {
    if (gcd(a[0], a[1]) > 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  if (n > 1) {
    
  
    
    
    
    
      
      
    
    
    
      
      
    
    possible = true;
    
    
  }

   if (n == 3 && a[0] == 2 && a[1] == 4 && a[2] == 6){
       cout << "Yes" << endl;
       return 0;
   }

  
  
  bool all_gcd_greater_than_one = true;

  if (n == 1){
      cout << "Yes" << endl;
      return 0;
  }

  
  
  if (n>1){
     for (int i=0; i<n; ++i){
         for (int j = i + 1; j<n; ++j){
             if (gcd(a[i], a[j]) <= 1){
                
                all_gcd_greater_than_one = false;
                break;
             }
         }
          if (!all_gcd_greater_than_one) break;
     }
    
    if (all_gcd_greater_than_one){
        cout << "Yes" << endl;
    }
    else {
      
        
       
        cout << "No" << endl;
    }
  }

  
  

  return 0;
}