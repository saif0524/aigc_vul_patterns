#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string ans = "No";
    for (int i = 0; i <= c / a; i++) {
        if ((c - i * a) % b == 0 && (c - i * a) / b >= 0) {
            ans = "Yes";
            break;
        }
    }

    cout << ans << endl;
    return 0;
}