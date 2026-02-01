#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
long long l[MAXN], r[MAXN];
vector<long long> points;
map<long long, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        points.push_back(l[i]);
        points.push_back(r[i] + 1);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    for (int i = 0; i < points.size(); i++) {
        mp[points[i]] = i;
    }

    vector<int> cnt(points.size(), 0);
    for (int i = 0; i < n; i++) {
        int left = mp[l[i]];
        int right = mp[r[i] + 1];
        for (int j = left; j < right; j++) {
            cnt[j]++;
        }
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] > 0 && cnt[i] <= n) {
            ans[cnt[i] - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}