#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const double EPS = 1e-9;

int N, R;
int F[MAXN], S[MAXN];
double P[MAXN];

double memo[MAXN][MAXN * 100 + 1];

double dp(int level, int time_used) {
    if (time_used > R) return 1e9;
    if (level == N) return 0.0;
    double &res = memo[level][time_used];
    if (res > -0.5) return res;
    double p = P[level] / 100.0;
    res = min(
        F[level] + p * dp(level + 1, time_used + F[level]) + (1 - p) * (S[level] - F[level] + dp(level, time_used + S[level])),
        dp(0, 0) + time_used
    );
    return res;
}

int main(){
    cin >> N >> R;
    for(int i = 0; i < N; i++){
        cin >> F[i] >> S[i] >> P[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << fixed << setprecision(10) << dp(0, 0) << endl;
}