#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> d(n + 1, 0);
    vector<ll> lazy(n + 1, 0);
    vector<pair<int, int>> queries;
    vector<int> query_types;
    vector<int> query_indices;
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 1) {
            int d;
            cin >> d;
            lazy[l] += d;
            lazy[r] -= d;
        } else {
            int x;
            cin >> x;
            queries.emplace_back(l, r);
            query_types.push_back(1);
            query_indices.push_back(i);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        d[i] += (i > 0 ? d[i - 1] : 0) + lazy[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 2) {
            int x;
            cin >> x;
            queries.emplace_back(l, r);
            query_types.push_back(2);
            query_indices.push_back(i);
        }
    }
    
    vector<int> res(m, -1);
    for (unsigned i = 0; i < queries.size(); ++i) {
        int l = queries[i].first;
        int r = queries[i].second;
        int type = query_types[i];
        ll max_val = LLONG_MIN;
        for (int j = l; j < r; ++j) {
            max_val = max(max_val, d[j]);
        }
        if (type == 1) {
            res[query_indices[i]] = (max_val <= 1e9 && max_val >= -1e9 ? 1 : 0);
        } else {
            ll val;
            cin >> val;
            res[query_indices[i]] = (max_val == val ? 1 : 0);
        }
    }
    
    for (int i : res) {
        if (i == 0) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << d[i] << (i < n - 1 ? ' ' : '\n');
    }
}