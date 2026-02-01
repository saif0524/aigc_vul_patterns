#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

mt19937 gen(time(NULL));

long long ask(int i, long long x) {
	cout << "? " << i << " " << x << endl;
	long long res;
	cin >> res;
	return res;
}

int main() {
	int n;
	long long L;
	cin >> n >> L;

	vector<pair<long long, long long>> ans(n);

	for (int i = 0; i < n; i++) {
		long long l = 0, r = INF;
		while (r - l > 1) {
			long long m = (l + r) / 2;
			if (ask(i + 1, m) >= L / n)
				r = m;
			else
				l = m;
		}
		ans[i] = {l, r};
	}

	sort(ans.begin(), ans.end());

	for (int i = 1; i < n; i++) {
		if (ans[i].first <= ans[i - 1].second) {
			ans[i].first = ans[i - 1].second;
			ans[i].second = ans[i].first + L / n;
		}
	}

	cout << "!" << endl;
	for (auto& p : ans)
		cout << p.first << " " << p.second << endl;

	return 0;
}