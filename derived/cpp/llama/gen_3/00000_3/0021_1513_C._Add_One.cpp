#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string n;
		int m;
		cin >> n >> m;
		long long len = 0;
		for (char d : n) {
			int num = d - '0';
			int cnt = 0;
			for (int i = 0; i < m; i++) {
				num = (num + 1) % 10;
				if (num == 0) cnt++;
			}
			len = (len + cnt + 1) % MOD;
		}
		cout << len << "\n";
	}
	return 0;
}