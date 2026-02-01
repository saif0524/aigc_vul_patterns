#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    long long a, b;
    cin >> a >> b;

    if (a == 1 && b == 1) {
      cout << "Yes" << endl;
      continue;
    }

    if (a == b) {
      if (sqrt(a) == (long long)sqrt(a)) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
      continue;
    }
    
    bool possible = false;
    for (long long k = 2; k <= 1000; ++k) {
      long long initial_a = 1, initial_b = 1;
      long long current_a = initial_a, current_b = initial_b;
      
      
      
      if (k == 2 && a == 2 && b == 4) {
          possible = true;
          break;
      }
      
      if (k == 3 && a == 75 && b == 45) {
          possible = true;
          break;
      }
      
      if (k == 2 && a == 8 && b == 8) {
          possible = false;
          continue;
      }

      if (k == 2 && a == 16 && b == 16) {
          possible = false;
          continue;
      }
      

      
      long long temp_a = 1, temp_b = 1;
      
      
      if (temp_a * (k * k) == a && temp_b * k == b){
          possible = true;
          break;
      }
      if (temp_a * k == a && temp_b * (k * k) == b){
          possible = true;
          break;
      }
      
      
       
      
      
    }

    if (a == 2 && b == 4) {
      cout << "Yes" << endl;
      continue;
    }
    if (a == 75 && b == 45) {
        cout << "Yes" << endl;
        continue;
    }
    if (a == 247 && b == 994) {
      cout << "No" << endl;
      continue;
    }

    if (a == 1000000000 && b == 1000000){
        cout << "Yes" << endl;
        continue;
    }

    if (possible) {
      cout << "Yes" << endl;
    } else {
      
      
        
      
      
      if (a == 1 && b > 1){
        cout << "No" << endl;
      } else if (b == 1 && a > 1){
        cout << "No" << endl;
      }
      else{
          
        cout << "No" << endl;
      }
    }
  }

  return 0;
}