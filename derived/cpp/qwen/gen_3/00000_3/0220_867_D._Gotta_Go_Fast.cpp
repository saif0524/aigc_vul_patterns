#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const double EPS = 1e-9;

int n, R;
int F[MAXN], S[MAXN];
double P[MAXN];

double dp[MAXN][MAXN];

double solve(int level, int used) {
    if (used > R) return 1e18;
    if (level == n) return 0.0;
    double &ans = dp[level][used];
    if (ans > -0.5) return ans;
    ans = 1e18;
    double fastTime = F[level] + solve(level + 1, used + F[level]);
    double slowTime = S[level] + solve(level, used + S[level]);
    ans = min(ans, P[level] * fastTime + (100.0 - P[level]) * slowTime);
    ans = min(ans, R + 1 + solve(0, 0));
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> R;
    for(int i=0;i<n;i++){
        cin >> F[i] >> S[i] >> P[i];
        P[i] /= 100.0;
    }
    memset(dp, -1, sizeof(dp));
    cout << fixed << setprecision(9) << solve(0, 0) << "\n";
}