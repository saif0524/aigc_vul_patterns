#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N = 100005;
const int MOD = (1LL << 58);
const int MAX_DIG = 5;

int n;
int x[N];
int digits[MAX_DIG];
int count_digits[N][MAX_DIG];

void add_mod(ull &a, ull b) {
    a = (a + b) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
        int temp = x[i], pos = 0;
        if(temp == 0){
            ++count_digits[i][0];
        }
        while(temp){
            ++count_digits[i][pos++];
            temp /= 10;
        }
    }
    ull dp[10][n];
    memset(dp, 0, sizeof(dp));
    for(int d=0; d<10; d++){
        dp[d][0] = count_digits[0][d];
    }
    for(int j=1; j<n; j++){
        ull prefix_sum[10];
        memset(prefix_sum, 0, sizeof(prefix_sum));
        prefix_sum[0] = dp[0][j-1];
        for(int d=1; d<10; d++){
            prefix_sum[d] = (prefix_sum[d-1] + dp[d][j-1]) % MOD;
        }
        for(int d=0; d<10; d++){
            int c = count_digits[j][d];
            if(c == 0){
                dp[d][j] = 0;
                continue;
            }
            int target = (10-d) % 10;
            ull ways = prefix_sum[target];
            if(d > 0){
                ways = (ways - dp[target][j-1] + MOD) % MOD;
            }
            dp[d][j] = (ways * c) % MOD;
        }
    }
    ull ans[n];
    for(int i=0; i<n; i++){
        ans[i] = 0;
    }
    for(int i=0; i<n; i++){
        ull total_ways = 1;
        for(int k=0; k<MAX_DIG; k++){
            total_ways = (total_ways * dp[digits[k]][n-1]) % MOD;
        }
        add_mod(ans[digits[0]], total_ways);
        bool done = false;
        for(int k=0; k<MAX_DIG && !done; k++){
            int d = digits[k];
            if(d > 0){
                done = true;
                --digits[k];
                for(int j=k+1; j<MAX_DIG; j++){
                    digits[j] = 9;
                }
                total_ways = 1;
                for(int k=0; k<MAX_DIG; k++){
                    total_ways = (total_ways * dp[digits[k]][n-1]) % MOD;
                }
                add_mod(ans[digits[0]], total_ways);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i];
        if(i < n-1){
            cout << " ";
        }else{
            cout << "\n";
        }
    }
    return 0;
}