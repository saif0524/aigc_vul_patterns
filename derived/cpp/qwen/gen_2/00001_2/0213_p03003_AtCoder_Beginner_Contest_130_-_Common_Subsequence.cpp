#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for(auto& x : S) cin >> x;
    for(auto& x : T) cin >> x;

    unordered_map<int, vector<int>> idxS, idxT;
    for(int i = 0; i < N; i++) idxS[S[i]].push_back(i);
    for(int i = 0; i < M; i++) idxT[T[i]].push_back(i);

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    dp[0][0] = 1;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i < N) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if(j < M) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            if(i < N && j < M && S[i] == T[j]){
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            ans = (ans + dp[i][j]) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}