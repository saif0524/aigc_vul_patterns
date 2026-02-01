#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int k) {
    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ((i == 0 && j == 0) ? '*' : '.');
            }
            cout << '\n';
        }
        return;
    }

    int total = n * m;
    if (k * 2 + 2 > total) {
        cout << -1;
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int index = i * m + j;
            if (index < k * 2 + 2) {
                if (index % 2 == 0) {
                    cout << '*';
                } else {
                    if (j + 1 < m) {
                        cout << '*';
                    } else {
                        cout << '.';
                    }
                }
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
        if(t) cout << '\n';
    }
}