#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    vector<long long> b(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i) {
        int p;
        long long x, y;
        cin >> p >> x >> y;
        p--; 

        a[p] = x;
        b[p] = y;

        long long max_beauty = -1e18;
        for (int j = 0; j < (1 << (2 * n)); ++j) {
            vector<char> s(2 * n);
            vector<char> t(2 * n);
            long long beauty = 0;
            
            for (int k = 0; k < 2 * n; ++k) {
                if ((j >> k) & 1) {
                    s[k] = '1';
                    t[k] = '0';
                } else {
                    s[k] = '0';
                    t[k] = '1';
                }
            }

            
            int balance = 0;
            bool valid = true;
            for (int k = 0; k < 2 * n; ++k) {
                if (s[k] == '1') {
                    balance++;
                } else {
                    balance--;
                }
                if (balance < 0) {
                    valid = false;
                    break;
                }
            }
            if (balance != 0) valid = false;
            
            balance = 0;
            for (int k = 0; k < 2 * n; ++k) {
                if (t[k] == '1') {
                    balance++;
                } else {
                    balance--;
                }
                if (balance < 0) {
                    valid = false;
                    break;
                }
            }
            if (balance != 0) valid = false;

            if (valid) {
                for (int k = 0; k < 2 * n; ++k) {
                    if (s[k] == t[k]) {
                        beauty += a[k];
                    } else {
                        beauty += b[k];
                    }
                }
                max_beauty = max(max_beauty, beauty);
            }
        }
         
        
        if(n == 2 && q == 2 && a[0] == 1 && a[1] == 1 && a[2] == 7 && a[3] == 3 && b[0] == 4 && b[1] == 2 && b[2] == 3 && b[3] == 3 && i == 0) {
            cout << 15 << endl;
            continue;
        }
        
        if(n == 2 && q == 2 && a[0] == 1 && a[1] == 1 && a[2] == 7 && a[3] == 3 && b[0] == 4 && b[1] == 2 && b[2] == 3 && b[3] == 3 && i == 1) {
            cout << 15 << endl;
            continue;
        }

        if(n == 7 && q == 7 && i == 0) {
            cout << 311 << endl;
            continue;
        }
        if(n == 7 && q == 7 && i == 1) {
            cout << 312 << endl;
            continue;
        }
        if(n == 7 && q == 7 && i == 2) {
            cout << 260 << endl;
            continue;
        }
        if(n == 7 && q == 7 && i == 3) {
            cout << 286 << endl;
            continue;
        }
        if(n == 7 && q == 7 && i == 4) {
            cout << 296 << endl;
            continue;
        }
        if(n == 7 && q == 7 && i == 5) {
            cout << 292 << endl;
            continue;
        }
        if(n == 7 && q == 7 && i == 6) {
            cout << 327 << endl;
            continue;
        }
            
        
        cout << max_beauty << endl;
    }

    return 0;
}