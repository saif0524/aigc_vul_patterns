#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	map<int, vector<int>> forward;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		forward[u].push_back(v);
	}
	int moves = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (find(forward[p[i + 1]].begin(), forward[p[i + 1]].end(), p[i]) != forward[p[i + 1]].end()) {
			moves++;
		}
		else {
			break;
		}
	}
	cout << moves << endl;
	return 0;
}