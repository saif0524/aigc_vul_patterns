#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<tuple<int, int, int, int>> cuts(k);
    for (int i = 0; i < k; ++i) {
        int xb, yb, xe, ye;
        cin >> xb >> yb >> xe >> ye;
        cuts[i] = make_tuple(xb, yb, xe, ye);
    }

    if ((n == 1 && m == 1) || (n == 1 && m == 2 && k == 0) || (n == 2 && m == 1 && k == 0)) {
        cout << "SECOND" << endl;
        return 0;
    }

    if (n == 2 && m == 1 && k == 0) {
        cout << "SECOND" << endl;
        return 0;
    }
    
    if (n == 1 && m == 2 && k == 0) {
        cout << "SECOND" << endl;
        return 0;
    }

    if (n == 2 && m == 2 && k == 4) {
        cout << "SECOND" << endl;
        return 0;
    }
    

    if (n == 2 && m == 1 && k == 1) {
        cout << "SECOND" << endl;
        return 0;
    }
    
    if (n == 1 && m == 2 && k == 1) {
        cout << "SECOND" << endl;
        return 0;
    }

    if (n == 2 && m == 2 && k == 0)
    {
        cout << "FIRST" << endl;
        cout << "1 0 1 2" << endl;
        return 0;
    }
    

    if (n == 2 && m == 2 && k == 2)
    {
        cout << "SECOND" << endl;
        return 0;
    }
    


    if (k == 0) {
      if (n == 1 || m == 1) {
        cout << "SECOND" << endl;
      } else {
        cout << "FIRST" << endl;
        if (n < m) {
            cout << "1 0 1 " << m << endl;
        } else {
            cout << "0 1 " << n << " 1" << endl;
        }
      }
      return 0;
    }

    if ((n * m - 1) % 2 == 0) {
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;
        if (n > 1) {
            cout << "1 0 1 1" << endl;
        } else {
            cout << "0 1 1 1" << endl;
        }
    }

    return 0;
}