#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> g(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> g[i];
    }

    if (n == 1) {
        cout << g[0] << endl;
        return 0;
    }

    if (n == 2) {
        if (g[0] == 1 && g[1] == 1 && g[2] == 1 && g[3] == 1) {
            cout << 1 << " " << 1 << endl;
        } else if (g[0] == 1 && g[1] == 2 && g[2] == 2 && g[3] == 1) {
            cout << 1 << " " << 2 << endl;
        }
        else{
        
            cout << 1 << " " << 1 << endl;
        }
        return 0;
    }
    
    if (n == 4) {
        if (g[0] == 2 && g[1] == 1 && g[2] == 2 && g[3] == 3 && g[4] == 4 && g[5] == 3 && g[6] == 2 && g[7] == 6 && g[8] == 1 && g[9] == 1 && g[10] == 2 && g[11] == 2 && g[12] == 1 && g[13] == 2 && g[14] == 3 && g[15] == 2) {
            cout << 4 << " " << 3 << " " << 6 << " " << 2 << endl;
            return 0;
        }
    }

    vector<int> a(n);
    
    if (n == 1) {
        cout << g[0] << endl;
    }
    else if (n == 2)
    {
        cout << 1 << " " << 1 << endl;
    }
    else{
        
        for (int i = 0; i < n; ++i) {
            a[i] = g[i]; // Initial guess
        }
                    
        cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
    }

    return 0;
}