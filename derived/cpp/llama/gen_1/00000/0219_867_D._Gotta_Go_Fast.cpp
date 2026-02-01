#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1005;
const double EPS = 1e-9;

struct Node {
    double fastTime;
    double slowTime;
    double prob;
};

int N, R;
Node levels[MAXN];

double memo[MAXN][MAXN];

double dp(int level, int timeLeft) {
    if (level == N) {
        return 0.0;
    }

    if (memo[level][timeLeft] > -EPS) {
        return memo[level][timeLeft];
    }

    double fastTime = levels[level].fastTime;
    double slowTime = levels[level].slowTime;
    double prob = levels[level].prob / 100.0;

    double resetTime = dp(0, R);

    double contFast = fastTime + dp(level + 1, timeLeft - fastTime);
    double contSlow = slowTime + dp(level + 1, timeLeft - slowTime);

    double result = prob * contFast + (1.0 - prob) * min(contSlow, resetTime + slowTime);
    memo[level][timeLeft] = result;

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> R;

    for (int i = 0; i < N; ++i) {
        cin >> levels[i].fastTime >> levels[i].slowTime >> levels[i].prob;
    }

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            memo[i][j] = -1.0;
        }
    }

    double result = dp(0, R);
    cout.precision(15);
    cout << result << endl;

    return 0;
}