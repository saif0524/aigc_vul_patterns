#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> vacants;
vector<int> selected;

bool dist(pair<int, int> a, pair<int, int> b) {
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return dx * dx + dy * dy >= 4;
}

void backtrack(int idx, int cnt) {
    if (cnt == K) {
        for (int i : selected) {
            cout << i + 1 << '\n';
        }
        exit(0);
    }
    if (idx == N) return;
    bool ok = true;
    for (int i : selected) {
        if (!dist(vacants[i], vacants[idx])) {
            ok = false;
            break;
        }
    }
    if (ok) {
        selected.push_back(idx);
        backtrack(idx + 1, cnt + 1);
        selected.pop_back();
    }
    backtrack(idx + 1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    vacants.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vacants[i].first >> vacants[i].second;
    }
    backtrack(0, 0);
    cout << -1 << '\n';
    return 0;
}