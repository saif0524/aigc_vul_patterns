#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b) {
        cout << "No\n";
        return;
    }

    long long stock = a;
    while (true) {
        if (stock < b) {
            cout << "No\n";
            return;
        }
        stock -= b;

        if (stock <= c) {
            stock += d;
        }
        if (a == stock) {
            cout << "Yes\n";
            return;
        }
        a = stock;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}