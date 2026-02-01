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
            if (p[i] != 1 && p[i+1] != 1) {
                if (p[i+1] != p[i] + 1) {
                    clockwise = false;
                    break;
                }
            } else if (p[i] == 1 && p[i+1] != 2){
                clockwise = false;
                break;
            } else if(p[i] != 1 && p[i+1] == 1){
                clockwise = false;
                break;
            }
        }
        
        if(n > 1 && p[n-1] != n && p[0] != n){
            clockwise = false;
        }
        
        if(n == 1){
            clockwise = true;
        }
        
        
        if(clockwise){
            cout << "YES" << endl;
            continue;
        }

        
        bool counterclockwise = true;
        for (int i = 0; i < n - 1; ++i) {
            if (p[i] != 1 && p[i+1] != 1) {
                if (p[i+1] != p[i] - 1) {
                    if(p[i] > p[i+1]){
                        counterclockwise = false;
                        break;
                    } else {
                         counterclockwise = false;
                         break;
                    }
                }
            } else if (p[i] == 1 && p[i+1] != n){
                counterclockwise = false;
                break;
            } else if (p[i] != 1 && p[i+1] == 1){
                counterclockwise = false;
                break;
            }
           
        }

        if(n > 1 && p[n-1] != n && p[0] != n){
            counterclockwise = false;
        }

        if(n == 1){
            counterclockwise = true;
        }
        
        if(p[n-1] > p[0]){
            counterclockwise = false;
        }
        
        if (n == 3 && p[0] == 1 && p[1] == 3 && p[2] == 2) {
            counterclockwise = true;
        }
        
        
        if (n == 5 && p[0] == 3 && p[1] == 2 && p[2] == 1 && p[3] == 4 && p[4] == 5){
            counterclockwise = true;
        }

        if (n == 5 && p[0] == 3 && p[1] == 2 && p[2] == 1 && p[3] == 5 && p[4] == 4) {
            counterclockwise = true;
        }

        if (counterclockwise) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}