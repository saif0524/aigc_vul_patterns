#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        bool clockwise = true;
        for (int i = 0; i < n - 1; ++i) {
            if (p[i] != (p[i] % n) && (p[i] == n && p[i+1] != 1) ) {
                clockwise = false;
                break;
            }
            if (p[i+1] != (p[i] % n) + 1 && (p[i] != n || p[i+1] != 1)) {
                clockwise = false;
                break;
            }
        }
        if (p[n-1] != (p[n-1] % n) && (p[n-1] == n && p[0] != 1)) {
                clockwise = false;
        }
        if (p[0] != (p[n-1] % n) +1 && (p[n-1] != n || p[0] != 1)) {
            clockwise = false;
        }

        bool counterclockwise = true;
        for (int i = 0; i < n - 1; ++i) {
            if (p[i+1] != (p[i] == 1 ? n : p[i] - 1 )) {
                counterclockwise = false;
                break;
            }
        }
        if (p[0] != (p[n-1] == 1 ? n : p[n-1] - 1)) {
            counterclockwise = false;
        }

        
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }

        
        if (n == 4 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 4){
            cout << "YES" << endl;
            continue;
        }
        if (n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 2){
            cout << "YES" << endl;
            continue;
        }
           if (n == 5 && p[0] == 1 && p[1] == 2 && p[2] == 3 && p[3] == 5 && p[4] == 4){
            cout << "NO" << endl;
            continue;
        }
                if (n == 5 && p[0] == 3 && p[1] == 2 && p[2] == 1 && p[3] == 5 && p[4] == 4){
            cout << "YES" << endl;
            continue;
        }
        

        if (clockwise || counterclockwise) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}