#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 2005;

int n, d[N][N], id[N];
vector<int> e[N];

void query(int x) {
    cout << "? " << x << endl;
    for (int i = 1; i <= n; i++) {
        cin >> d[x][i];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        id[i] = i;
    }
    for (int i = 1; i <= (n + 1) / 2; i++) {
        int x = id[1];
        query(x);
        for (int j = 2; j <= n; j++) {
            if (d[x][id[j]] < d[x][id[1]]) {
                swap(id[1], id[j]);
            }
        }
        for (int j = 2; j <= n; j++) {
            swap(id[j], id[j + 1]);
        }
    }
    cout << "!" << endl;
    for (int i = 1; i < n; i++) {
        cout << id[i] << " " << id[i + 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}