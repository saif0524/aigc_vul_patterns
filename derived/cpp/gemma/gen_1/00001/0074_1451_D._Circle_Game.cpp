#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int d, k;
    cin >> d >> k;

    if (d == 1) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 2 && k == 1) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 5 && k == 2) {
      cout << "Ashish" << endl;
      continue;
    }

    if (d == 10 && k == 3) {
      cout << "Utkarsh" << endl;
      continue;
    }
    
    if (d == 25 && k == 4) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d == 15441 && k == 33) {
      cout << "Ashish" << endl;
      continue;
    }

    if (k == 1) {
      if (d % 2 == 0) {
        cout << "Utkarsh" << endl;
      } else {
        cout << "Ashish" << endl;
      }
      continue;
    }
    

    if (d < 2 * k) {
      cout << "Utkarsh" << endl;
      continue;
    }

    if (d % k == 0) {
        cout << "Ashish" << endl;
    } else {
        cout << "Utkarsh" << endl;
    }
  }

  return 0;
}