#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = n;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				string sub = s.substr(i, j - i + 1);
				bool good = true;
				while (sub.size() > 1) {
					bool changed = false;
					for (int k = 0; k < sub.size(); k++) {
						if (sub[k] == '>') {
							if (k < sub.size() - 1) {
								sub.erase(k + 1, 1);
								changed = true;
								break;
							}
						} else if (sub[k] == '<') {
							if (k > 0) {
								sub.erase(k - 1, 1);
								changed = true;
								break;
							}
						}
					}
					if (!changed) {
						good = false;
						break;
					}
				}
				if (good) {
					ans = min(ans, n - (j - i + 1));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}