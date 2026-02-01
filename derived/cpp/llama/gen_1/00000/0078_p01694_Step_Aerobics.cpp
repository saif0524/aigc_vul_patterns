#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<string> f(n);
		for (int i = 0; i < n; i++) cin >> f[i];

		int lu = 0, ru = 0, ld = 0, rd = 0, count = 0;
		for (int i = 0; i < n; i++) {
			if (f[i] == "lu") lu = 1;
			else if (f[i] == "ru") ru = 1;
			else if (f[i] == "ld") ld = 1;
			else if (f[i] == "rd") rd = 1;

			if (lu && ru && (!ld && !rd)) {
				count++;
				lu = ru = 0;
			}
			else if (ld && rd && (!lu && !ru)) {
				count++;
				ld = rd = 0;
			}
		}

		cout << count << endl;
	}

	return 0;
}