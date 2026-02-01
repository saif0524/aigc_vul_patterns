#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define pb push_back

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int k, n, m;
		cin >> k >> n >> m;

		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		int i = 0, j = 0;
		vector<int> ans;
		while (i < n || j < m) {
			if (i < n && a[i] == 0) {
				ans.pb(a[i]);
				k++;
				i++;
			} else if (j < m && b[j] == 0) {
				ans.pb(b[j]);
				k++;
				j++;
			} else if (i < n && a[i] <= k) {
				ans.pb(a[i]);
				i++;
			} else if (j < m && b[j] <= k) {
				ans.pb(b[j]);
				j++;
			} else {
				cout << -1 << endl;
				goto next;
			}
		}

		for (int x : ans) cout << x << " ";
		cout << endl;

next:
		continue;
	}

	return 0;
}