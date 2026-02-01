#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dists;
vector<int> current;
vector<vector<int>> results;

bool check() {
    for (int i = 0; i < n; ++i) {
        set<int> s;
        for (int j = i + 1; j < n; ++j) {
            int sum = 0;
            for (int k = i; k < j; ++k) {
                sum += current[k - i];
            }
            s.insert(sum);
        }
        if (s.size() != (n - 1 - i)) return false;
    }
    return true;
}

void backtrack(int idx) {
    if (idx == n - 1) {
        if (check()) {
            results.push_back(current);
        }
        return;
    }
    set<int> used;
    for (int i = 0; i < dists.size(); ++i) {
        if (used.find(dists[i]) != used.end()) continue;
        used.insert(dists[i]);
        current[idx] = dists[i];
        backtrack(idx + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        if (n == 0) break;
        dists.clear();
        results.clear();
        current.assign(n - 1, 0);
        for (int i = 0; i < n * (n - 1) / 2; ++i) {
            int x;
            cin >> x;
            dists.push_back(x);
        }
        backtrack(0);
        sort(results.begin(), results.end());
        for (const auto& res : results) {
            for (int i = 0; i < res.size(); ++i) {
                if (i > 0) cout << ' ';
                cout << res[i];
            }
            cout << '\n';
        }
        cout << "-----\n";
    }
    return 0;
}