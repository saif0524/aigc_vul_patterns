#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define N 5205

bool check(int n, int x, vector<vector<int>>& mat) {
	for(int i = 0; i < n; i += x) {
		for(int j = 0; j < n; j += x) {
			int val = mat[i][j];
			for(int k = i; k < i + x; k++) {
				for(int l = j; l < j + x; l++) {
					if(mat[k][l] != val) return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		for(int j = 0; j < n / 4; j++) {
			int val = (s[j] >= '0' && s[j] <= '9') ? s[j] - '0' : s[j] - 'A' + 10;
			for(int k = 0; k < 4; k++) {
				mat[i][j * 4 + k] = (val >> (3 - k)) & 1;
			}
		}
	}
	for(int x = n / 2; x > 0; x--) {
		if(n % x == 0 && check(n, x, mat)) {
			cout << x << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
	return 0;
}