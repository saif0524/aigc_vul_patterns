#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct FastMatrix {
    ll mat[2][2];
    FastMatrix() {
        memset(mat, 0, sizeof mat);
    }
    FastMatrix(ll a, ll b, ll c, ll d) {
        mat[0][0] = a; mat[0][1] = b;
        mat[1][0] = c; mat[1][1] = d;
    }
    FastMatrix operator * (FastMatrix o) {
        FastMatrix res(0, 0, 0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] = min(res.mat[i][j], mat[i][k] + o.mat[k][j]);
                }
            }
        }
        res.mat[0][1] = min(res.mat[0][1], mat[0][0] + mat[0][1]);
        res.mat[1][0] = min(res.mat[1][0], mat[1][1] + mat[1][0]);
        res.mat[1][1] = min(res.mat[1][1], mat[1][0] + mat[1][1]);
        res.mat[0][0] = min(res.mat[0][0], mat[0][1] + mat[1][0]);
        res.mat[0][0] = min(res.mat[0][0], mat[0][0] + mat[1][1] + mat[1][0]);
        res.mat[0][0] = min(res.mat[0][0], mat[0][1] + mat[1][1] + mat[0][0]);
        return res;
    }
};

FastMatrix fpow(FastMatrix base, ll exp) {
    FastMatrix res(0, 0, 0, 0);
    res.mat[0][0] = res.mat[1][1] = 1;
    while (exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<int> f(n);
    vector<ll> w(n);
    for(auto &x: f) cin >> x;
    for(auto &x: w) cin >> x;
    vector<FastMatrix> cycle(n);
    for(int i = 0; i < n; i++){
        if(cycle[i].mat[0][0] != 0) continue;
        int now = i;
        vector<int> cyc;
        vector<ll> cycw;
        do{
            cyc.push_back(now);
            cycw.push_back(w[now]);
            now = f[now];
        }while(now != i);
        int sz = cyc.size();
        FastMatrix c(0, 0, 0, 0);
        for(int j = 0; j < sz; j++){
            c.mat[0][1] = min(c.mat[0][1], cycw[j]);
            c.mat[1][1] = min(c.mat[1][1], cycw[(j+1)%sz]);
        }
        for(int j = 0; j < sz; j++){
            c = c * c;
            cycle[cyc[j]] = c;
        }
    }
    for(int i = 0; i < n; i++){
        ll add = 0;
        int now = i;
        for(int j = 62; j >= 0; j--){
            if(k >> j & 1){
                add += w[now];
                now = f[now];
            }
        }
        FastMatrix ans = cycle[i];
        ll s = ans.mat[0][0] + add;
        ll m = ans.mat[0][1];
        cout << s << " " << m << "\n";
    }
}