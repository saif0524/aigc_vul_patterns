#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> x(k);
    for(int &i : x) cin >> i;
    vector<int> a(l);
    for(int &i : a) cin >> i;

    vector<int> target(n+1, 0);
    for(int i : x) target[i] = 1;

    int ans = INT_MAX;
    auto valid = [&](const vector<int> &state) -> bool {
        for(int i = 1; i <= n; ++i) {
            if(state[i] != target[i]) return false;
        }
        return true;
    };

    vector<int> state(n+1, 0);
    auto flip = [&](int start, int size) -> void {
        for(int i = start; i < start + size; ++i) {
            if(i > n) break;
            state[i] ^= 1;
        }
    };

    function<void(int, int)> backtrack = [&](int pos, int moves) -> void {
        if(pos > n) {
            if(valid(state)) {
                ans = min(ans, moves);
            }
            return;
        }
        if(moves >= ans) return;
        backtrack(pos + 1, moves);
        for(int j = 0; j < l; ++j) {
            if(pos + a[j] - 1 > n) continue;
            flip(pos, a[j]);
            backtrack(pos + a[j], moves + 1);
            flip(pos, a[j]);
        }
    };

    backtrack(1, 0);
    if(ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
}