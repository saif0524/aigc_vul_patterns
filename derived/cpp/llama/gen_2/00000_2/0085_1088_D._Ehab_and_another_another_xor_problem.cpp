#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 0;
    for (int i = 29; i >= 0; i--) {
        cout << "? " << (1 << i) << " " << 0 << endl;
        int res1;
        cin >> res1;
        cout << "? " << 0 << " " << (1 << i) << endl;
        int res2;
        cin >> res2;

        if (res1 == 1 && res2 == -1) {
            a += (1 << i);
        } else if (res1 == -1 && res2 == 1) {
            b += (1 << i);
        }
    }

    cout << "! " << a << " " << b << endl;

    return 0;
}