#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

const int mxN=2e5;
int n, a[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	ll cnt=0;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			int or_=a[i]|a[j];
			bool ok=1;
			for(int k=i; k<=j; ++k)
				if((or_&a[k])!=or_)
					ok=0;
			if(ok)
				++cnt;
		}
	}
	cout << cnt;
	return 0;
}