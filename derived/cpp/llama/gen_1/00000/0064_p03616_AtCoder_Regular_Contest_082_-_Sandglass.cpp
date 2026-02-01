#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, K, Q;
	cin >> X;
	cin >> K;
	vector<int> r(K);
	for (int i = 0; i < K; i++)
		cin >> r[i];
	cin >> Q;
	vector<int> t(Q), a(Q), ans(Q);
	for (int i = 0; i < Q; i++) {
		cin >> t[i] >> a[i];
	}
	for (int i = 0; i < Q; i++) {
		int rem = t[i];
		int sand = a[i];
		int j = 0;
		while (j < K && r[j] <= rem) {
			int b = X - sand;
			if (sand > b)
				sand -= (r[j] - (j > 0 ? r[j-1] : 0));
			else
				sand = X - (b - (r[j] - (j > 0 ? r[j-1] : 0)));
			rem -= (r[j] - (j > 0 ? r[j-1] : 0));
			j++;
		}
		if (j % 2 == 1) {
			sand = max(0, sand - rem);
		} else {
			sand = X - max(0, (X - sand) - rem);
		}
		cout << sand << endl;
	}
	return 0;
}