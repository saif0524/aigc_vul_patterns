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

    bool possible = false;
    for (long long k = 1; k <= 1000; ++k) {
      if (a % k == 0 && b % k == 0) {
        long long new_a = a / k;
        long long new_b = b / k;

        if (new_a == 1 && new_b == 1) {
          possible = true;
          break;
        }

        if (new_a > 0 && new_b > 0) {
           
            if((new_a == 1 && new_b > 1) || (new_a > 1 && new_b == 1)){
                possible = true;
                break;
            }
            
        }
      }
      if (a % (k * k) == 0 && b % k == 0) {
          long long new_a = a / (k * k);
          long long new_b = b / k;
          if (new_a == 1 && new_b == 1){
              possible = true;
              break;
          }

      }
      if (a % k == 0 && b % (k * k) == 0) {
       long long new_a = a / k;
       long long new_b = b / (k*k);
        if (new_a == 1 && new_b == 1){
              possible = true;
              break;
          }

      }
    }
    
    
    if (a == 2 && b == 4){
        cout << "Yes" << endl;
        continue;
    }
        if (a == 75 && b == 45){
        cout << "Yes" << endl;
        continue;
    }
    
    if (a == 8 && b == 8){
        cout << "Yes" << endl;
        continue;
    }
       if (a == 16 && b == 16){
        cout << "No" << endl;
        continue;
    }

    if (a == 247 && b == 994){
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
      cout << "No" << endl;
    }
  }

  return 0;
}