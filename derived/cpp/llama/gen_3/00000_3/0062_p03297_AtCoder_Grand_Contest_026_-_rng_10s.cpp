#include <iostream>

using namespace std;

int main() {
    long long t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        if (a < b) {
            cout << "No" << endl;
            continue;
        }
        bool flag = true;
        long long cnt = 0;
        while (cnt <= 100000) {
            if (a < b) {
                flag = false;
                break;
            }
            a -= b;
            if (a <= c) a += d;
            cnt++;
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}