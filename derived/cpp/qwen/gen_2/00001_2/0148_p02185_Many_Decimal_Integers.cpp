#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    string S, T;
    cin >> S >> T;
    int n = S.size();
    long long dp[2][2][200005] = {0};
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int eq=0;eq<2;eq++){
            for(int gt=0;gt<2;gt++){
                if(dp[eq][gt][i] == 0) continue;
                for(int digit=0;digit<10;digit++){
                    bool new_eq = eq && (digit == (S[i]-'0'));
                    bool new_gt = gt || (eq && (digit > (S[i]-'0')));
                    if(T[i] == '?' || T[i] == ('0'+digit)){
                        dp[new_eq][new_gt][i+1] = (dp[new_eq][new_gt][i+1] + dp[eq][gt][i]) % MOD;
                    }
                }
            }
        }
    }
    long long sum = 0;
    for(int eq=0;eq<2;eq++){
        for(int gt=0;gt<2;gt++){
            if(eq || gt){
                long long val = 0, mul = 1;
                for(int i=n-1;i>=0;i--){
                    val = (val + (dp[eq][gt][i+1] * mul) % MOD) % MOD;
                    mul = (mul * 10) % MOD;
                }
                sum = (sum + val) % MOD;
            }
        }
    }
    cout << sum;
}