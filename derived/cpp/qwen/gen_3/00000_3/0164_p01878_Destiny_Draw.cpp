#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 41;
const int MAXT = 1000005;

int N, K, C, T;
struct Operation {
    int a, b, t;
} ops[MAXN];

ll dp[MAXN][MAXT];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> C >> T;
    for(int i=0;i<K;i++){
        cin >> ops[i].a >> ops[i].b >> ops[i].t;
        ops[i].a--;
    }
    dp[0][0] = 1;
    for(int t=0;t<T;t++){
        for(int j=0;j<N;j++){
            if(dp[j][t] == 0) continue;
            for(int i=0;i<K;i++){
                if(t + ops[i].t <= T){
                    int new_position = j;
                    if(ops[i].a <= j && j < ops[i].a + ops[i].b){
                        new_position = ops[i].a + ops[i].b - 1 - (j - ops[i].a);
                    }
                    dp[new_position][t + ops[i].t] = (dp[new_position][t + ops[i].t] + dp[j][t]) % MOD;
                }
            }
        }
    }
    cout << dp[C-1][T] << "\n";
}