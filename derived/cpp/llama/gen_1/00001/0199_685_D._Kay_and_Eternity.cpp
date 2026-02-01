#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 1e9;

int n, k;
pi p[100002];
pi l[100002], r[100002];
bool done[100002];

int count_squares(int i, int x) {
	int ret = 0;
	for (int j = 1; j <= n; j++) {
		int a = max(l[j].first, p[i].first);
		int b = min(r[j].first, p[i].first + k - 1);
		int c = max(l[j].second, p[i].second);
		int d = min(r[j].second, p[i].second + k - 1);
		if (b < a || d < c) continue;
		int cnt = 0;
		for (int t = 1; t <= n; t++) {
			if (a <= p[t].first && p[t].first <= b && c <= p[t].second && p[t].second <= d) cnt++;
		}
		if (cnt == x) ret++;
	}
	return ret;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].first >> p[i].second;
		l[i] = make_pair(p[i].first - k + 1, p[i].second - k + 1);
		r[i] = make_pair(p[i].first, p[i].second);
		done[i] = false;
	}

	for (int y = -INF; y <= INF; y += k) {
		for (int i = 1; i <= n; i++) {
			if (done[i] || p[i].second != y + k - 1) continue;
			for (int j = i + 1; j <= n; j++) {
				if (p[j].second == y && p[j].first == p[i].first) {
					done[j] = true;
					r[i].second = p[j].second;
				}
			}
		}
	}

	for (int y = -INF; y <= INF; y += k) {
		for (int i = 1; i <= n; i++) {
			if (done[i] || p[i].second != y) continue;
			for (int j = i + 1; j <= n; j++) {
				if (p[j].second == y + k - 1 && p[j].first == p[i].first) {
					done[j] = true;
					l[i].second = p[j].second - k + 1;
				}
			}
		}
	}

	vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= n; x++) {
			cnt[x] += count_squares(i, x);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TT = 1;
	while (TT--) {
		solve();
	}
}