#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = n; i <= n * 2; ++i) {
        cout << i * 2 << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}