#include <bits/stdc++.h>
using namespace std;

long long T, n;
long long a[200005], b[200005];
long long ans[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	long long sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
	}

	for(int i = 0; i < n; i++) {
		if(i == 0) {
			long long now = 0;
			for(long long j = 0; j < T; j++) {
				if(now < b[i]) {
					ans[i]++;
					now += sum;
				} else {
					now -= b[i];
				}
			}
		} else {
			long long now = b[i-1];
			for(long long j = 0; j < T; j++) {
				if(now < b[i]) {
					ans[i]++;
					now += sum;
				} else {
					now -= b[i];
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}