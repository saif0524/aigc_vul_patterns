#include <bits/stdc++.h>
using namespace std;

long long dp[101][4][2];

long long countNumbers(string &num, int pos, int nonZeroCount, int tight) {
    if (pos == num.size()) return nonZeroCount == 0;
    if (dp[pos][nonZeroCount][tight] != -1) return dp[pos][nonZeroCount][tight];
    long long limit = tight ? (num[pos] - '0') : 9;
    long long ans = 0;
    for (int it = 0; it <= limit; it++) {
        ans += countNumbers(num, pos + 1, nonZeroCount - (it > 0), tight && (it == limit));
    }
    return dp[pos][nonZeroCount][tight] = ans;
}

int main(){
    string N;
    int K;
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    long long total = countNumbers(N, 0, K, 1);
    long long invalid = 0;
    for(int i = 1; i < K; ++i){
        memset(dp, -1, sizeof(dp));
        invalid += countNumbers(N, 0, i, 1);
    }
    cout << total - invalid;
}