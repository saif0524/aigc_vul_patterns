#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
bool vis[200005];
int n, m, a, b;

void dfs(int x, int p) {
	vis[x] = true;
	for (int y : g[x]) {
		if (y != p && !vis[y]) {
			dfs(y, x);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		memset(vis, 0, sizeof(vis));
		dfs(a, -1);
		int va = 0, vb = 0;
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && !vis[i]) {
				va++;
			}
		}
		memset(vis, 0, sizeof(vis));
		dfs(b, -1);
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b && !vis[i]) {
				vb++;
			}
		}
		printf("%d\n", va * vb);
	}
	return 0;
}