#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int MAXM = 200005;

vector<int> g[MAXN], r[MAXN], vg[MAXM], vr[MAXM];
int n, m, a[MAXM], b[MAXM], vis[MAXN], scc[MAXN], s, tot, cnt, c[MAXN], d[MAXN], id[MAXN];
stack<int> st;

void dfs1(int x) {
	vis[x] = 1;
	for (int y : g[x]) {
		if (!vis[y]) dfs1(y);
	}
	st.push(x);
}

void dfs2(int x, int num) {
	scc[x] = num;
	vis[x] = 0;
	for (int y : r[x]) {
		if (vis[y]) dfs2(y, num);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]);
		r[b[i]].push_back(a[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}

	while (!st.empty()) {
		int x = st.top();
		st.pop();
		if (vis[x]) {
			s++;
			dfs2(x, s);
		}
	}

	for (int i = 1; i <= m; i++) {
		vg[i].push_back(a[i]);
		vg[i].push_back(b[i]);
		vr[i].push_back(b[i]);
		vr[i].push_back(a[i]);
	}

	for (int i = 1; i <= m; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			c[j] = scc[j];
			d[j] = vis[j] = 0;
			id[j] = j;
		}
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				dfs1(j);
			}
		}
		while (!st.empty()) {
			int x = st.top();
			st.pop();
			if (vis[x]) {
				cnt++;
				dfs2(x, cnt);
			}
		}
		if (cnt != s) {
			cout << "diff\n";
		} else {
			bool flag = false;
			sort(vg[i].begin(), vg[i].end());
			sort(vr[i].begin(), vr[i].end());
			if (vg[i].front() == vr[i].front() && vg[i].back() == vr[i].back()) {
				for (int j = 1; j <= n; j++) {
					if (c[a[i]] == c[j] && c[b[i]] == c[j]) {
						flag = true;
						break;
					}
				}
				if (flag) {
					cout << "same\n";
				} else {
					cout << "diff\n";
				}
			} else {
				cout << "same\n";
			}
		}
	}

	return 0;
}