#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
long long d[MAXN], h[MAXN], sumd;
vector<pair<long long, int>> v;

long long dist(int x, int y) {
    if (x <= y) return sumd - sumd * (y - x) / n;
    return sumd * (n - y + x) / n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        sumd += d[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    for (int i = 0; i < n; ++i) {
        v.push_back({h[i], i});
    }

    sort(v.begin(), v.end(), greater<pair<long long, int>>());

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        if (a <= b) {
            v.erase(remove_if(v.begin(), v.end(), [a, b](const pair<long long, int>& x) {
                return a <= x.second && x.second <= b;
            }), v.end());
        } else {
            v.erase(remove_if(v.begin(), v.end(), [a, b](const pair<long long, int>& x) {
                return (x.second >= a && x.second < n) || (x.second <= b);
            }), v.end());
        }

        long long ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                long long tmp = 2 * (v[i].first + v[j].first) + dist(v[i].second, v[j].second);
                ans = max(ans, tmp);
            }
        }

        cout << ans << '\n';

        v.clear();
        for (int i = 0; i < n; ++i) {
            v.push_back({h[i], i});
        }
        sort(v.begin(), v.end(), greater<pair<long long, int>>());
    }

    return 0;
}