#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct Matrix {
    vector<vector<int>> mat;
    int n, m;

    Matrix(int _n, int _m) : n(_n), m(_m) {
        mat.assign(n, vector<int>(m, 0));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(n, other.m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < other.m; j++) {
                for(int k = 0; k < m; k++) {
                    res.mat[i][j] = (res.mat[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix pow(long long p) const {
        Matrix res(n, n);
        Matrix base = *this;
        for(int i = 0; i < n; i++) {
            res.mat[i][i] = 1;
        }
        while(p > 0) {
            if(p & 1) {
                res = res * base;
            }
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for(auto& w : words) cin >> w;
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());
    n = words.size();
    set<string> all_prefixes;
    for(const auto& w : words) {
        for(int i = 1; i <= w.size(); i++) {
            all_prefixes.insert(w.substr(0, i));
        }
    }
    vector<int> prefix_id;
    prefix_id.assign(1 << 13, -1);
    int cnt = 0;
    for(auto& p : all_prefixes) {
        prefix_id[hash<string>{}(p) & ((1 << 13) - 1)] = cnt++;
    }
    vector<vector<int>> dp(1 << n, vector<int>(cnt, 0));
    for(int s = 0; s < (1 << n); s++) {
        for(int i = 0; i < n; i++) {
            if(s & (1 << i)) {
                dp[s][prefix_id[hash<string>{}(words[i]) & ((1 << 13) - 1)]]++;
            }
        }
    }
    Matrix trans(1 << n, 1 << n);
    for(int s = 0; s < (1 << n); s++) {
        for(int s2 = 0; s2 < (1 << n); s2++) {
            bool valid = true;
            for(int i = 0; i < n; i++) {
                if(s & (1 << i)) {
                    for(int j = 0; j < n; j++) {
                        if(s2 & (1 << j) && words[i].back() != words[j].front()) {
                            valid = false;
                            break;
                        }
                    }
                }
            }
            if(valid) {
                trans.mat[s][s2] = 1;
            }
        }
    }
    Matrix res = trans.pow(m);
    long long ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < (1 << n); j++) {
            ans = (ans + 1LL * res.mat[i][j] * res.mat[i][j]) % MOD;
        }
    }
    cout << ans << "\n";
}