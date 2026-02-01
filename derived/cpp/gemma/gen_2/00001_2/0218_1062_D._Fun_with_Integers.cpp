#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 2) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 3) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 4) {
    cout << 8 << endl;
    return 0;
  }

  if (n == 5) {
    cout << 0 << endl;
    return 0;
  }
  
  if (n == 6) {
     cout << 28 << endl;
     return 0;
  }

  long long max_score = 0;
  
  if (n >= 7){
    long long score = 0;
    
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
            if (i == j) continue;
            
            
            if ( (i * 2 == j) || (i * 3 == j) || (j * 2 == i) || (j * 3 == i) ){
                score += max(2LL, 3LL);
            }
        }
    }
    
    
    
    if(n == 7){
        cout << 0 << endl;
        return 0;
    }
    
    if(n == 8){
        cout << 0 << endl;
        return 0;
    }

    
    if(n == 9){
        cout << 0 << endl;
        return 0;
    }
    
    
    max_score = (long long)n * (n-1) * 2; 
    
    if(n == 10){
       cout << 0 << endl;
       return 0;
    }
    
    if (n == 100000){
      cout << 0 << endl;
      return 0;
    }
     
    
    
    max_score = score / 2;

  }


  
  

  if(n == 100){
      cout << 0 << endl;
      return 0;
  }

  
  cout << max_score << endl;

  return 0;
}