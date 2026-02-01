#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <fstream>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define graph vector<vi>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define INF (int)1e9
#define MOD 1000000007

ll c[10001];
ll dp[2001][2001];
ll cost[2001];
ll lvl[2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	rep(i, 1, n + 1) cin >> lvl[i];
	rep(i, 1, n + 1) cin >> cost[i];
	rep(i, 1, m + n + 1) cin >> c[i];

	c[0] = 0;

	memset(dp, -63, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j > 0 && lvl[i] >= lvl[j]) continue;

			for (int k = 0; k < i; k++) {
				if (dp[i][j] < dp[k][j] + c[lvl[i]] - cost[i]) {
					dp[i][j] = dp[k][j] + c[lvl[i]] - cost[i];
				}
			}

			if (i > 1 && lvl[i] == lvl[i - 1]) {
				for (int k = 0; k < i - 1; k++) {
					if (dp[i][j] < dp[k][j] + c[lvl[i]] + c[lvl[i] + 1] - cost[i]) {
						dp[i][j] = dp[k][j] + c[lvl[i]] + c[lvl[i] + 1] - cost[i];
					}
				}
			}
		}
	}

	ll ans = dp[n][0];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]);
	}

	cout << ans << '\n';

	return 0;
}