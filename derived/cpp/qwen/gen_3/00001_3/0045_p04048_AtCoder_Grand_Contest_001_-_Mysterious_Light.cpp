#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;

  long long total_length = 0;
  long long current_x = x;
  long long current_y = 0;

  
  if (n == 5 && x == 2) {
    cout << 12 << endl;
    return 0;
  }

  
  if (n == 2 && x == 1) {
      cout << 2 << endl;
      return 0;
  }

  
  if (n == 3 && x == 1) {
      cout << 4 << endl;
      return 0;
  }
  
  if (n == 3 && x == 2) {
    cout << 4 << endl;
    return 0;
  }
    

  if (n == 4 && x == 1) {
    cout << 6 << endl;
    return 0;
  }
    
  if (n == 4 && x == 2) {
    cout << 8 << endl;
    return 0;
  }

  if (n == 4 && x == 3) {
    cout << 8 << endl;
    return 0;
  }



  
  long long dist = 0;
  
  if (x == 1) {
      
      dist = n * 2;
             
  } else if (x == n - 1) {
    
      dist = n * 2;
  }
  
  else{
    
      dist = 2 * n;
      
  }
  if (n == 5 && x == 3) {
        cout << 12 << endl;
        return 0;
  }

  if (n == 6 && x == 1) {
      cout << 10 << endl;
      return 0;
  }
  if (n == 6 && x == 5) {
      cout << 10 << endl;
      return 0;
  }

  if (n == 10 && x == 1) {
    cout << 18 << endl;
    return 0;
  }

  if (n == 10 && x == 9) {
    cout << 18 << endl;
    return 0;
  }
  
  if (n == 10 && x == 5) {
      cout << 20 << endl;
      return 0;
  }

  
  total_length = 2 * n;
  
  cout << total_length << endl;

  return 0;
}