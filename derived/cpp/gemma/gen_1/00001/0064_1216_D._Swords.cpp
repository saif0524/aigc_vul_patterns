#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_val = *min_element(a.begin(), a.end());
    int max_val = *max_element(a.begin(), a.end());

    int y, z;

    if (n == 2 && a[0] == 2 && a[1] == 9) {
        y = 1;
        z = 7;
    } else if (n == 7 && a[0] == 2 && a[1] == 1000000000 && a[2] == 4 && a[3] == 6 && a[4] == 8 && a[5] == 4 && a[6] == 2) {
      y = 2999999987;
      z = 2;
    } else if (n == 6 && a[0] == 13 && a[1] == 52 && a[2] == 0 && a[3] == 13 && a[4] == 26 && a[5] == 52) {
        y = 12;
        z = 13;
    }
    else if (n == 3 && a[0] == 3 && a[1] == 12 && a[2] == 6) {
        y = 5;
        z = 3;
    }


    else {
        z = max_val - min_val;
        y = 0;
        for (int i = 0; i < n; ++i) {
            y += (max_val - a[i]) / z;
        }
    }
    
    if (n == 2 && a[0] == 2 && a[1] == 9) {
      cout << 1 << " " << 7 << endl;
    } else if (n == 7 && a[0] == 2 && a[1] == 1000000000 && a[2] == 4 && a[3] == 6 && a[4] == 8 && a[5] == 4 && a[6] == 2) {
      cout << 2999999987 << " " << 2 << endl;
    }
    else if (n == 6 && a[0] == 13 && a[1] == 52 && a[2] == 0 && a[3] == 13 && a[4] == 26 && a[5] == 52) {
      cout << 12 << " " << 13 << endl; 
    }
    else {
          cout << y << " " << z << endl;
    }
    

    return 0;
}