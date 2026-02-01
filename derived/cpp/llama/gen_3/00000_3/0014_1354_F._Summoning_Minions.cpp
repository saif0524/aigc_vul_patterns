#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 85;
int T, n, k;
int a[maxn], b[maxn];
int f[maxn][maxn], pre[maxn][maxn];
int maxv, id;

void print(int x, int y) {
	if (x == 0) return;
	if (pre[x][y] == -1) {
		cout << y << ' ';
		print(x - 1, y);
	} else {
		print(x - 1, pre[x][y]);
		cout << -pre[x][y] << ' ' << y << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				f[i][j] = f[i - 1][j];
				pre[i][j] = -1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				for (int l = 1; l <= j; l++) {
					int t = f[i - 1][j - l] + (j - 1) * b[i] + a[i];
					if (t > f[i][j]) {
						f[i][j] = t;
						pre[i][j] = l;
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (f[i][j] > f[id][maxv]) {
					maxv = j;
					id = i;
				}
			}
		}
		cout << k + (id - maxv) << '\n';
		print(id, maxv);
		cout << '\n';
		maxv = id = 0;
	}

	return 0;
}