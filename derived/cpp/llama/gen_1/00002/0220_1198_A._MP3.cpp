#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;
int n, I, a[MAXN];
map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> I;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<pair<int, int>> v;
    for (auto& it : cnt) {
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end());

    int k = 8 * I / n;
    int K = pow(2, k);

    if (v.size() <= K) {
        cout << 0 << endl;
        return 0;
    }

    int ans = n;
    int l = 0, r = v.size() - K;
    for (int i = 0; i <= v.size() - K; ++i) {
        int sum = 0;
        for (int j = 0; j < l; ++j) {
            sum += v[j].second;
        }
        for (int j = r + 1; j < v.size(); ++j) {
            sum += v[j].second;
        }
        ans = min(ans, sum);
        l++, r++;
    }

    cout << ans << endl;

    return 0;
}