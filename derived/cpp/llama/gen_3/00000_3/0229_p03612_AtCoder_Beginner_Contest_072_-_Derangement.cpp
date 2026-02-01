#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    vector<int> cycle;
    vector<bool> used(N, false);

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        cycle.clear();
        int now = i;
        while (!used[now]) {
            cycle.push_back(now);
            used[now] = true;
            now = P[now];
        }

        if (cycle.size() == 2 && cycle[0] + 1 == cycle[1] + 1) {
            cout << 1 << endl;
            return;
        }
    }

    vector<int> A(N, -1);
    for (int i = 0; i < N; i++) {
        A[P[i]] = i;
    }

    vector<int> pos;
    for (int i = 0; i < N; i++) {
        if (A[i] == i) {
            pos.push_back(i);
        }
    }

    sort(pos.begin(), pos.end());

    int x = pos.size();
    int ans = (x + 1) / 2;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}