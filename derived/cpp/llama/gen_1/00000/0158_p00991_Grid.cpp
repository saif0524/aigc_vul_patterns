#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int MOD = 100000007;
const int MAX_R = 1000;
const int MAX_C = 1000;
const int MAX_DIST = MAX_R * MAX_C;

int r, c, a1, a2, b1, b2;
int memo[MAX_R * 2][MAX_C * 2];

int dp(int x, int y) {
    if (x < 0 || x >= 2 * r || y < 0 || y >= 2 * c) return 0;
    x %= r;
    y %= c;
    if (x == b1 && y == b2) return 1;
    if (memo[x][y] != -1) return memo[x][y];
    int& res = memo[x][y];
    res = 0;
    res += dp(x + 1, y);
    res += dp(x - 1, y);
    res += dp(x, y + 1);
    res += dp(x, y - 1);
    res %= MOD;
    return res;
}

int solve() {
    memset(memo, -1, sizeof(memo));
    return dp(a1, a2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;
    cout << solve() << endl;
    return 0;
}