#include <bits/stdc++.h>

using namespace std;

int dp[50010][26][26];

int main() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	memset(dp, 0, sizeof(dp));
	dp[0][s[0] - 'a'][s.back() - 'a'] = s.length();
	for (int i = 1; i < n; i++) {
		cin >> s;
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				if (dp[i - 1][j][k]) {
					if (j == s[0] - 'a') {
						dp[i][j][s.back() - 'a'] = max(dp[i][j][s.back() - 'a'], dp[i - 1][j][k] + s.length());
					}
					if (k == s.back() - 'a') {
						dp[i][s[0] - 'a'][k] = max(dp[i][s[0] - 'a'][k], dp[i - 1][j][k] + s.length());
					}
				}
			}
		}
		dp[i][s[0] - 'a'][s.back() - 'a'] = max(dp[i][s[0] - 'a'][s.back() - 'a'], s.length());
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = max(ans, dp[n - 1][i][i]);
	}
	cout << ans << endl;
	return 0;
}