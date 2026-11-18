#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;

struct Node {
    ll sum;
    ll min_val;
    Node() : sum(0), min_val(INF) {}
};

Node combine(const Node &a, const Node &b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.min_val = min(a.min_val, b.min_val);
    return res;
}

int n;
ll k;
int f[MAXN];
ll w[MAXN];
Node dp[MAXN][65];

void preprocess() {
    for (int i = 0; i < n; ++i) {
        dp[i][0].sum = w[i];
        dp[i][0].min_val = w[i];
    }
    for (int j = 1; (1LL << j) <= k; ++j) {
        for (int i = 0; i < n; ++i) {
            int mid = f[dp[i][j-1].sum % n];
            dp[i][j] = combine(dp[i][j-1], dp[mid][j-1]);
        }
    }
}

Node query(int start, ll steps) {
    Node res;
    for (int j = 0; (1LL << j) <= steps; ++j) {
        if (steps & (1LL << j)) {
            res = combine(res, dp[start][j]);
            start = f[res.sum % n];
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> f[i];
    }
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    preprocess();
    for(int i=0;i<n;i++){
        Node ans = query(i, k);
        cout << ans.sum % n << " " << ans.min_val << "\n";
    }
    return 0;
}