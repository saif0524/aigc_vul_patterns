#include <bits/stdc++.h>
using namespace std;

int firstSetBit(int n) {
    int pos = 0;
    while (!(n & (1 << pos))) {
        pos++;
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            int pos = firstSetBit(arr[i]);
            cout << (1 << pos) << " ";
        }
        cout << "\n";
    }

    return 0;
}