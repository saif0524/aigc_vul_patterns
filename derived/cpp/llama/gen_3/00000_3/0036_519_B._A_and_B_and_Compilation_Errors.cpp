#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n - 1), c(n - 2);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;

    map<int, int> count;
    for (int x : a) count[x]++;
    for (int x : b) count[x]--;
    for (int x : c) count[x]--;

    vector<int> ans;
    for (auto& p : count) {
        if (p.second == 1) ans.push_back(p.first);
        else if (p.second == -1) ans.push_back(p.first);
    }

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}