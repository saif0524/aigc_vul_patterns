#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> words;
string ans;
int n, m;
ll K;

bool possible(ll len) {
    static vector<ll> dp(2020, 0);
    dp[0] = 1;
    for (int i = 1; i <= len; ++i) {
        dp[i] = 0;
        for (auto &w : words) {
            if (i >= (int)w.size()) {
                dp[i] += dp[i - (int)w.size()];
            }
        }
    }
    return dp[len] >= K;
}

void construct(int len) {
    if (len == 0) return;
    ll cnt = 0;
    for (auto &w : words) {
        if (len >= (int)w.size()) {
            cnt += possible(len - (int)w.size());
            if (cnt >= K) {
                ans += w;
                construct(len - (int)w.size());
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> K;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    sort(words.begin(), words.end());
    if(possible(m)){
        construct(m);
        cout << ans;
    }else{
        cout << "-";
    }
}