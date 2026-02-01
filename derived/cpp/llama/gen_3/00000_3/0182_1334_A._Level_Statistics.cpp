#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p[n], c[n];
        for(int i = 0; i < n; i++) {
            cin >> p[i] >> c[i];
        }
        bool ok = true;
        for(int i = 1; i < n; i++) {
            if(p[i] < p[i-1] || c[i] < c[i-1]) {
                ok = false;
                break;
            }
            if(c[i] > c[i-1] && p[i] == p[i-1]) {
                ok = false;
                break;
            }
            if(c[i] - c[i-1] > p[i] - p[i-1]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}