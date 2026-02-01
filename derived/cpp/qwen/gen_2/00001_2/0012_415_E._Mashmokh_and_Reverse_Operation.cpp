#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT {
    int sz;
    vector<ll> data;

    BIT(int n) : sz(n), data(n + 1) {}

    void add(int idx, ll val) {
        for (++idx; idx <= sz; idx += idx & -idx)
            data[idx] += val;
    }

    ll query(int idx) {
        ll res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += data[idx];
        return res;
    }
};

int main(){
    int n;
    scanf("%d", &n);
    int len = (1 << n);
    vector<int> a(len);
    for(int &x : a) scanf("%d", &x);
    int m;
    scanf("%d", &m);
    vector<int> q(m);
    for(int &x : q) scanf("%d", &x);
    reverse(q.begin(), q.end());
    vector<int> pos(len);
    for(int i = 0; i < len; ++i){
        pos[a[i]] = i;
    }
    BIT bit(len + 1);
    for(int i = 0; i < len; ++i){
        bit.add(pos[i], 1);
    }
    ll inversions = 0;
    for(int i = 1; i < len; ++i){
        inversions += i - bit.query(pos[i]);
    }
    vector<ll> ans(m);
    for(int i = 0; i < m; ++i){
        ans[i] = inversions;
        int split = (1 << (n - q[i]));
        vector<int> new_a(len);
        for(int j = 0; j < split; ++j){
            reverse(a.begin() + j * split, a.begin() + (j + 1) * split);
        }
        for(int j = 0; j < len; ++j){
            bit.add(pos[a[j]], -1);
            inversions -= len - 1 - pos[a[j]] - bit.query(pos[a[j]]);
            pos[a[j]] = j;
            inversions += pos[a[j]] - bit.query(pos[a[j]]);
            bit.add(pos[a[j]], 1);
        }
    }
    for(int i = m - 1; i >= 0; --i){
        printf("%lld\n", ans[i]);
    }
}