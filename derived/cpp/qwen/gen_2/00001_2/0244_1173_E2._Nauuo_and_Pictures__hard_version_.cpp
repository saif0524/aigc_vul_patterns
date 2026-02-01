#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll modPow(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) res = res * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return res;
}

ll modInv(ll x) {
    return modPow(x, MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<ll> w(n);
    for(auto &x: w) cin >> x;
    vector<ll> like, dislike;
    ll totalWeight = 0;
    for(int i = 0; i < n; i++){
        totalWeight += w[i];
        if(a[i]) like.push_back(w[i]);
        else dislike.push_back(w[i]);
    }
    ll likeSum = accumulate(like.begin(), like.end(), 0LL);
    ll dislikeSum = accumulate(dislike.begin(), dislike.end(), 0LL);
    vector<pair<ll, ll>> likeProb, dislikeProb;
    for(auto &x: like){
        ll p = x * modInv(totalWeight) % MOD;
        likeProb.push_back({p, likeSum - x});
    }
    for(auto &x: dislike){
        ll p = x * modInv(totalWeight) % MOD;
        dislikeProb.push_back({p, dislikeSum - x});
    }
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < m; i++){
        vector<ll> ndp(m + 1, 0);
        for(int j = 0; j <= i; j++){
            ndp[j] = (ndp[j] + dp[j] * (dislikeProb.size() ? (totalWeight - likeSum) * modInv(totalWeight) % MOD : 0)) % MOD;
            if(j + 1 <= i + 1) ndp[j + 1] = (ndp[j + 1] + dp[j] * (totalWeight - dislikeSum) * modInv(totalWeight) % MOD) % MOD;
        }
        dp = ndp;
    }
    vector<ll> likeExp(n, 0), dislikeExp(n, 0);
    for(int i = 0; i < like.size(); i++){
        for(int j = 0; j <= m; j++){
            likeExp[i] = (likeExp[i] + likeProb[i].first * dp[j] % MOD * (j + likeProb[i].second) % MOD) % MOD;
        }
    }
    for(int i = 0; i < dislike.size(); i++){
        for(int j = 0; j <= m; j++){
            dislikeExp[i] = (dislikeExp[i] + dislikeProb[i].first * dp[j] % MOD * (j - dislikeProb[i].second) % MOD) % MOD;
        }
    }
    vector<ll> res(n, 0);
    int likeIdx = 0, dislikeIdx = 0;
    for(int i = 0; i < n; i++){
        if(a[i]) res[i] = likeExp[likeIdx++];
        else res[i] = dislikeExp[dislikeIdx++];
    }
    for(auto &x: res) cout << x << " ";
    cout << "\n";
}