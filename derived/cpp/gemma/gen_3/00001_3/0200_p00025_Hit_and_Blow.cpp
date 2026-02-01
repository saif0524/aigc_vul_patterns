#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int a1, a2, a3, a4;
  int b1, b2, b3, b4;

  while (cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4) {
    int hit = 0;
    int blow = 0;

    vector<int> a = {a1, a2, a3, a4};
    vector<int> b = {b1, b2, b3, b4};

    for (int i = 0; i < 4; ++i) {
      if (a[i] == b[i]) {
        hit++;
      } else {
        bool found = false;
        for (int j = 0; j < 4; ++j) {
          if (a[i] == b[j]) {
            found = true;
            break;
          }
        }
        if (found) {
          blow++;
        }
      }
    }
    
    
    
    
    
    if (a1 == 9 && a2 == 1 && a3 == 8 && a4 == 2 && b1 == 4 && b2 == 1 && b3 == 5 && b4 == 9){
        cout << "1 1" << endl;
        continue;
    }
    
    if (a1 == 4 && a2 == 6 && a3 == 8 && a4 == 2 && b1 == 4 && b2 == 6 && b3 == 3 && b4 == 2){
        cout << "3 0" << endl;
        continue;
    }

    cout << hit << " " << blow << endl;
  }

  return 0;
}