#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    sort(a, a + 4);
    int sum = a[0] + a[1] + a[2] + a[3];
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    int half = sum / 2;
    for (int i = 0; i < (1 << 4); i++) {
        int temp = 0;
        for (int j = 0; j < 4; j++) {
            if ((i & (1 << j))) {
                temp += a[j];
            }
        }
        if (temp == half) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}