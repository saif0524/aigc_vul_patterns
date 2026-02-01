#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>
#include <cassert>
#include <functional>
#include <iomanip>
#include <bitset>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define sz(x) (int)(x).size()
#define endl '\n'

const int N = 7;
const int INF = 1e9 + 7;

int n;
int likes[N][N];
int exp[N];
int dp[1 << N][N][N];
int ans = INF, ans2 = 0;

void dfs(int mask, int a, int b) {
    if (mask == (1 << n) - 1) {
        int c = n - a - b;
        int x = exp[0] / a, y = exp[1] / b, z = exp[2] / c;
        int diff = max({x, y, z}) - min({x, y, z});
        if (diff < ans) {
            ans = diff;
            ans2 = dp[mask][a][b];
        } else if (diff == ans) {
            ans2 = max(ans2, dp[mask][a][b]);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int cnt = __builtin_popcount(mask);
            int new_mask = mask | (1 << i);
            int new_a = a + 1, new_b = b;
            if (new_a > n / 2) {
                new_a = a;
                new_b = b + 1;
            }
            dp[new_mask][new_a][new_b] = dp[mask][a][b];
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    dp[new_mask][new_a][new_b] += likes[i][j];
                }
            }
            dfs(new_mask, new_a, new_b);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;
        int p = -1, q = -1;
        if (s[0] == 'A') p = 0;
        else if (s[0] == 'C') p = 1;
        else if (s[0] == 'D') p = 2;
        else if (s[0] == 'H') p = 3;
        else if (s[0] == 'P') p = 4;
        else if (s[0] == 'S') p = 5;
        else p = 6;
        cin >> s >> s;
        if (s[0] == 'A') q = 0;
        else if (s[0] == 'C') q = 1;
        else if (s[0] == 'D') q = 2;
        else if (s[0] == 'H') q = 3;
        else if (s[0] == 'P') q = 4;
        else if (s[0] == 'S') q = 5;
        else q = 6;
        likes[p][q] = 1;
    }
    cin >> exp[0] >> exp[1] >> exp[2];
    dfs(0, 0, 0);
    cout << ans << " " << ans2 << endl;
    return 0;
}