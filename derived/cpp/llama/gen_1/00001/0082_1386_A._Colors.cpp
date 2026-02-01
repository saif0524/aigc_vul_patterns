#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N;
    cin >> N;
    long long low = 1;
    long long high = N;
    vector<bool> used(N + 1);
    long long color = 1;
    used[color] = true;
    cout << "? " << color << endl;
    cin.ignore();
    while (low < high) {
        long long mid = (high + low) / 2;
        long long next = color + mid;
        if (next >= 1 && next <= N && !used[next]) {
            cout << "? " << next << endl;
            used[next] = true;
            int ans;
            cin >> ans;
            cin.ignore();
            if (ans == 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
            color = next;
        } else {
            next = color - mid;
            if (next >= 1 && next <= N && !used[next]) {
                cout << "? " << next << endl;
                used[next] = true;
                int ans;
                cin >> ans;
                cin.ignore();
                if (ans == 0) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
                color = next;
            } else {
                for (int i = 1; i <= N; i++) {
                    if (!used[i]) {
                        next = i;
                        break;
                    }
                }
                cout << "? " << next << endl;
                used[next] = true;
                color = next;
                cin.ignore();
            }
        }
    }
    cout << "= " << low << endl;
}

int! main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}