#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;
vector<int> g[MAXN];
int n, sz[MAXN], ans[MAXN];

void dfs(int v, int p) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0);
		int cnt = 0;
		for (int u : g[i]) {
			if (sz[u] > n / 2) cnt++;
		}
		if (cnt <= 1) ans[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		for (int u : g[i]) {
			for (int v : g[u]) {
				if (v == i) continue;
				sz[v] = 1;
				for (int x : g[v]) {
					if (x == u) continue;
					dfs(x, v);
					sz[v] += sz[x];
				}
				int cnt = 0;
				for (int x : g[v]) {
					if (x == u) continue;
					if (sz[x] > n / 2) cnt++;
				}
				if (cnt <= 1) {
					ans[i] = 1;
					break;
				}
			}
			if (ans[i]) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << ' ';
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}