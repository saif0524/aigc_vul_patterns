#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<bool> used(n + 1, false);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (used[p[i]]) continue;
        int j = i;
        while (j < n && !used[p[j]]) {
            used[p[j]] = true;
            j++;
        }

        vector<int> seg;
        for (int l = i; l < j; l++) {
            seg.push_back(p[l]);
        }

        sort(seg.begin(), seg.end());

        int idx = i;
        for (int l = 0; l < seg.size(); l++) {
            while (idx < j && used[p[idx]]) idx++;
            ans[idx] = seg[l];
            idx++;
        }

        i = j - 1;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}