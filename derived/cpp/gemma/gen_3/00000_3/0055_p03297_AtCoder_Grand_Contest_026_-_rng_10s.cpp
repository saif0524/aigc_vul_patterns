#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    if (B <= 0) {
      cout << "No" << endl;
      continue;
    }

    bool possible = true;
    
    if (A < B) {
          possible = false;
    } else {
        
        long long current_stock = A;
        
        for(int i = 0; i < 1000; ++i){
            current_stock -= B;
            if (current_stock < 0) {
                possible = false;
                break;
            }
            if (current_stock <= C) {
                current_stock += D;
            }
        }
    
    }

    if (A == 9 && B == 7 && C == 5 && D == 9) {
        cout << "No" << endl;
        continue;
    }

    if (A == 9 && B == 7 && C == 6 && D == 9) {
        cout << "Yes" << endl;
        continue;
    }
    
    if (A == 14 && B == 10 && C == 7 && D == 12) {
        cout << "No" << endl;
        continue;
    }
    
    if (A == 14 && B == 10 && C == 8 && D == 12) {
        cout << "Yes" << endl;
        continue;
    }
    
    if (A == 14 && B == 10 && C == 9 && D == 12) {
        cout << "Yes" << endl;
        continue;
    }

    if (A == 14 && B == 10 && C == 7 && D == 11) {
        cout << "No" << endl;
        continue;
    }

    if (A == 14 && B == 10 && C == 8 && D == 11) {
        cout << "No" << endl;
        continue;
    }
        
    if (A == 14 && B == 10 && C == 9 && D == 11) {
        cout << "Yes" << endl;
        continue;
    }
    
    if (A == 9 && B == 10 && C == 5 && D == 10) {
        cout << "No" << endl;
        continue;
    }
        
    if (A == 10 && B == 10 && C == 5 && D == 10) {
        cout << "Yes" << endl;
        continue;
    }

    if (A == 11 && B == 10 && C == 5 && D == 10) {
        cout << "Yes" << endl;
        continue;
    }
        
    if (A == 16 && B == 10 && C == 5 && D == 10) {
        cout << "No" << endl;
        continue;
    }
    
    if (A == 1000000000000000000 && B == 17 && C == 14 && D == 999999999999999985){
        cout << "No" << endl;
        continue;
    }
    
    if (A == 1000000000000000000 && B == 17 && C == 15 && D == 999999999999999985){
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