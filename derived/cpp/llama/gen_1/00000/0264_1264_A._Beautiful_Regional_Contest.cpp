#include <bits/stdc++.h>
using namespace std;

int t, n;
int p[400009];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int g = 1;
		while (g < n && p[g] == p[g - 1]) g++;
		int s = g + 1;
		while (s < n && p[s] == p[s - 1]) s++;
		int b = s + 1;
		while (b < n && p[b] == p[b - 1]) b++;
		while (b < n && p[b] == p[b - 1]) b++;
		if (g >= s || g >= b || g + s + b > n / 2) {
			cout << "0 0 0\n";
			continue;
		}
		int max_b = n / 2 - g - s;
		while (b + max_b < n && p[b + max_b] == p[b + max_b - 1]) max_b--;
		cout << g << ' ' << s - g << ' ' << b - s << '\n';
	}
	return 0;
}