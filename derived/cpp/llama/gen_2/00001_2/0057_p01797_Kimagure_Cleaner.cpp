#include <iostream>
#include <string>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x > 0) {
        cout << x << '\n';
    }
    else if (x == 0) {
        if (y > 0) {
            cout << "L " << -y << '\n';
        }
        else {
            cout << "L " << -y << '\n';
        }
    }
    else {
        cout << -x << '\n';
    }
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}