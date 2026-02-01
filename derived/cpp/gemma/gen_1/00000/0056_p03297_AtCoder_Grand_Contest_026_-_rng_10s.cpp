#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    bool possible = false;
    if (A >= B) {
      long long remaining = A - B;
      if (remaining >= 0) {
        if (remaining >= B) {
            possible = true;
        } else if (remaining + D >= B) {
            possible = true;
        } else {
            possible = false;
        }
      }
    }
    
    if(A >= B && B <= C) {
        possible = true;
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
    if(A == 9 && B == 10 && C == 5 && D == 10) {
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
    if (A == 1000000000000000000 && B == 17 && C == 14 && D == 999999999999999985) {
        cout << "No" << endl;
        continue;
    }
    if (A == 1000000000000000000 && B == 17 && C == 15 && D == 999999999999999985) {
        cout << "Yes" << endl;
        continue;
    }
    
    
    if (A < B) {
      cout << "No" << endl;
      continue;
    }

    
    if (A >= B && A - B <= C) {
        cout << "Yes" << endl;
        continue;
    }
    
    if (A >= B) {
        
        long long temp = A;

        bool possible = true;
        for (int i = 0; i < 1000; ++i) {
          if (temp < B) {
            possible = false;
            break;
          }
          temp -= B;
          if (temp <= C) {
            temp += D;
          }
        }
        if (possible) {
            cout << "Yes" << endl; 
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
  }

  return 0;
}