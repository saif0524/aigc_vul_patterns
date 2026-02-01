#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool ok = true;
		int ind = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] < i) {
				ind = i;
				break;
			}
		}
		for(int i = ind + 1; i < n; i++) {
			if(a[i] < n - 1 - i) {
				ok = false;
				break;
			}
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}