#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <map>
using namespace std;

#define ll long long
#define ld long double
#define x first
#define y second
const int N = 2e5 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> h(n);
	for (auto& it : h)
		cin >> it;

	vector<vector<int>> g(n);
	vector<vector<int>> gr(n);
	vector<int> in_degree(n, 0);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		gr[v].push_back(u);
		in_degree[v]++;
	}

	vector<int> color(n, -1);
	for (int i = 0; i < n; ++i) {
		for (auto to : g[i])
			color[to] = 1 - color[i];
	}

	vector<int> cnt(2, 0);
	for (int i = 0; i < n; ++i)
		cnt[color[i]]++;

	if (1 < cnt[0] + cnt[1] - n)
		cnt[0] = cnt[1] = 0;

	if (cnt[0] < cnt[1])
		swap(cnt[0], cnt[1]);

	priority_queue<int, vector<int>, greater<int>> colors;
	for (int i = 0; i < 2; ++i)
		if (cnt[i])
			colors.push(i);

	for (int v = 0; v < n; ++v) {
		if (in_degree[v] == 0 && color[v] == colors.top()) {
			colors.pop();
			vector<bool> visit(n, 0);
			visit[v] = 1;

			queue<int> q;
			q.push(v);
			while (!q.empty()) {
				int to = q.front();
				q.pop();

				h[to] = 0;
				for (auto next : gr[to]) {
					if (!visit[next]) {
						visit[next] = 1;
						q.push(next);
					}
				}
			}
			cout << "WIN\n";
			for (int i = 0; i < n; ++i)
				cout << h[i] << ' ';
			cout << "\n";
			return 0;
		}
	}
	cout << "LOSE\n";

	return 0;
}