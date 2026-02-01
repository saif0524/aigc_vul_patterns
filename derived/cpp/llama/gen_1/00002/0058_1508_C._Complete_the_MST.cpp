#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pipii pair<int, pair<int, int>>
#define pipll pair<int, pair<ll, ll>>
#define ff first
#define ss second

const int MAXN = 2e5 + 10;

int n, m;
int fa[MAXN];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

struct edge {
	int x, y, w;
	bool operator< (const edge &e) const {
		return w < e.w;
	}
};

edge e[MAXN];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
 ll sum = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		e[i] = {x, y, w};
		 sum ^= w;
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		int x = e[i].x;
		int y = e[i].y;
		while (find(x) != find(y)) {
			if (rand() % 2) x = find(x);
			else y = find(y);
			fa[find(x)] = find(y);
			tot++;
			ans += e[i].w;
		}
	}
	if (tot == n - 1) {
		if (sum == 0) cout << ans << endl;
		else cout << ans + 1 << endl;
	} else {
		int mx = 0;
		for (int i = 1; i <= m; i++) {
			int x = e[i].x;
			int y = e[i].y;
			if (find(x) != find(y)) {
				mx = max(mx, e[i].w);
				fa[find(x)] = find(y);
				tot++;
				ans += e[i].w;
			}
		}
		if (sum == 0) cout << ans << endl;
		else cout << ans + 1 - mx << endl;
	}
}